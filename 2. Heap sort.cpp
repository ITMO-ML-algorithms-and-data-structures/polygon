#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include  <cassert>

using namespace std;
using namespace std::chrono; 

// Функция для построения кучи
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Инициализация наибольшего элемента как корня
    int left = 2 * i + 1; // Левый потомок
    int right = 2 * i + 2; // Правый потомок

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый потомок больше, чем наибольший элемент на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не является корнем
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Рекурсивно вызываем heapify для поддерева, в котором был изменен корень
        heapify(arr, n, largest);
    }
}

// Функция сортировки кучей
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Построение кучи (перемещение наибольших элементов в конец массива)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}





// Функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Функция юнит-тестов
void testHeapSort() {
    setlocale(LC_ALL, "RU");
    // Набор тестовых массивов
    vector<pair<string, vector<int>>> testCases = {
        {"Пустой массив", {}},
        {"Один элемент", {42}},
        {"Уже отсортированный массив", {1, 2, 3, 4, 5}},
        {"Обратно отсортированный массив", {5, 4, 3, 2, 1}},
        {"Случайный массив", {3, 1, 4, 1, 5, 9, 2, 6, 5}},
        {"Массив с повторяющимися элементами", {10, 7, 7, 3, 2, 2, 5, 7}}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Тест " << i + 1 << ": " << testCases[i].first << endl;

        vector<int> arr = testCases[i].second;
        cout << "Исходный массив: ";
        printArray(arr);

        auto start = high_resolution_clock::now();
        heapSort(arr);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        cout << "Отсортированный массив: ";
        printArray(arr);
        cout << "Время выполнения: " << duration.count() << " микросекунд" << endl;

        // Проверка корректности сортировки
        assert(is_sorted(arr.begin(), arr.end()));
        cout << "Тест успешно пройден!" << endl << endl;
    }
}

int main() {
    // Вызов юнит-тестов
    testHeapSort();
    return 0;
}




//память: О(1) 
//время: O(n log n) - извлечение элементов из кучи 