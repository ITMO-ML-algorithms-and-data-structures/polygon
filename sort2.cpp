#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

vector <int> do_merge(const vector<int> &a, const vector <int> &b) {
    vector <int> ans;
    int p1 = 0, p2 = 0, x;
    int n = a.size(), m = b.size();

    // берем текущий минимальный
    while (p1 < n && p2 < m) {
        if (a[p1] < b[p2])
            x = a[p1++];
        else
            x = b[p2++];

        ans.push_back(x);
    }

    // добавляем остальные элементы
    while (p1 < n)
        ans.push_back(a[p1++]);

    while (p2 < m)
        ans.push_back(b[p2++]);

    return ans;
}

vector<int> merge(vector<int> &a, int l, int r) {
    if (r - l == 0)
        return {};
    if (r - l == 1)
        return {a[l]};

    int m = (l + r) / 2;
    return do_merge(merge(a, l, m), merge(a, m, r)); // разделяем на 2 подмассива
}

vector<int> MergeSort(vector<int> &a) {
    return merge(a, 0, a.size());
}

TEST(SortTest, Test0) {
    vector<int> in({1, 2, 3, 4});
    vector<int> res = MergeSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test1) {
    vector<int> in({1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9});
    vector<int> res = MergeSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test2) {
    vector<int> in({5, 4, 3, 2, 1});
    vector<int> res = MergeSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test3) {
    vector<int> in({3, 3, -2, 1, 4, 5, -5, 1, 3});
    vector<int> res = MergeSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test4) {
    vector<int> in({});
    vector<int> res = MergeSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test5) {
    vector<int> in({100000, -323443, 43, 2312, 435, -657, 3794874, 3803, 21, 21, 32, 0, -5});
    vector<int> res = MergeSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

TEST(SortTest, Test6) {
    vector<int> in({8, 7, 6, 5, 4, 3, 2, 1});
    vector<int> res = MergeSort(in);
    EXPECT_TRUE(is_sorted(res.begin(), res.end()));
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
