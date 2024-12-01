#include <gtest/gtest.h>
#include "comb_sort.h"
#include "timsort.h"
#include "introsort.h"

// Вспомогательная функция для проверки сортировки
template <typename SortFunction>
void TestSort(SortFunction sortFunction, const std::vector<int>& input, const std::vector<int>& expected) {
    EXPECT_EQ(sortFunction(input.size(), input), expected);
}

// Тесты для Comb Sort
TEST(CombSortTest, BestCase) {
std::vector<int> input = {1, 2, 3, 4, 5};
std::vector<int> expected = {1, 2, 3, 4, 5};
EXPECT_EQ(combSort(input), expected);
}

TEST(CombSortTest, AverageCase) {
std::vector<int> input = {3, 1, 4, 2, 5};
std::vector<int> expected = {1, 2, 3, 4, 5};
EXPECT_EQ(combSort(input), expected);
}

TEST(CombSortTest, WorstCase) {
std::vector<int> input = {5, 4, 3, 2, 1};
std::vector<int> expected = {1, 2, 3, 4, 5};
EXPECT_EQ(combSort(input), expected);
}

// Тесты для Timsort
TEST(TimSortTest, BestCase) {
std::vector<int> input = {1, 2, 3, 4, 5};
std::vector<int> expected = {1, 2, 3, 4, 5};
EXPECT_EQ(timSort(input), expected);
}

TEST(TimSortTest, AverageCase) {
std::vector<int> input = {3, 1, 4, 2, 5};
std::vector<int> expected = {1, 2, 3, 4, 5};
EXPECT_EQ(timSort(input), expected);
}

TEST(TimSortTest, WorstCase) {
std::vector<int> input = {5, 4, 3, 2, 1};
std::vector<int> expected = {1, 2, 3, 4, 5};
EXPECT_EQ(timSort(input), expected);
}

// Тесты для Introsort
TEST(IntroSortTest, BestCase) {
std::vector<int> input = {1, 2, 3, 4, 5};
std::vector<int> expected = {1, 2, 3, 4, 5};
EXPECT_EQ(introSort(input), expected);
}

TEST(IntroSortTest, AverageCase) {
std::vector<int> input = {3, 1, 4, 2, 5};
std::vector<int> expected = {1, 2, 3, 4, 5};
EXPECT_EQ(introSort(input), expected);
}

TEST(IntroSortTest, WorstCase) {
std::vector<int> input = {5, 4, 3, 2, 1};
std::vector<int> expected = {1, 2, 3, 4, 5};
EXPECT_EQ(introSort(input), expected);
}

