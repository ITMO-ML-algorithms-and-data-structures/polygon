//Heap sort (Cоздает максимальную кучу и повторно извлекает максимальный элемент, перенося его в конец массива)
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // наибольший элемент как корень
    int left = 2 * i + 1;  // Левый элемент
    int right = 2 * i + 2; // Правый  элемент

    // Проверяем, является ли левый элемент больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Проверяем, является ли правый элемент больше текущего наибольшего
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если наибольший элемент не корень, выполняем обмен и вызываем heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Построение max-heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);  // Перемещаем корень в конец
        heapify(arr, i, 0);    // Восстанавливаем max-heap
    }
}
