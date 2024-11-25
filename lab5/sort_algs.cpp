#include <cmath>
#include <iostream>
#include <vector>

// TASK 1
// https://www.educative.io/answers/how-to-implement-comb-sort-in-cpp
void combSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return;

    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped) {
        gap = std::max(1, (int)(gap / 1.3));
        swapped = false;

        for (int i = 0; i < n - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

// TASK 2
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

// TASK 3
// я протестил несколько реализаций и эта работает быстрее всех
void timSort(std::vector<int>& arr) {
    int n = arr.size();
    int RUN = std::max(16, static_cast<int>(std::log2(n) * 2));

    auto insertionSort = [](std::vector<int>& arr, int left, int right) {
        for (int i = left + 1; i <= right; ++i) {
            int temp = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > temp) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = temp;
        }
    };

    auto merge = [](std::vector<int>& arr, int left, int mid, int right) {
        int len1 = mid - left + 1, len2 = right - mid;
        std::vector<int> leftArr(len1), rightArr(len2);

        for (int i = 0; i < len1; ++i) leftArr[i] = arr[left + i];
        for (int i = 0; i < len2; ++i) rightArr[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < len1 && j < len2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                ++i;
            } else {
                arr[k] = rightArr[j];
                ++j;
            }
            ++k;
        }

        while (i < len1) {
            arr[k] = leftArr[i];
            ++i;
            ++k;
        }

        while (j < len2) {
            arr[k] = rightArr[j];
            ++j;
            ++k;
        }
    };

    for (int i = 0; i < n; i += RUN) {
        insertionSort(arr, i, std::min(i + RUN - 1, n - 1));
    }

    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}
