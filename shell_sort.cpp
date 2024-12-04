#include <iostream>
#include <cassert>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

bool arraysEqual(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void test_shell_sort() {
    // Тест 1: Пустой массив
    int arr1[] = {};
    shellSort(arr1, 0);
    int expected1[] = {};
    assert(arraysEqual(arr1, expected1, 0));

    // Тест 2: Массив с одним элементом
    int arr2[] = {42};
    shellSort(arr2, 1);
    int expected2[] = {42};
    assert(arraysEqual(arr2, expected2, 1));

    // Тест 3: Массив с дублирующимися элементами
    int arr3[] = {5, 3, 3, 2, 5, 1};
    shellSort(arr3, 6);
    int expected3[] = {1, 2, 3, 3, 5, 5};
    assert(arraysEqual(arr3, expected3, 6));

    // Тест 4: Уже отсортированный массив - лучший случай
    int arr4[] = {1, 2, 3, 4, 5};
    shellSort(arr4, 5);
    int expected4[] = {1, 2, 3, 4, 5};
    assert(arraysEqual(arr4, expected4, 5));

    // Тест 5: Массив в обратном порядке - худший случай
    int arr5[] = {5, 4, 3, 2, 1};
    shellSort(arr5, 5);
    int expected5[] = {1, 2, 3, 4, 5};
    assert(arraysEqual(arr5, expected5, 5));

    // Тест 6: Массив с отрицательными числами
    int arr6[] = {-1, -3, -2, -4};
    shellSort(arr6, 4);
    int expected6[] = {-4, -3, -2, -1};
    assert(arraysEqual(arr6, expected6, 4));

    cout << "Tests passed" << endl;
}

int main() {
    // Пример использования функции - средний случай
    int arr[] = { 23, 10, 20, 11, 12, 6, 7, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Тесты
    test_shell_sort();


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
        shellSort(arr.data(), n);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        times.push_back(duration.count());
    }

    // Сохранение данных для графика
    ofstream outFile("shell_sort_times.txt");
    for (size_t i = 0; i < sizes.size(); ++i) {
        outFile << sizes[i] << " " << times[i] << endl;
    }
    outFile.close();


    // Boxplot
    const int num_runs = 50;

    // Для массива размером 10^4
    ofstream outFile10000("2 timing_10000.txt");
    for (int run = 0; run < num_runs; run++) {
        vector<int> arr(10000);
        for (int i = 0; i < 10000; ++i) {
            arr[i] = rand() % 10000;
        }

        auto start = chrono::high_resolution_clock::now();
        shellSort(arr.data(), arr.size());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        outFile10000 << duration.count() << endl;
    }
    outFile10000.close();

    // Для массива размером 10^5
    ofstream outFile100000("2 timing_100000.txt");
    for (int run = 0; run < num_runs; run++) {
        vector<int> arr(100000);
        for (int i = 0; i < 100000; ++i) {
            arr[i] = rand() % 100000;
        }

        auto start = chrono::high_resolution_clock::now();
        shellSort(arr.data(), arr.size());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        outFile100000 << duration.count() << endl;
    }
    outFile100000.close();
    return 0;
}