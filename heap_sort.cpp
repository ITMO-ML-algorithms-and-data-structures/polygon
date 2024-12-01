#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;
using namespace chrono;

// Функция для обмена двух элементов
void swap(int &a, int &b) { // временная сложность - O(1), пространственная - O(1)
    int temp = a;
    a = b;
    b = temp;
}

// Функция для восстановления свойства кучи
void heapify(vector<int> &arr, int n, int i) { // в среднем случае временная сложность - O(logn), пространственная - O(logn)
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n and arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n and arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Основная функция для сортировки массива с использованием Heap Sort
void heapSort(vector<int> &arr) { // в среднем случае временная сложность - O(nlogn), пространственная - O(logn)
    int n = arr.size();
    // Строим кучу
    for (int i = n / 2 - 1; i >= 0; i--) { // в среднем случае временная сложность - O(nlogn), пространственная - O(logn)
        heapify(arr, n, i);
    }
    // Извлекаем элементы из кучи по одному
    for (int i = n - 1; i > 0; i--) { // в среднем случае временная сложность - O(nlogn), пространственная - O(logn)
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Функция для вывода массива
void printArray(vector<int> arr) { // временная сложность - O(n), пространственная - O(1)
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    // Лучший случай
    vector<int> bestCase = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Худший случай
    vector<int> worstCase = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Средний случай
    vector<int> averageCase = {5, 3, 8, 6, 2, 7, 4, 10, 1, 9};

    // Тестирование на лучшем случае
    cout << "Best Case: ";
    printArray(bestCase);

    auto start = high_resolution_clock::now();
    heapSort(bestCase);
    auto end = high_resolution_clock::now();

    cout << "Sorted Best Case: ";
    printArray(bestCase);

    auto durationBest = duration_cast<microseconds>(end - start).count();

    // Тестирование на худшем случае
    cout << "Worst Case: ";
    printArray(worstCase);

    start = high_resolution_clock::now();
    heapSort(worstCase);
    end = high_resolution_clock::now();

    cout << "Sorted Worst Case: ";
    printArray(worstCase);

    auto durationWorst = duration_cast<microseconds>(end - start).count();

    // Тестирование на среднем случае
    cout << "Average Case: ";
    printArray(averageCase);

    start = high_resolution_clock::now();
    heapSort(averageCase);
    end = high_resolution_clock::now();

    cout << "Sorted Average Case: ";
    printArray(averageCase);

    auto durationAverage = duration_cast<microseconds>(end - start).count();

    // Вывод результатов времени выполнения
    cout << fixed << setprecision(3); // Устанавливаем точность вывода до трех знаков после запятой
    cout << "Time taken for Best Case: " << durationBest / 1000.0 << " ms" << endl;
    cout << "Time taken for Worst Case: " << durationWorst / 1000.0 << " ms" << endl;
    cout << "Time taken for Average Case: " << durationAverage / 1000.0 << " ms" << endl;


    return 0;
}
