#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

vector<int> InsertionSort(vector<int> &a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int x = a[i]; // Берем элемент
        int j = i - 1;
        while (x < a[j] && j >= 0) { // Переставляем предыдущие пока не найдем походящее место
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x; // Вставляем элемент
    }
    return a;
}

TEST(SortTest, Test0) {
    vector<int> in({1, 2, 3, 4});
    vector<int> res = InsertionSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test1) {
    vector<int> in({1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9});
    vector<int> res = InsertionSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test2) {
    vector<int> in({5, 4, 3, 2, 1});
    vector<int> res = InsertionSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test3) {
    vector<int> in({3, 3, -2, 1, 4, 5, -5, 1, 3});
    vector<int> res = InsertionSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test4) {
    vector<int> in({});
    vector<int> res = InsertionSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test5) {
    vector<int> in({100000, -323443, 43, 2312, 435, -657, 3794874, 3803, 21, 21, 32, 0, -5});
    vector<int> res = InsertionSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test6) {
    vector<int> in({8, 7, 6, 5, 4, 3, 2, 1});
    vector<int> res = InsertionSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}