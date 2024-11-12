#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

vector <int> heap;

void sieve_up(int idx) { // выстраиваем элементы массива в виде сортирующего дерева
    while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void sieve_down() { // перестраиваем дерево
    int idx = 0;
    while (2 * idx + 1 < heap.size()) {
        int minc = 2 * idx + 1;
        if (2 * idx + 2 < heap.size() && heap[2 * idx + 2] > heap[2 * idx + 1])
            minc++;
        if (heap[idx] < heap[minc]) {
            swap(heap[idx], heap[minc]);
            idx = minc;
        } else {
            break;
        }
    }
}

vector<int> HeapSort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
         heap.push_back(arr[i]);
         sieve_up((int)heap.size() - 1);
    }

    vector<int> res;
    for (int i = 0; i < arr.size(); i++) {
        res.push_back(heap.front()); // вытаскиваем наибольший элемент из корня
        swap(heap[0], heap.back());
        heap.pop_back();
        sieve_down();
    }
    reverse(res.begin(), res.end());
    return res;
}

TEST(SortTest, Test0) {
    vector<int> in({1, 2, 3, 4});
    vector<int> res = HeapSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test1) {
    vector<int> in({1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9});
    vector<int> res = HeapSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test2) {
    vector<int> in({5, 4, 3, 2, 1});
    vector<int> res = HeapSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test3) {
    vector<int> in({3, 3, -2, 1, 4, 5, -5, 1, 3});
    vector<int> res = HeapSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test4) {
    vector<int> in({});
    vector<int> res = HeapSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test5) {
    vector<int> in({100000, -323443, 43, 2312, 435, -657, 3794874, 3803, 21, 21, 32, 0, -5});
    vector<int> res = HeapSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test6) {
    vector<int> in({8, 7, 6, 5, 4, 3, 2, 1});
    vector<int> res = HeapSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
