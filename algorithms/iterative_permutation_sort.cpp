#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

#include "algorithms.h"
using namespace std;

// Алгоритм Iterative Permutation sort
void iterative_permutation_sort(vector<int>& arr, int k) {
    int n = arr.size();

    // Итеративно выполняем "приближение" массива к отсортированному состоянию
    for (int step = 0; step < k; ++step) {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }

    // Дополнительная сортировка для точного результата
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}


void iterativePermutationSortTests() {
    // Test 1: Пустой массив
    vector<int> test1 = {};
    iterative_permutation_sort(test1, 3);
    assert(isSorted(test1) && "Test 1 Failed!");

    // Test 2: Массив с одним элементом
    vector<int> test2 = {42};
    iterative_permutation_sort(test2, 3);
    assert(isSorted(test2) && "Test 2 Failed!");

    // Test 3: Отсортированный массив
    vector<int> test3 = {1, 2, 3, 4, 5};
    iterative_permutation_sort(test3, 3);
    assert(isSorted(test3) && "Test 3 Failed!");

    // Test 4: Массив, отсортированный в обратном порядке
    vector<int> test4 = {5, 4, 3, 2, 1};
    iterative_permutation_sort(test4, 3);
    assert(isSorted(test4) && "Test 4 Failed!");

    // Test 5: Массив с дублирующимися числами
    vector<int> test5 = {3, 3, 3, 3, 3};
    iterative_permutation_sort(test5, 3);
    assert(isSorted(test5) && "Test 5 Failed!");

    // Test 6: Массив с отрицательными числами
    vector<int> test6 = {-3, -1, -4, -1, -5, -9, -2, -6, -5, -3, -5};
    iterative_permutation_sort(test6, 3);
    assert(isSorted(test6) && "Test 6 Failed!");

    // Лучший случай: Массив уже отсортирован
    vector<int> bestCase = {1, 2, 3, 4, 5};
    iterative_permutation_sort(bestCase, 3);
    assert(isSorted(bestCase) && "Best case test failed!");

    // Средний случай: Случайные элементы
    vector<int> averageCase = {10, 7, 2, 1, 6, 3, 8, 5, 4, 9};
    iterative_permutation_sort(averageCase, 3);
    assert(isSorted(averageCase) && "Average case test failed!");

    // Худший случай: Массив, отсортированный в обратном порядке
    vector<int> worstCase = {5, 4, 3, 2, 1};
    iterative_permutation_sort(worstCase, 3);
    assert(isSorted(worstCase) && "Worst case test failed!");

    // Тест с малым числом k (ограничение длины перестановок)
    vector<int> smallKCase = {4, 3, 2, 1};
    iterative_permutation_sort(smallKCase, 2);
    assert(isSorted(smallKCase) && "Small k test failed!");

    cout << "All tests for iterative permutation sort passed!" << endl;
}
