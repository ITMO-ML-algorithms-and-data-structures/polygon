#include <iostream>
#include <vector>
#include <random>
#include <chrono>


std::vector<int> insertionSort(std::vector<int> arr) {
    int n = arr.size();
    for (int i=1; i<n; i++) 
        for (int j=i; j>0 && arr[j-1]>arr[j]; j--)
            std::swap(arr[j-1], arr[j]);

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

    std::cout << "\n";
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
    std::vector<int> arrSort = insertionSort(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    display(arr, arrSort, duration);
}   
int main() {
    test(1000, 999, 99999);
    return 0;
}