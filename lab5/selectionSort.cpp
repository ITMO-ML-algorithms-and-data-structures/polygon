#include <iostream>
#include <utility>
#include <vector>
#include <chrono>
#include <iomanip>
#include <fstream>

void selectionSort(std::vector<int>& array) {
    // Use std::vector<int>::size_type for the size and indices
    std::vector<int>::size_type n = array.size();

    for (std::vector<int>::size_type i = 0; i < n - 1; i++) {
        std::vector<int>::size_type indexOfMinimal = i;
        for (std::vector<int>::size_type j = i + 1; j < n; j++) {
            if (array[j] < array[indexOfMinimal]) {
                indexOfMinimal = j;
            }
        }
        std::swap(array[indexOfMinimal], array[i]);
    }
}

void readFromFile(std::vector<int>& array, const std::string& filename) {
    std::ifstream file(filename);

    int number;
    while (file >> number) {
        array.push_back(number);
    }

    file.close();
}

int main() {
    std::vector<int> array;
    std::string filename = "numbers10e6.txt"; 

    readFromFile(array, filename);

    auto start = std::chrono::high_resolution_clock::now();

    selectionSort(array);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "SelectionSort: " << duration.count() << " seconds" << std::endl;
    std::cout << "Array size: " << array.size() << std::endl;

    return 0;
}
