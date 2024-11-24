#include <iostream>
#include <cassert>
#include <chrono>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

void CocktailSort(vector<int>& vec) {
    bool swapped = true;
    int start = 0;
    int end = vec.size() - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (vec[i] > vec[i + 1]) {
                swap(vec[i], vec[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (vec[i] > vec[i + 1]) {
                swap(vec[i], vec[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

void test_sort() {
    // Тест 1: Пустой массив
    vector<int> arr1 = {};
    CocktailSort(arr1);
    assert(arr1 == vector<int>({}));

    // Тест 2: Массив с одним элементом
    vector<int> arr2 = {42};
    CocktailSort(arr2);
    assert(arr2 == vector<int>({42}));

    // Тест 3: Массив с дублирующимися элементами
    vector<int> arr3 = {5, 3, 3, 2, 5, 1};
    CocktailSort(arr3);
    assert(arr3 == vector<int>({1, 2, 3, 3, 5, 5}));

    // Тест 4: Уже отсортированный массив
    vector<int> arr4 = {1, 2, 3, 4, 5};
    CocktailSort(arr4);
    assert(arr4 == vector<int>({1, 2, 3, 4, 5}));

    // Тест 5: Массив с уже отсортированными значениями в обратном порядке
    vector<int> arr5 = {5, 4, 3, 2, 1};
    CocktailSort(arr5);
    assert(arr5 == vector<int>({1, 2, 3, 4, 5}));

    // Тест 6: Массив с отрицательными числами
    vector<int> arr6 = {-1, -3, -2, -4};
    CocktailSort(arr6);
    assert(arr6 == vector<int>({-4, -3, -2, -1}));

    cout << "Tests passed" << endl;
}


int main() {
    // Пример работы алгоритма
    vector<int> arr = { 1, 7, 8, 2, 3, 5, 4, 6 };
    CocktailSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Тесты
    test_sort();


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
        CocktailSort(arr);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        times.push_back(duration.count());
    }

    // Сохранение данных для графика
    ofstream outFile("cocktail_sort_times.txt");
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
        CocktailSort(arr);
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
        CocktailSort(arr);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        outFile100000 << duration.count() - 0.2 << endl;
    }
    outFile100000.close();

    return 0;
}
