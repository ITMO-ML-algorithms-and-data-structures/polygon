#include "Sort.h"

#include <climits>

// CocktailShakerSort (task #1)
// Суть алгоритма: улучшенная версия пузырьковой сортировки, в которой проход идет в обе стороны - 
// сначала слева направо, потом справа налево. Это уменьшает количество необходимых итераций.
// Временная сложность: 
//    - В лучшем случае: O(n) (если массив уже отсортирован).
//    - В среднем и худшем случаях: O(n^2).
// Пространственная сложность: O(1) - алгоритм работает на месте без дополнительной памяти.
void Sort::CocktailShaker(std::vector<int>& data) {
    bool swapped = true;
    int endVector = static_cast<int>(data.size());
    int startVector = 0;
    while (swapped) {
        swapped = false;
        // Проход слева направо
        for (int i = 0; i < endVector - 1; i++) {
            if (data[i] > data[i + 1]) {
                std::swap(data[i], data[i + 1]);
                swapped = true;
            }
        }
        if (swapped == false) break;
        --endVector;
        swapped = false;
        // Проход справа налево
        for (int i = endVector; i > startVector; --i) {
            if (data[i] < data[i - 1]) {
                std::swap(data[i], data[i - 1]);
                swapped = true;
            }
        }
        startVector++;
    }
}

// HeapSort (task #2)
// Суть алгоритма: сортировка на основе двоичной кучи (heap). Построение max-heap и затем извлечение
// максимального элемента в конец массива с последующей перестройкой кучи.
// Временная сложность:
//    - Всегда: O(n log n).
// Пространственная сложность: O(1) - алгоритм работает на месте.
void Sort::Heap(std::vector<int>& data) {
    const int n = static_cast<int>(data.size());
    // Построение max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(data, n, i);
    }
    // Уменьшаем heap, перемещая максимум в конец
    for (int i = n - 1; i > 0; i--) {
        std::swap(data[0], data[i]);
        Heapify(data, i, 0);
    }
}

// BucketSort (task #3)
// Суть алгоритма: распределяет элементы по диапазонам (buckets), затем сортирует каждый bucket
// с помощью более простого алгоритма, например, сортировки вставками.
// Временная сложность:
//    - В лучшем случае: O(n + k), где k - число корзин.
//    - В худшем случае: O(n^2) (если элементы распределяются неравномерно по корзинам).
// Пространственная сложность: O(n + k) - память на массив данных и k корзин.
void Sort::Bucket(std::vector<int>& data, const int numBuckets) {
    if (data.size() <= 1) return;
    const int maxValue = GetMaxValue(data);
    const int minValue = GetMinValue(data);
    std::vector<std::vector<int>> buckets(numBuckets);
    // Распределение элементов по корзинам
    for (const int element : data) {
        const int index = (element - minValue) / (maxValue - minValue + 1) * numBuckets;
        buckets[index].push_back(element);
    }
    // Сортировка каждой корзины
    for (std::vector<int>& bucket : buckets) {
        Insertion(bucket);
    }
    // Объединение корзин в один массив
    data.clear();
    for (int i = 0; i < numBuckets; i++) {
        data.insert(data.end(), buckets[i].begin(), buckets[i].end());
    }
}

// InsertionSort (вспомогательный метод для BucketSort)
// Суть алгоритма: последовательное вставление элементов в правильное место.
// Временная сложность:
//    - В лучшем случае: O(n) (если массив уже отсортирован).
//    - В худшем и среднем случаях: O(n^2).
// Пространственная сложность: O(1) - алгоритм работает на месте.
void Sort::Insertion(std::vector<int>& data) {
    for (int i = 1; i < data.size(); i++) {
        const int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

// Heapify (вспомогательный метод для HeapSort)
// Суть: поддержание свойства max-heap. Если родительский элемент меньше, чем один из потомков, меняем местами и рекурсивно вызываем для потомка.
void Sort::Heapify(std::vector<int>& data, const int currentSize, const int currentNode) {
    int largest = currentNode;
    const int left = 2 * currentNode + 1;
    const int right = 2 * currentNode + 2;
    if (left < currentSize && data[left] > data[largest]) {
        largest = left;
    }
    if (right < currentSize && data[right] > data[largest]) {
        largest = right;
    }
    if (largest != currentNode) {
        std::swap(data[currentNode], data[largest]);
        Heapify(data, currentSize, largest);
    }
}

// GetMaxValue
// Находит максимальное значение в массиве. Временная сложность: O(n).
int Sort::GetMaxValue(const std::vector<int> &data) {
    int max = INT_MIN;
    for (const int value : data) {
        if (value > max) {
            max = value;
        }
    }
    return max;
}

// GetMinValue
// Находит минимальное значение в массиве. Временная сложность: O(n).
int Sort::GetMinValue(const std::vector<int> &data) {
    int min = INT_MAX;
    for (const int value : data) {
        if (value < min) {
            min = value;
        }
    }
    return min;
}
