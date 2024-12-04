#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <fstream>

void insertionSort(std::vector<int>& array) {
    std::vector<int>::size_type n = array.size();

    for (std::vector<int>::size_type i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
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
    std::string filename = "numbers10e4.txt";

    readFromFile(array, filename);

    auto start = std::chrono::high_resolution_clock::now();

    insertionSort(array);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "InsertionSort: " << duration.count() << " seconds" << std::endl;
    std::cout << "Array size: " << array.size() << std::endl;

    return 0;
}
