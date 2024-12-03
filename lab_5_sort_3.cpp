#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int RUN = 32;

void insertion_sort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int len1 = mid - left + 1, len2 = right - mid;
    vector<int> left_arr(len1);
    vector<int> right_arr(len2);
    for (int i = 0; i < len1; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int i = 0; i < len2; i++) {
        right_arr[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < len2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void timsort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i += RUN) {
        insertion_sort(arr, i, min((i + RUN - 1), (n - 1)));
    }
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min((left + size - 1), (n - 1));
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}


