#include <iostream>
#include <vector>
#include "sort_algorithms.h"

int main() {
    std::vector<int> arr;
    std::ifstream file("aaa.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
    }
    file.close();

    std::vector<int> sorted_arr;

    // Вызов Counting Sort
    // countingSort(arr, sorted_arr);

    // Вызов QuickSort
    // quicksort(arr, 0, arr.size() - 1);
    // sorted_arr = arr;

    // Вызов Cocktail Sort
    // CoctailSort(arr);
    // sorted_arr = arr;

    for (int x : sorted_arr) {
        std::cout << x << " ";
    }
    return 0;
}

