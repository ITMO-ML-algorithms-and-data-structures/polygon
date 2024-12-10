#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>  

using namespace std;

void insertionSort(vector<int>& array, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int currentElement = array[i];
        int j = i - 1;
        while (j >= left && array[j] > currentElement) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = currentElement;
    }
}

void merge(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArray(n1), rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        } else {
            array[k++] = rightArray[j++];
        }
    }

    while (i < n1) {
        array[k++] = leftArray[i++];
    }
    while (j < n2) {
        array[k++] = rightArray[j++];
    }
}

int calculateMinRun(int n) {
    int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

void TimSort(vector<int>& array) {
    int n = array.size();
    int minRun = calculateMinRun(n);

    for (int start = 0; start < n; start += minRun) {
        int end = min(start + minRun - 1, n - 1);
        insertionSort(array, start, end);
    }

    for (int size = minRun; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(n - 1, left + size - 1);
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right) {
                merge(array, left, mid, right);
            }
        }
    }
}

int main() {
    ifstream inputFile("numbers1e6.txt");
    vector<int> numbers;
    int num;

    while (inputFile >> num) {
        numbers.push_back(num);
    }

    inputFile.close();

    auto start = chrono::high_resolution_clock::now();

    TimSort(numbers);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "First 100 sorted nums: ";
    for (size_t i = 0; i < numbers.size() && i < 100; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << fixed << setprecision(5);
    cout << "Work time: " << elapsed.count() << " sec." << endl;

    return 0;
}
