#include <vector>
#include <cassert>
#include <iostream>

#include "algorithms.h"
using namespace std;

// Алгоритм гребенчатой сортировки
void combSort(vector<int>& arr) {
    int n = arr.size();
    int gap = n;
    float shrink = 1.3;
    bool isSorted = false;

    while (!isSorted) {
        gap = static_cast<int>(static_cast<float>(gap) / shrink);
        if (gap <= 1) {
            gap = 1;
            isSorted = true;
        }

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                isSorted = false;
            }
        }
    }
}

void combSortTests() {
    // Test 1: Пустой массив
    vector<int> test1 = {};
    combSort(test1);
    assert(isSorted(test1) && "Test 1 Failed!");

    // Test 2: Массив с одним элементом
    vector<int> test2 = {42};
    combSort(test2);
    assert(isSorted(test2) && "Test 2 Failed!");

    // Test 3: Отсортированный массив
    vector<int> test3 = {1, 2, 3, 4, 5};
    combSort(test3);
    assert(isSorted(test3) && "Test 3 Failed!");

    // Test 4: Массив, отсортированный в обратном порядке
    vector<int> test4 = {5, 4, 3, 2, 1};
    combSort(test4);
    assert(isSorted(test4) && "Test 4 Failed!");

    // Test 5: Массив с дублирующимися числами
    vector<int> test5 = {3, 3, 3, 3, 3};
    combSort(test5);
    assert(isSorted(test5) && "Test 5 Failed!");

    // Test 6: Массив с отрицательными числами
    vector<int> test6 = {-3, -1, -4, -1, -5, -9, -2, -6, -5, -3, -5};
    combSort(test6);
    assert(isSorted(test6) && "Test 6 Failed!");

    // Лучший случай: массив уже отсортирован
    vector<int> bestCase = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    combSort(bestCase);
    assert(isSorted(bestCase) && "Best case test failed!");

    // Средний случай: массив со случайными элементами
    vector<int> averageCase = {10, 7, 2, 1, 6, 3, 8, 5, 4, 9};
    combSort(averageCase);
    assert(isSorted(averageCase) && "Average case test failed!");

    // Худший случай: массив отсортирован в обратном порядке
    vector<int> worstCase = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    combSort(worstCase);
    assert(isSorted(worstCase) && "Worst case test failed!");

    cout << "All tests for comb sort passed!" << endl;
}
