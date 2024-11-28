#include <iostream>
#include "heap_sort.h"

// Функция для "просеивания" элемента в куче
void heapify(int arr[], int n, int i) {
    int largest = i;  // Инициализируем корень как наибольший
    int left = 2 * i + 1;  // Левый элемент
    int right = 2 * i + 2;  // Правый элемент

    // Если левый элемент больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый элемент больше
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если наибольший элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Рекурсивно "просеиваем" затронутый поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция для сортировки
void heapsort(int arr[], int n) {
    // Строим кучу (перестроение массива в кучу)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 1; i--) {
        // Перемещаем текущий корень (максимум) в конец массива
        std::swap(arr[0], arr[i]);

        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

