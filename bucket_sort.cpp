#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int findMin(const int arr[], int n) {
    int minValue = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

int findMax(const int arr[], int n) {
    int maxValue = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int findRange(const int arr[], int n) {
    return findMax(arr, n) - findMin(arr, n) + 1;
}

void distributeIntoBuckets(const int arr[], int n, int buckets[][10], int bucketSizes[], int bucketCount) {
    int minValue = findMin(arr, n);
    int range = findRange(arr, n);

    for (int i = 0; i < n; ++i) {
        int bucketIndex = (arr[i] - minValue) * bucketCount / range;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }
}

void sortBuckets(int buckets[][10], int bucketSizes[], int bucketCount) {
    for (int i = 0; i < bucketCount; ++i) {
        insertionSort(buckets[i], bucketSizes[i]);
    }
}

void concatenateBuckets(int arr[], int buckets[][10], int bucketSizes[], int bucketCount) {
    int index = 0;
    for (int i = 0; i < bucketCount; ++i) {
        for (int j = 0; j < bucketSizes[i]; ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

void bucketSort(int arr[], int n) {
    const int bucketCount = 5; 
    int buckets[bucketCount][10] = {0}; 
    int bucketSizes[bucketCount] = {0}; 

    distributeIntoBuckets(arr, n, buckets, bucketSizes, bucketCount);
    sortBuckets(buckets, bucketSizes, bucketCount);
    concatenateBuckets(arr, buckets, bucketSizes, bucketCount);
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void testBucketSort() {
    // Лучший случай (уже отсортированный массив)
    int bestCase[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int bestCaseSize = sizeof(bestCase) / sizeof(bestCase[0]);
    bucketSort(bestCase, bestCaseSize);
    assert(is_sorted(bestCase, bestCase + bestCaseSize));

    // Средний случай (случайный порядок)
    int averageCase[] = {3, 1, 4, 9, 6, 7, 8, 2, 5, 10};
    int averageCaseSize = sizeof(averageCase) / sizeof(averageCase[0]);
    bucketSort(averageCase, averageCaseSize);
    assert(is_sorted(averageCase, averageCase + averageCaseSize));

    // Худший случай (обратный порядок)
    int worstCase[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int worstCaseSize = sizeof(worstCase) / sizeof(worstCase[0]);
    bucketSort(worstCase, worstCaseSize);
    assert(is_sorted(worstCase, worstCase + worstCaseSize));

    cout << "All tests passed!" << endl;
}

int main() {
    testBucketSort();
    return 0;
}