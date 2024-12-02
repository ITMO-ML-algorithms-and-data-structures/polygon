#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Функция для выполнения пузырьковой сортировки
void bubbleSort(int arr[], int n) {
    // Внешний цикл: проходим по всем элементам массива
    for (int i = 0; i < n - 1; ++i) {
        // Внутренний цикл: сравниваем соседние элементы и меняем их местами, если они в неправильном порядке
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Меняем местами arr[j] и arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция для обмена элементов (для быстрой сортировки)
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для выбора опорного элемента и разбиения массива (для быстрой сортировки)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); // индекс меньшего элемента

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Рекурсивная функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция для подсчета поразрядной сортировки на основе конкретного разряда (для Radix Sort)
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); 
    int count[10] = {0}; 

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Основная функция поразрядной сортировки
void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

int main() {
    // Пример массива для сортировки
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    vector<int> arr2 = {10, 7, 8, 9, 1, 5};
    vector<int> arr3 = {170, 45, 75, 90, 802, 24, 2, 66};
    
    // Пузырьковая сортировка
    cout << "Original array for Bubble Sort: ";
    printArray(arr1, n1);
    bubbleSort(arr1, n1);
    cout << "Sorted array using Bubble Sort: ";
    printArray(arr1, n1);
    cout << endl;

    // Быстрая сортировка
    cout << "Original array for Quick Sort: ";
    printArray(arr2.data(), arr2.size());
    quickSort(arr2.data(), 0, arr2.size() - 1);
    cout << "Sorted array using Quick Sort: ";
    printArray(arr2.data(), arr2.size());
    cout << endl;

    // Поразрядная сортировка
    cout << "Original array for Radix Sort: ";
    printArray(arr3.data(), arr3.size());
    radixSort(arr3);
    cout << "Sorted array using Radix Sort: ";
    printArray(arr3.data(), arr3.size());
    
    return 0;
}
