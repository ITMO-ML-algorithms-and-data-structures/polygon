#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// CocktailSort
vector<int> CocktailSort(vector<int>& vec) {
    bool isChange = true;
    int start = 0;
    int finish = vec.size() - 1;

    while (isChange) {
        isChange = false;

        // Проход в прямом направлении
        for (int i = start; i < finish; i++) {
            if (vec[i] > vec[i + 1]) {  // Сортировка по возрастанию
                swap(vec[i], vec[i + 1]);
                isChange = true;
            }
        }

        if (!isChange) break;

        isChange = false;

        // Проход в обратном направлении
        for (int i = finish; i > start; i--) {
            if (vec[i] < vec[i - 1]) {  // Сортировка по возрастанию
                swap(vec[i], vec[i - 1]);
                isChange = true;
            }
        }

        start += 1;
    }

    return vec;
}

// MergeSort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// BucketSort
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<float> b[n];
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        sort(b[i].begin(), b[i].end());
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}

// Тесты для CocktailSort
TEST(CocktailSortTest, BestCase) {
    vector<int> arr = {1, 2, 3, 4, 5};  // Уже отсортированный массив
    CocktailSort(arr);
    for (int i = 0; i < arr.size() - 1; ++i) {
        ASSERT_LE(arr[i], arr[i + 1]);  // Проверка, что массив отсортирован
    }
}

TEST(CocktailSortTest, AverageCase) {
    vector<int> arr = {3, 1, 4, 5, 2};  // Несортированный массив
    CocktailSort(arr);
    for (int i = 0; i < arr.size() - 1; ++i) {
        ASSERT_LE(arr[i], arr[i + 1]);  // Проверка, что массив отсортирован
    }
}

TEST(CocktailSortTest, WorstCase) {
    vector<int> arr = {5, 4, 3, 2, 1};  // Массив в обратном порядке
    CocktailSort(arr);
    for (int i = 0; i < arr.size() - 1; ++i) {
        ASSERT_LE(arr[i], arr[i + 1]);  // Проверка, что массив отсортирован
    }
}

// Тесты для MergeSort
TEST(MergeSortTest, BestCase) {
    vector<int> arr = {1, 2, 3, 4, 5};
    mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size() - 1; ++i) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}

TEST(MergeSortTest, AverageCase) {
    vector<int> arr = {3, 1, 4, 5, 2};
    mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size() - 1; ++i) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}

TEST(MergeSortTest, WorstCase) {
    vector<int> arr = {5, 4, 3, 2, 1};
    mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size() - 1; ++i) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}

// Тесты для BucketSort
TEST(BucketSortTest, BestCase) {
    vector<float> arr = {0.1, 0.2, 0.3, 0.4, 0.5};
    bucketSort(arr);
    for (int i = 0; i < arr.size() - 1; ++i) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}

TEST(BucketSortTest, AverageCase) {
    vector<float> arr = {0.4, 0.1, 0.5, 0.3, 0.2};
    bucketSort(arr);
    for (int i = 0; i < arr.size() - 1; ++i) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}

TEST(BucketSortTest, WorstCase) {
    vector<float> arr = {0.9, 0.8, 0.7, 0.6, 0.5};
    bucketSort(arr);
    for (int i = 0; i < arr.size() - 1; ++i) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);  // Инициализация Google Test
    return RUN_ALL_TESTS();  // Запуск всех тестов
}