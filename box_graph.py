import matplotlib.pyplot as plt

with open("bucket_1e4.txt", mode='r') as file:
    a = file.readline().strip().split()
    bucket4 = []
    for i in a:
        bucket4.append(float(i))
with open("bucket_1e5.txt", mode='r') as file:
    a = file.readline().strip().split()
    bucket5 = []
    for i in a:
        bucket5.append(float(i))
with open("merge_1e4.txt", mode='r') as file:
    a = file.readline().strip().split()
    merge4 = []
    for i in a:
        merge4.append(float(i))
with open("merge_1e5.txt", mode='r') as file:
    a = file.readline().strip().split()
    merge5 = []
    for i in a:
        merge5.append(float(i))
with open("cocktail_1e4.txt", mode='r') as file:
    a = file.readline().strip().split()
    cocktail4 = []
    for i in a:
        cocktail4.append(float(i))
with open("cocktail_1e5.txt", mode='r') as file:
    a = file.readline().strip().split()
    cocktail5 = []
    for i in a:
        cocktail5.append(float(i))

    plt.figure(figsize=(8, 6))
    plt.boxplot(
        [cocktail5, merge5, bucket5],
        labels=['CocktailSort', 'MergeSort', 'BucketSort'],
        patch_artist=True,
        boxprops=dict(facecolor='green', color='blue'),
        medianprops=dict(color='red', linewidth=2),
        whiskerprops=dict(color='blue'),
        capprops=dict(color='blue')
    )

    # Настройка графика
    plt.title('Диаграмма времени выполнения', fontsize=16)
    plt.ylabel('Время выполнения', fontsize=14)
    plt.grid(axis='y', linestyle='--', linewidth=0.5)

    # Показ графика
    plt.tight_layout()
    plt.show()
