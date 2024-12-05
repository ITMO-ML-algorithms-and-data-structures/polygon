#include <iostream>
#include <vector>
#include <random>
#include <chrono>


void merge(std::vector<int>& arr, const int& left, const int& mid, const int& right) {
    int nLeft = mid - left + 1;
    int nRight = right - mid; 

    std::vector<int> arrLeft(nLeft);
    std::vector<int> arrRight(nRight);

    for (int i=0; i<nLeft; i++) arrLeft[i] = arr[left + i];
    for (int i=0; i<nRight; i++) arrRight[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i<nLeft && j<nRight) {
        if (arrLeft[i]<=arrRight[j]) {
            arr[k] = arrLeft[i];
            i++;
        } else {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }

    while (i<nLeft) {
        arr[k] = arrLeft[i];
        i++;
        k++;
    }

    while (j<nRight) {
        arr[k] = arrRight[j];
        j++;
        k++;
    }
}


std::vector<int> mergeSort(std::vector<int> arr, int left, int right) {
    if (left<right) {
        int mid = left + (right - left) / 2;

        arr = mergeSort(arr, left, mid);
        arr = mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
    return arr;
}


std::vector<int> arrRand(const int& n, const int& arrMin, const int& arrMax) {
    std::vector<int> arr(n);
    std::random_device rd;
    std::mt19937 seed(rd());

    for (int i=0; i<n; ++i) arr[i] = arrMin + seed() % (arrMax - arrMin);

    return arr;
}


void display(const std::vector<int>& arr, const std::vector<int>& arrSort, std::chrono::duration<double> duration) {
    int n = arr.size();
    std::cout << "\nРазмер массива:\n" << n;

    std::cout << "\nВремя выполнения:\n" << duration.count();
    /*
    std::cout << "\nИсходный массив:\n";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";

    std::cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < n; i++) std::cout << arrSort[i] << " ";
    */
}


void test(const int& n = 10, const int& arrMax = 100, const int& arrMin = 0) {
    std::vector<int> arr = arrRand(n, arrMin, arrMax);

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> arrSort = mergeSort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    display(arr, arrSort, duration);
}


int main() {
    test();
    return 0;
}