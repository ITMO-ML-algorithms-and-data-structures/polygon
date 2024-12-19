import subprocess
from concurrent.futures import ThreadPoolExecutor, as_completed
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from tqdm import tqdm

"""
тут немного сгенерированного кода, спасибо codestral, но к лабе это не относится xd 
"""

PATH2ELF = "polygon/src/lab5speedtester"

ALGS = [
    "bublesort",
    "exchangesort",
    "lazysort",
    "shakersort",
    "gravitysort",
    "radixsort",
    "quicksort",
]


def call_sort(alg: str, n: int) -> float:
    try:
        return float(
            subprocess.check_output([PATH2ELF, "-t", alg, "-n", str(n)])
            .decode()
            .strip()
        )
    except subprocess.CalledProcessError as e:
        print(f"Error while executing {alg} with n={n}: {e}")
        return None


def benchmark(algs, sizes, repetitions=50):
    results = {algo: [] for algo in algs}

    def task(algo, size):
        times = []
        for _ in range(repetitions):
            exec_time = call_sort(algo, size)
            if exec_time is not None:
                times.append(exec_time)
        return algo, size, np.mean(times)

    with ThreadPoolExecutor(max_workers=4) as executor:
        futures = [
            executor.submit(task, algo, size)
            for algo in algs
            for size in sizes
        ]
        for future in tqdm(as_completed(futures), total=len(futures), desc="Benchmarking"):
            algo, size, mean_time = future.result()
            results[algo].append(mean_time)

    return results


def graph(results, sizes):
    plt.figure(figsize=(10, 6))
    for algo, times in results.items():
        plt.plot(sizes, times, label=algo)
    plt.xlabel("Размер массива")
    plt.ylabel("Время выполнения (с)")
    plt.title("Сравнение времени работы алгоритмов сортировки")
    plt.legend()
    plt.grid(True)
    plt.savefig("graph.jpg")


def boxplot(algs, size, repetitions=50):
    results = {algo: [] for algo in algs}

    def task(algo):
        times = []
        for _ in range(repetitions):
            exec_time = call_sort(algo, size)
            if exec_time is not None:
                times.append(exec_time)
        return algo, times

    with ThreadPoolExecutor(max_workers=4) as executor:
        futures = [executor.submit(task, algo) for algo in algs]
        for future in tqdm(as_completed(futures), total=len(futures), desc=f"Boxplot {size}"):
            algo, times = future.result()
            results[algo].extend(times)

    plt.figure(figsize=(8, 6))
    sns.boxplot(data=[results[algo] for algo in algs], notch=True)
    plt.xticks(range(len(algs)), algs, rotation=45)
    plt.xlabel("Алгоритмы")
    plt.ylabel("Время выполнения (с)")
    plt.title(f"Box plot для {size} элементов")
    plt.grid(True)
    plt.savefig(f"boxplt_{size}.jpg")


def main():
    sizes = list(range(1000, 10001, 1000))
    repetitions = 50

    print("Сбор данных для линейного графика...")
    results = benchmark(ALGS, sizes, repetitions)
    graph(results, sizes)

    print("Сбор данных для box plot (1e4 элементов)...")
    boxplot(ALGS, size=10000, repetitions=repetitions)

    print("Сбор данных для box plot (1e5 элементов)...")
    boxplot(ALGS, size=100000, repetitions=repetitions)


if __name__ == "__main__":
    main()