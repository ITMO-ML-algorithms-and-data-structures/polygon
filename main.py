import numpy as np

# Создаем пустой список для данных
data = []

# Генерация данных
for i in range(1, 1001):  # 1000 строк
    row = np.random.randint(0, 10000, i * 1000)  # генерируем i * 1000 случайных чисел
    data.append(row)

# Преобразуем список в одномерный массив
data = np.concatenate(data)

# Сохраняем данные в бинарном формате
data.tofile('random_numbers.bin')

print("Бинарный файл успешно создан!")

