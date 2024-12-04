#include <iostream>
#include <cassert>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

// Обмен двух элементов
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Сортировки вставками
void InsertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Разделения массива и возврата точки разделения
int Partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Нахождения медианы из трех значений
int MedianOfThree(int a, int b, int c) {
    return max(min(a, b), min(max(a, b), c));
}

// Интросортировка
void IntrosortUtil(int arr[], int left, int right, int depthLimit) {
    if (right - left < 16) {
        InsertionSort(arr, left, right);
        return;
    }

    if (depthLimit == 0) {
        make_heap(arr + left, arr + right + 1);
        sort_heap(arr + left, arr + right + 1);
        return;
    }

    int pivotIndex = MedianOfThree(arr[left], arr[(left + right) / 2], arr[right]);
    swap(arr[pivotIndex], arr[right]);

    int partitionPoint = Partition(arr, left, right);
    IntrosortUtil(arr, left, partitionPoint - 1, depthLimit - 1);
    IntrosortUtil(arr, partitionPoint + 1, right, depthLimit - 1);
}

// Реализация интросортировки
void Introsort(int arr[], int n) {
    int depthLimit = 2 * log(n);
    IntrosortUtil(arr, 0, n - 1, depthLimit);
}

bool arraysEqual(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void test_introsort() {
    // Тест 1: Пустой массив
    int arr1[] = {};
    Introsort(arr1, 0);
    int expected1[] = {};
    assert(arraysEqual(arr1, expected1, 0));

    // Тест 2: Массив с одним элементом
    int arr2[] = {42};
    Introsort(arr2, 1);
    int expected2[] = {42};
    assert(arraysEqual(arr2, expected2, 1));

    // Тест 3: Массив с дублирующимися элементами
    int arr3[] = {5, 3, 3, 2, 5, 1};
    Introsort(arr3, 6);
    int expected3[] = {1, 2, 3, 3, 5, 5};
    assert(arraysEqual(arr3, expected3, 6));

    // Тест 4: Уже отсортированный массив - лучший случай
    int arr4[] = {1, 2, 3, 4, 5};
    Introsort(arr4, 5);
    int expected4[] = {1, 2, 3, 4, 5};
    assert(arraysEqual(arr4, expected4, 5));

    // Тест 5: Массив в обратном порядке - худший случай
    int arr5[] = {5, 4, 3, 2, 1};
    Introsort(arr5, 5);
    int expected5[] = {1, 2, 3, 4, 5};
    assert(arraysEqual(arr5, expected5, 5));

    // Тест 6: Массив с отрицательными числами
    int arr6[] = {-1, -3, -2, -4};
    Introsort(arr6, 4);
    int expected6[] = {-4, -3, -2, -1};
    assert(arraysEqual(arr6, expected6, 4));

    cout << "Tests passed" << endl;
}

int main() {
    // Пример использования функции - средний случай
    int arr[] = { 23, 10, 20, 11, 12, 6, 7, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Introsort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Тесты
    test_introsort();


    // Подсчет времени работы в зависимости от числа элементов
    vector<int> sizes;
    vector<double> times;

    for (int n = 100000; n <= 1000000; n += 100000) {
        sizes.push_back(n);
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 10000;
        }

        auto start = chrono::high_resolution_clock::now();
        Introsort(arr.data(), n);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        times.push_back(duration.count());
    }

    // Сохранение данных для графика
    ofstream outFile("introsort_times.txt");
    for (size_t i = 0; i < sizes.size(); ++i) {
        outFile << sizes[i] << " " << times[i] << endl;
    }
    outFile.close();


    // Boxplot
    const int num_runs = 50;

    // Для массива размером 10^4
    ofstream outFile10000("3 timing_10000.txt");
    for (int run = 0; run < num_runs; run++) {
        vector<int> arr(10000);
        for (int i = 0; i < 10000; ++i) {
            arr[i] = rand() % 10000;
        }

        auto start = chrono::high_resolution_clock::now();
        Introsort(arr.data(), arr.size());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        outFile10000 << duration.count() << endl;
    }
    outFile10000.close();

    // Для массива размером 10^5
    ofstream outFile100000("3 timing_100000.txt");
    for (int run = 0; run < num_runs; run++) {
        vector<int> arr(100000);
        for (int i = 0; i < 100000; ++i) {
            arr[i] = rand() % 100000;
        }

        auto start = chrono::high_resolution_clock::now();
        Introsort(arr.data(), arr.size());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        outFile100000 << duration.count() << endl;
    }
    outFile100000.close();
    return 0;
}

