#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "sorting.h"

#define ll long long
using namespace std;


void shaker_sort(vector <ll> &ass);
void merge(vector<ll> &ass, int l, int r);
void merge_sort(vector <ll> &ass, int left, int right);
void heap(vector <ll> &ass, int n, int jj);
void heap_sort(vector <ll> &ass);

// Test for Shaker Sort
TEST(ShakerSortTest, EmptyArray) {
    vector<ll> ass = {};
    shaker_sort(ass);
    ASSERT_TRUE(ass.empty());
}

TEST(ShakerSortTest, SingleElement) {
    vector<ll> ass = {3};
    shaker_sort(ass);
    ASSERT_EQ(ass[0], 3);
}

TEST(ShakerSortTest, SortedArray) {
    vector<ll> ass = {1, 2, 3, 4, 5};
    shaker_sort(ass);
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]);
    }
}

TEST(ShakerSortTest, ReverseSortedArray) {
    vector<ll> ass = {5, 4, 3, 2, 1};
    shaker_sort(ass);
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]);
    }
}

TEST(ShakerSortTest, RandomArray) {
    vector<ll> ass = {5, 2, 8, 1, 9, 4};
    shaker_sort(ass);
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]);
    }
}

TEST(ShakerSortTest, DuplicateElements) {
    vector<ll> ass = {1, 1, 2, 2, 3};
    shaker_sort(ass);
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]);
    }
}


// Test for Merge Sort
TEST(MergeSortTest, EmptyArray) {
    vector<ll> ass = {};
    merge_sort(ass, 0, 0); // Adjust the second parameter appropriately for empty arrays
    ASSERT_TRUE(ass.empty());
}

TEST(MergeSortTest, SingleElement) {
    vector<ll> ass = {3};
    merge_sort(ass, 0, ass.size()); 
    ASSERT_EQ(ass[0], 3);
}

TEST(MergeSortTest, SortedArray) {
    vector<ll> ass = {1, 2, 3, 4, 5};
    merge_sort(ass, 0, ass.size());
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]);
    }
}

TEST(MergeSortTest, ReverseSortedArray) {
    vector<ll> ass = {5, 4, 3, 2, 1};
    merge_sort(ass, 0, ass.size());
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]);
    }
}

TEST(MergeSortTest, RandomArray) {
    vector<ll> ass = {5, 2, 8, 1, 9, 4};
    merge_sort(ass, 0, ass.size());
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]);
    }
}

TEST(MergeSortTest, DuplicateElements) {
    vector<ll> ass = {2, 2, 4, 4, 6, 6}; // Duplicates
    merge_sort(ass, 0, ass.size());
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]); // Check sorted
    }
}


// Test for Heap Sort
TEST(HeapSortTest, EmptyArray) {
    vector<ll> ass = {};
    heap_sort(ass);
    ASSERT_TRUE(ass.empty());
}

TEST(HeapSortTest, SingleElement) {
    vector<ll> ass = {3};
    heap_sort(ass);
    ASSERT_EQ(ass[0], 3);
}

TEST(HeapSortTest, SortedArray) {
    vector<ll> ass = {1, 2, 3, 4, 5};
    heap_sort(ass);
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]);
    }
}

TEST(HeapSortTest, ReverseSortedArray) {
    vector<ll> ass = {5, 4, 3, 2, 1};
    heap_sort(ass);
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]);
    }
}

TEST(HeapSortTest, RandomArray) {
    vector<ll> ass = {5, 2, 8, 1, 9, 4};
    heap_sort(ass);
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]);
    }
}

TEST(HeapSortTest, DuplicateElements) {
    vector<ll> ass = {1, 1, 2, 2, 3, 3}; // Duplicates
    heap_sort(ass);
    for (int i = 0; i < ass.size() - 1; ++i) {
        ASSERT_LE(ass[i], ass[i + 1]); // Check sorted
    }
}


