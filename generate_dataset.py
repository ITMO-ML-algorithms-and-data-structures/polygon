"""Генератор входных датасетов для лабораторной работы №2
Вывод справки
python generate_dataset.py --help

Генерация датасета с разделителем запятая и пробелами:
python generate_dataset.py --mode text --num-rows 1000 --delimiter ',' --enter 1 --output-file dataset.csv

Генерация числового датасета с разделителем табуляция (\t):
python generate_dataset.py --mode numeric --min-value 1 --max-value 100 --num-rows 500 --delimiter '\t' --output-file numbers.tsv

Генерация текстового датасета с разделителем точка с запятой (;):
python generate_dataset.py --mode text --num-rows 10000 --delimiter ';' --output-file dataset.txt

Генерация пары строк одинаковой длинны с разделителем точка с запятой (\t):
python generate_dataset.py --mode text-pair --num-rows 1000 --max-length 50 --delimiter '\t' --output-file pairs.csv

"""
import argparse
import random
import string

NULL_PROBA = 0.1
WRITE_ROW_LIMIT = 1e4
MAX_NUM_ROWS = int(1e9)  # Максимальное значение для num_rows


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


def generate_random_string_pairs(length, enter, char_set):
    """Генератор пары случайных строк одинаковой длины."""
    string1 = generate_random_string(length, enter, char_set)
    string2 = generate_random_string(length, enter, char_set)
    return (string1, string2)


def generate_random_numbers(size, min_val, max_val, include_null=False, null_probability=NULL_PROBA):
    """Генератор числовых данных с возможностью добавления пропусков (null)."""
    for _ in range(size):
        if include_null and random.random() < null_probability:
            yield None
        else:
            yield random.randint(min_val, max_val)


def generate_text_dataset(num_rows, max_length, enter, char_set):
    """Генератор текстового датасета."""
    for _ in range(num_rows):
        yield generate_random_string(random.randint(1, max_length), enter, char_set)


def generate_text_pair_dataset(num_rows, length, enter, char_set):
    """Генератор датасета пар строк одинаковой длины."""
    for _ in range(num_rows):
        yield generate_random_string_pairs(length, enter, char_set)


def save_dataset_to_file(filename, data_gen, delimiter, row_limit=WRITE_ROW_LIMIT, is_pair=False):
    """Сохраняет датасет в файл с выбранным разделителем. Если строк больше row_limit, то запись построчная."""
    row_count = 0
    with open(filename, 'w') as f:
        for row in data_gen:
            if is_pair:
                formatted_row = f"{row[0]}{delimiter}{row[1]}"  # Для пар строк
                f.write(f"{formatted_row}\n")
                row_count += 1
                if row_count >= row_limit:
                    f.flush()  # Очищает буфер
            else:
                formatted_row = str(row).replace("None", "")  # Преобразуем None в пустую строку
                f.write(f"{formatted_row}{delimiter}")
                row_count += 1
                if row_count >= row_limit:
                    f.flush()  # Очищает буфер
    print(f"Датасет сохранен в {filename}, всего строк: {row_count}")


def main():
    parser = argparse.ArgumentParser(description="Генератор датасетов.")

    parser.add_argument('--mode', choices=['text', 'numeric', 'text-pair'], required=True,
                        help="Тип генерируемых данных: текстовый, числовой или пара текстов.")
    parser.add_argument('--max-length', type=int, default=100,
                        help="Максимальная длина строки (для текстовых данных).")
    parser.add_argument('--num-rows', type=int, default=int(1e4),
                        help="Количество строк или чисел для генерации (макс. 1e9).")
    parser.add_argument('--charset', choices=['default', 'alphanumeric', 'alphanumeric_ru'], default='default',
                        help="Набор символов для генерации строк.")
    parser.add_argument('--enter', choices=['1', '0'], default='0',
                        help="Наличие пробелов (для векторизатора).")

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

        dataset_gen = generate_text_dataset(args.num_rows, args.max_length, args.enter, char_set)
        save_dataset_to_file(args.output_file, dataset_gen, delimiter)

    elif args.mode == 'text-pair':
        char_set = string.ascii_lowercase  # Набор символов по умолчанию
        if args.charset == 'alphanumeric':
            char_set = string.ascii_letters + string.digits
        elif args.charset == 'alphanumeric_ru':
            char_set = string.ascii_letters + string.digits + 'абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'

        dataset_gen = generate_text_pair_dataset(args.num_rows, args.max_length, args.enter, char_set)
        save_dataset_to_file(args.output_file, dataset_gen, delimiter, is_pair=True)

    elif args.mode == 'numeric':
        dataset_gen = generate_random_numbers(args.num_rows, args.min_value, args.max_value, args.include_null)
        save_dataset_to_file(args.output_file, dataset_gen, delimiter)


if __name__ == "__main__":
    main()
