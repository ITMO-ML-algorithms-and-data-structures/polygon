import csv
import random

# Указываем имя файла для записи
filename = 'random_numbers.csv'

# Открываем файл для записи
with open(filename, mode='w', newline='') as file:
    writer = csv.writer(file)

    # Генерируем строки с случайными числами
    for i in range(1, 1001):  # 1000 строк
        # Генерируем случайные целые числа от 0 до 10000, количество чисел на строке = i * 1000
        row = [random.randint(0, 10000) for _ in range(i * 1000)]
        writer.writerow(row)  # Записываем строку в файл

print(f"Файл '{filename}' успешно создан!")


