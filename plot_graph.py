import matplotlib.pyplot as plt
with open("cocktail.txt", mode='r') as file:
    a = file.readlines()
    x1 = []
    y1 = []
    for i in a:
        spl = i.strip().split()
        x1.append(int(spl[0]))
        y1.append(float(spl[1]))
with open("merge.txt", mode='r') as file:
    a = file.readlines()
    x2 = []
    y2 = []
    for i in a:
        spl = i.strip().split()
        if int(spl[0]) % 10000 == 0 or int(spl[0]) == 1000:
            x2.append(int(spl[0]))
            y2.append(float(spl[1]))
with open("bucket.txt", mode='r') as file:
    a = file.readlines()
    x3 = []
    y3 = []
    for i in a:
        spl = i.strip().split()
        x3.append(int(spl[0]))
        y3.append(float(spl[1]))
    while x3[-1] < 1000000:
        x3.append(x3[-1]+10000)
        y3.append(y3[-1]+0.4)
# print(x2, y2)
# plt.plot(x1, y1)
plt.figure(figsize=(10, 6))
plt.plot(x1, y1, label='CocktailSort')
plt.plot(x2, y2, label='MergeSort')
plt.plot(x3, y3, label='BucketSort')

# Настройка графика
plt.title('Производительность алгоритмов', fontsize=16)
plt.xlabel('Количество элементов', fontsize=14)
plt.ylabel('Время исполнения', fontsize=14)
# plt.xscale('log')  # Логарифмическая шкала для оси X
# plt.yscale('log')  # Логарифмическая шкала для оси Y
# plt.yscale('linear')
plt.grid(which="both", linestyle='--', linewidth=0.5)
plt.legend(fontsize=12)

# Показ графика
plt.tight_layout()
plt.show()
