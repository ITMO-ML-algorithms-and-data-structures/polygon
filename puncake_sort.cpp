#include <iostream>
#include <cassert>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;

// Функция для переворота подмассива
void flip(vector<int>& arr, int k) {
    reverse(arr.begin(), arr.begin() + k + 1);
}

// Функция для поиска индекса максимального элемента в подмассиве
int maxIndex(const vector<int>& arr, int n) {
    return max_element(arr.begin(), arr.begin() + n) - arr.begin();
}

// Функция сортировки блинами
void pancakeSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n - 1; i > 0; --i) {
        int maxdex = maxIndex(arr, i + 1);
        if (maxdex != i) {
            flip(arr, maxdex); // Переворачиваем до максимального элемента
            flip(arr, i);      // Переворачиваем до конца массива
        }
    }
}

// Функция для проверки равенства двух массивов
bool arraysEqual(const vector<int>& arr1, const vector<int>& arr2) {
    return arr1 == arr2;
}

void test_pancake_sort() {
    // Тест 1: Пустой массив
    vector<int> arr1 = {};
    pancakeSort(arr1);
    vector<int> expected1= {};
    assert(arraysEqual(arr1, expected1));

    // Тест 2: Массив с одним элементом
    vector<int> arr2 = {42};
    pancakeSort(arr2);
    vector<int> expected2 = {42};
    assert(arraysEqual(arr2, expected2));

    // Тест 3: Массив с дублирующимися элементами
    vector<int> arr3 = {5, 3, 3, 2, 5, 1};
    pancakeSort(arr3);
    vector<int> expected3 = {1, 2, 3, 3, 5, 5};
    assert(arraysEqual(arr3, expected3));

    // Тест 4: Уже отсортированный массив - лучший случай
    vector<int> arr4 = {1, 2, 3, 4, 5};
    pancakeSort(arr4);
    vector<int> expected4 = {1, 2, 3, 4, 5};
    assert(arraysEqual(arr4, expected4));

    // Тест 5: Массив в обратном порядке - худший случай
    vector<int> arr5 = {5, 4, 3, 2, 1};
    pancakeSort(arr5);
    vector<int> expected5 = {1, 2, 3, 4, 5};
    assert(arraysEqual(arr5, expected5));

    // Тест 6: Массив с отрицательными числами
    vector<int> arr6 = {-1, -3, -2, -4};
    pancakeSort(arr6);
    vector<int> expected6 = {-4, -3, -2, -1};
    assert(arraysEqual(arr6, expected6));

    cout << "Tests passed" << endl;
}

int main() {
    // Пример использования функции - средний случай
    vector<int> arr = { 23, 10, 20, 11, 12, 6, 7, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    pancakeSort(arr);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Тесты
    test_pancake_sort();


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
        pancakeSort(arr);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        times.push_back(duration.count());
    }

    // Сохранение данных для графика
    ofstream outFile("pancake_sort_times.txt");
    for (size_t i = 0; i < sizes.size(); ++i) {
        outFile << sizes[i] << " " << times[i] << endl;
    }
    outFile.close();


    // Boxplot
    const int num_runs = 50;

    // Для массива размером 10^4
    ofstream outFile10000("1 timing_10000.txt");
    for (int run = 0; run < num_runs; run++) {
        vector<int> arr(10000);
        for (int i = 0; i < 10000; ++i) {
            arr[i] = rand() % 10000;
        }

        auto start = chrono::high_resolution_clock::now();
        pancakeSort(arr);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        outFile10000 << duration.count() << endl;
    }
    outFile10000.close();

    // Для массива размером 10^5
    ofstream outFile100000("1 timing_100000.txt");
    for (int run = 0; run < num_runs; run++) {
        vector<int> arr(100000);
        for (int i = 0; i < 100000; ++i) {
            arr[i] = rand() % 100000;
        }

        auto start = chrono::high_resolution_clock::now();
        pancakeSort(arr);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        outFile100000 << duration.count() << endl;
    }
    outFile100000.close();
    return 0;
}