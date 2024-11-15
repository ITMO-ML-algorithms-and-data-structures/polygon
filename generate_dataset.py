"""
Генератор входных датасетов для лабораторной работы №2

# Вывод справки:
python generate_dataset.py --help

# Генерация текстового датасета с минимальным количеством уникальных строк (разделитель запятая, с пробелами):
python generate_dataset.py --mode text --num-rows 1000 --min-unique 50 --max-length 10 --charset alphanumeric --enter 1 --delimiter ',' --output-file dataset.csv

# Генерация числового датасета с минимальным количеством уникальных чисел (разделитель табуляция):
python generate_dataset.py --mode numeric --num-rows 500 --min-unique 50 --min-value 1 --max-value 100 --delimiter \t --output-file numbers.tsv

# Генерация текстового датасета с минимальным количеством уникальных строк (разделитель точка с запятой):
python generate_dataset.py --mode text --num-rows 10000 --min-unique 100 --max-length 20 --charset default --delimiter ';' --output-file dataset.txt

# Генерация числового датасета с пропусками (null) и минимальным количеством уникальных значений (разделитель новая строка):
python generate_dataset.py --mode numeric --num-rows 2000 --min-unique 500 --min-value 10 --max-value 500 --include-null --delimiter \n --output-file dataset_with_nulls.txt
"""

import argparse
import random
import string

NULL_PROBA = 0.1
WRITE_ROW_LIMIT = 1e4
MAX_NUM_ROWS = int(1e9)

def generate_random_string(length, enter, char_set=string.ascii_lowercase):
    """Генератор случайных строк из заданного набора символов."""
    st = ''.join(random.choices(char_set, k=length))
    if enter == '0':
        return st
    i = random.randint(1, length)
    while i != length:
        st = st[:i] + ' ' + st[i:]
        i = random.randint(i, length)
    return st

def generate_unique_strings(num_unique, max_length, enter, char_set):
    """Генерация заданного количества уникальных строк."""
    unique_strings = set()
    while len(unique_strings) < num_unique:
        unique_strings.add(generate_random_string(random.randint(1, max_length), enter, char_set))
    return list(unique_strings)

def generate_unique_numbers(num_unique, min_val, max_val, include_null=False):
    """Генерация заданного количества уникальных чисел."""
    unique_numbers = set()
    while len(unique_numbers) < num_unique:
        if include_null and random.random() < NULL_PROBA:
            unique_numbers.add(None)
        else:
            unique_numbers.add(random.randint(min_val, max_val))
    return list(unique_numbers)

def generate_text_dataset(num_rows, num_unique, max_length, enter, char_set):
    """Генерация текстового датасета с минимальным количеством уникальных значений."""
    unique_strings = generate_unique_strings(num_unique, max_length, enter, char_set)
    for _ in range(num_rows):
        yield random.choice(unique_strings)

def generate_numeric_dataset(num_rows, num_unique, min_value, max_value, include_null):
    """Генерация числового датасета с минимальным количеством уникальных значений."""
    unique_numbers = generate_unique_numbers(num_unique, min_value, max_value, include_null)
    for _ in range(num_rows):
        yield random.choice(unique_numbers)

def save_dataset_to_file(filename, data_gen, delimiter, row_limit=WRITE_ROW_LIMIT):
    """Сохраняет датасет в файл с выбранным разделителем."""
    row_count = 0
    with open(filename, 'w') as f:
        for row in data_gen:
            formatted_row = str(row).replace("None", "")  # Преобразуем None в пустую строку
            f.write(f"{formatted_row}{delimiter}")
            row_count += 1
            if row_count >= row_limit:
                f.flush()  # Очищает буфер
    print(f"Датасет сохранен в {filename}, всего строк: {row_count}")

def main():
    parser = argparse.ArgumentParser(description="Генератор датасетов.")
    
    parser.add_argument('--mode', choices=['text', 'numeric'], required=True, 
                        help="Тип генерируемых данных: текстовый или числовой.")
    parser.add_argument('--max-length', type=int, default=100, 
                        help="Максимальная длина строки (для текстовых данных).")
    parser.add_argument('--num-rows', type=int, default=int(1e4), 
                        help="Количество строк или чисел для генерации (макс. 1e9).")
    parser.add_argument('--charset', choices=['default', 'alphanumeric', 'alphanumeric_ru'], default='default',
                        help="Набор символов для генерации строк.")
    parser.add_argument('--enter', choices=['1', '0'], default='0',
                        help="Наличие пробелов (для векторизатора).")
    parser.add_argument('--min-unique', type=int, default=1, 
                        help="Минимальное количество уникальных значений.")
    
    # Для числовых данных
    parser.add_argument('--min-value', type=int, default=0, help="Минимальное значение для чисел.")
    parser.add_argument('--max-value', type=int, default=100, help="Максимальное значение для чисел.")
    parser.add_argument('--include-null', action='store_true', help="Добавить пропуски (null) в числовые данные.")
    
    # Ввод/вывод файла
    parser.add_argument('--output-file', type=str, default='dataset.txt', help="Файл для сохранения датасета.")
    
    # Разделитель
    parser.add_argument('--delimiter', choices=['\\n', '\\t', ',', ';'], default='\\n',
                        help="Разделитель для записи данных (\\n, \\t, ',', ';').")

    args = parser.parse_args()

    # Ограничение на максимальное количество строк
    if args.num_rows > MAX_NUM_ROWS:
        raise ValueError(f"Максимальное количество строк не может превышать {MAX_NUM_ROWS}")

    if args.min_unique > args.num_rows:
        raise ValueError("Минимальное количество уникальных значений не может превышать количество строк.")

    # Обработка выбранного разделителя
    delimiter_map = {
        '\\n': '\n',
        '\\t': '\t',
        ',': ',',
        ';': ';'
    }
    delimiter = delimiter_map[args.delimiter]

    # Генерация датасета в зависимости от режима
    if args.mode == 'text':
        char_set = string.ascii_lowercase  # Набор символов по умолчанию
        if args.charset == 'alphanumeric':
            char_set = string.ascii_letters + string.digits
        elif args.charset == 'alphanumeric_ru':
            char_set = string.ascii_letters + string.digits + 'абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'

        dataset_gen = generate_text_dataset(args.num_rows, args.min_unique, args.max_length, args.enter, char_set)
    
    elif args.mode == 'numeric':
        dataset_gen = generate_numeric_dataset(args.num_rows, args.min_unique, args.min_value, args.max_value, args.include_null)

    save_dataset_to_file(args.output_file, dataset_gen, delimiter)

if __name__ == "__main__":
    main()