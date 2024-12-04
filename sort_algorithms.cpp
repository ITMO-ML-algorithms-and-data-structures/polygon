#include "sort_algorithms.h"

void countingSort(const std::vector<int>& arr, std::vector<int>& sorted_arr) {
    if (arr.empty()) {
        return;
    }
    int min_val = *std::min_element(arr.begin(), arr.end());
    int max_val = *std::max_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;
    std::vector<int> count(range, 0);
    for (int num : arr) {
        count[num - min_val]++;
    }
    for (size_t i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    sorted_arr.resize(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        sorted_arr[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }
}

void quicksort(std::vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot = arr[(low + high) / 2];
    int i = low;
    int j = high;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (low < j) {
        quicksort(arr, low, j);
    }
    if (i < high) {
        quicksort(arr, i, high);
    }
}

void CoctailSort(std::vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    bool c = true;
    while (c) {
        c = false;
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                c = true;
            }
        }
        if (!c) break;
        end--;
        c = false;
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                c = true;
            }
        }
        start++;
    }
}
