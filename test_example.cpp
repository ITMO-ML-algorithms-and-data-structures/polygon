#include <gtest/gtest.h>
#include "sort_algorithms.h"  // Подключаем заголовочный файл с объявлениями функций

// Тест для countingSort
TEST(CountingSortTest, HandlesReverseNumbers) {
    std::vector<int> arr = {9, 6, 5, 5, 2, 1};
    std::vector<int> sorted_arr;
    
    countingSort(arr, sorted_arr);
    
    std::vector<int> expected = {1, 2, 5, 5, 6, 9};
    EXPECT_EQ(sorted_arr, expected);
}

TEST(CountingSortTest, HandlesEmptyArray) {
    std::vector<int> arr;
    std::vector<int> sorted_arr;
    
    countingSort(arr, sorted_arr);
    
    std::vector<int> expected = {};
    EXPECT_EQ(sorted_arr, expected);
}
TEST(CountingSortTest, HandlesMixedNumbers) {
    std::vector<int> arr = {-5, 2, -9, 0, 5, -6};
    std::vector<int> sorted_arr;

    countingSort(arr, sorted_arr);

    std::vector<int> expected = {-9, -6, -5, 0, 2, 5};
    EXPECT_EQ(sorted_arr, expected);
}


// Тест для quicksort
TEST(QuickSortTest, HandlesReverseNumbers) {
    std::vector<int> arr = {9, 6, 5, 5, 2, 1};
    
    quicksort(arr, 0, arr.size() - 1);
    
    std::vector<int> expected = {1, 2, 5, 5, 6, 9};
    EXPECT_EQ(arr, expected);
}

TEST(QuickSortTest, HandlesEmptyArray) {
    std::vector<int> arr;
    
    quicksort(arr, 0, arr.size() - 1);
    
    std::vector<int> expected = {};
    EXPECT_EQ(arr, expected);
}
TEST(QuickSortTest, HandlesMixedNumbers) {
    std::vector<int> arr = {-5, 2, -9, 0, 5, -6};

    quicksort(arr, 0, arr.size() - 1);

    std::vector<int> expected = {-9, -6, -5, 0, 2, 5};
    EXPECT_EQ(arr, expected);
}

// Тест для CoctailSort
TEST(CoctailSortTest, HandlesReverseNumbers) {
    std::vector<int> arr = {9, 6, 5, 5, 2, 1};
    
    CoctailSort(arr);
    
    std::vector<int> expected = {1, 2, 5, 5, 6, 9};
    EXPECT_EQ(arr, expected);
}

TEST(CoctailSortTest, HandlesEmptyArray) {
    std::vector<int> arr;
    
    CoctailSort(arr);
    
    std::vector<int> expected = {};
    EXPECT_EQ(arr, expected);
}
TEST(CoctailSortTest, HandlesMixedNumbers) {
    std::vector<int> arr = {-5, 2, -9, 0, 5, -6};

    CoctailSort(arr);

    std::vector<int> expected = {-9, -6, -5, 0, 2, 5};
    EXPECT_EQ(arr, expected);
}
