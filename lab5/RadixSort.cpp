#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>


void countingSort(std::vector<int>& arr, const int& exp) {
    int n = arr.size();
    std::vector<int> res(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        res[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    arr = res;
}


std::vector<int> radixSort(std::vector<int> arr) {
    int arrMax = *max_element(arr.begin(), arr.end());

    for (int exp = 1; arrMax / exp > 0; exp *= 10) countingSort(arr, exp);

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
    std::vector<int> arrSort = radixSort(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    display(arr, arrSort, duration);
}


int main() {
    test(10, 999999, 0);
    return 0;
}