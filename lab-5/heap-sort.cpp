#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {

    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {

        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);

    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {

        swap(arr[0], arr[i]);
        heapify(arr, i, 0);

    }
}


int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++){

        cin >> arr[i];

    }

    heapSort(arr);

    for (int i = 0; i < n; i++){

        cout << arr[i] << ' ';

    }

    cout << '\n';

    return 0;
}

#include <gtest/gtest.h>

// Лучший случай: массив уже отсортирован
TEST(HeapSortTest, BestCase) {

    vector<int> input = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 4, 5};
    
    heapSort(input);

    EXPECT_EQ(input, expected);
}

// Средний случай: массив с произвольным порядком элементов
TEST(HeapSortTest, AverageCase) {

    vector<int> input = {5, 1, 4, 2, 3};
    vector<int> expected = {1, 2, 3, 4, 5};
    
    heapSort(input);

    EXPECT_EQ(input, expected);
}

// Худший случай: массив отсортирован в обратном порядке
TEST(HeapSortTest, WorstCase) {

    vector<int> input = {5, 4, 3, 2, 1};
    vector<int> expected = {1, 2, 3, 4, 5};
    
    heapSort(input);

    EXPECT_EQ(input, expected);
}

// Дополнительный случай: массив с повторяющимися элементами
TEST(HeapSortTest, Duplicates) {

    vector<int> input = {4, 2, 2, 5, 1, 3, 3};
    vector<int> expected = {1, 2, 2, 3, 3, 4, 5};
    
    heapSort(input);

    EXPECT_EQ(input, expected);
}

// Пустой массив
TEST(HeapSortTest, EmptyArray) {
    
    vector<int> input = {};
    vector<int> expected = {};
    
    heapSort(input);

    EXPECT_EQ(input, expected);
}

// Массив из одного элемента
TEST(HeapSortTest, SingleElement) {
    
    vector<int> input = {42};
    vector<int> expected = {42};
    
    heapSort(input);

    EXPECT_EQ(input, expected);
}
