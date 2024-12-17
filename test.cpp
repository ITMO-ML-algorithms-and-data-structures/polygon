#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> read_file(const string filename) {
    vector<int> mas;
    ifstream in(filename);
    int number;

    while (in >> number) {
        mas.push_back(number);
    }
    return mas;
}

void shakerSort(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    bool swapped = true;

    while (left < right && swapped) {
        swapped = false;
        for (int i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        --right;
        for (int i = right; i > left; --i) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        ++left;
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void countingSort(vector<int>& arr, int exp) {
    vector<int> count(10, 0);
    vector<int> output(arr.size());

    for (int num : arr) {
        count[(num / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    arr = output;
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

void testSortingAlgorithm(void (*sortFunc)(vector<int>&), const string& name) {
    vector<int> bestCase = read_file("/Users/mir/CLionProjects/lab-5/best&worst.txt");
    sortFunc(bestCase);
    if (is_sorted(bestCase.begin(), bestCase.end())) {
        cout << name << " passed best case!" << endl;
    } else {
        cout << name << " failed best case!" << endl;
    }

    vector<int> worstCase = read_file("/Users/mir/CLionProjects/lab-5/best&worst.txt");
    reverse(worstCase.begin(), worstCase.end());
    sortFunc(worstCase);
    if (is_sorted(worstCase.begin(), worstCase.end())) {
        cout << name << " passed worst case!" << endl;
    } else {
        cout << name << " failed worst case!" << endl;
    }

    vector<int> averageCase = read_file("/Users/mir/CLionProjects/lab-5/test_arr/average.txt");
    sortFunc(averageCase);
    if (is_sorted(averageCase.begin(), averageCase.end())) {
        cout << name << " passed average case!" << endl;
    } else {
        cout << name << " failed average case!" << endl;
    }
}

int main() {
    testSortingAlgorithm(shakerSort, "ShakerSort");
    testSortingAlgorithm(insertionSort, "InsertionSort");
    testSortingAlgorithm(radixSort, "RadixSort");

    return 0;
}
