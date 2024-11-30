#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void flip(vector<int>& arr, int k) {
    reverse(arr.begin(), arr.begin() + k);
}

int findMaxIndex(const vector<int>& arr, int n) {

    int maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}

// Реализация Pancake Sort
void pancakeSort(vector<int>& arr) {

    int n = arr.size();

    for (int currSize = n; currSize > 1; --currSize) {

        // Найти индекс максимального элемента в текущем подмассиве
        int maxIndex = findMaxIndex(arr, currSize);

        // Если максимальный элемент не на месте, перемещаем его
        if (maxIndex != currSize - 1) {

            // Переворачиваем, чтобы переместить максимальный элемент в начало
            if (maxIndex != 0) {
                flip(arr, maxIndex + 1);
            }

            // Переворачиваем, чтобы переместить максимальный элемент в конец подмассива
            flip(arr, currSize);
        }
    }
}

int main() {

    
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++){

        cin >> arr[i];

    }

    pancakeSort(arr);

    for (int i = 0; i < n; i++){

        cout << arr[i] << ' ';

    }

    cout << '\n';

    return 0;

}

#include <gtest/gtest.h>

// Лучший случай: массив уже отсортирован
TEST(PancakeSortTest, BestCase) {
    vector<int> input = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 4, 5};
    
    pancakeSort(input);

    EXPECT_EQ(input, expected);
}

// Средний случай: массив с произвольным порядком элементов
TEST(PancakeSortTest, AverageCase) {
    vector<int> input = {5, 1, 4, 2, 3};
    vector<int> expected = {1, 2, 3, 4, 5};
    
    pancakeSort(input);

    EXPECT_EQ(input, expected);
}

// Худший случай: массив отсортирован в обратном порядке
TEST(PancakeSortTest, WorstCase) {
    vector<int> input = {5, 4, 3, 2, 1};
    vector<int> expected = {1, 2, 3, 4, 5};
    
    pancakeSort(input);

    EXPECT_EQ(input, expected);
}

// Дополнительный случай: массив с повторяющимися элементами
TEST(PancakeSortTest, Duplicates) {
    vector<int> input = {4, 2, 2, 5, 1, 3, 3};
    vector<int> expected = {1, 2, 2, 3, 3, 4, 5};
    
    pancakeSort(input);

    EXPECT_EQ(input, expected);
}

// Пустой массив
TEST(PancakeSortTest, EmptyArray) {
    vector<int> input = {};
    vector<int> expected = {};
    
    pancakeSort(input);

    EXPECT_EQ(input, expected);
}

// Массив из одного элемента
TEST(PancakeSortTest, SingleElement) {
    vector<int> input = {42};
    vector<int> expected = {42};
    
    pancakeSort(input);

    EXPECT_EQ(input, expected);
}

