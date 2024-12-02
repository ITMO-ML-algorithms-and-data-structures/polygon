#include "introsort.h"
#include <vector>
#include <algorithm>
#include <cmath>

// Сортировка кучей
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Корень
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr, int start, int end) {
    int n = end - start + 1;

    // Построение кучи
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i + start);
    }

    // Извлечение элементов
    for (int i = end; i >= start; i--) {
        std::swap(arr[start], arr[i]);
        heapify(arr, i - start, start);
    }
}

// Сортировка вставками
static void insertionSort(std::vector<int>& arr, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Быстрая сортировка
void quickSort(std::vector<int>& arr, int start, int end, int depthLimit) {
    if (start >= end) {
        return;
    }

    if (depthLimit == 0) {
        heapSort(arr, start, end);
        return;
    }

    int pivot = arr[start + (end - start) / 2];
    int i = start, j = end;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (start < j) {
        quickSort(arr, start, j, depthLimit - 1);
    }
    if (i < end) {
        quickSort(arr, i, end, depthLimit - 1);
    }
}

// Introsort
std::vector<int> introSort(std::vector<int> arr) {
    int depthLimit = 2 * log(arr.size());
    quickSort(arr, 0, arr.size() - 1, depthLimit);
    insertionSort(arr, 0, arr.size() - 1); // Упорядочивание оставшихся элементов
    return arr;
}

