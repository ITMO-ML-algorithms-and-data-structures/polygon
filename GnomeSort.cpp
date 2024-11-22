#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <chrono>

void gnomeSort(std::vector<int>& array) {
    int index = 0;
    int n = array.size();

    while (index < n) {
        if (index == 0 || array[index] >= array[index - 1]) {
            index++;
        } else {
            std::swap(array[index], array[index - 1]);
            index--;
        }
    }
}

int main() {
    std::ifstream data_set("dataset.txt");

    std::string element; // 32 байта
    std::vector<int> array; // 24 байта

    while (getline(data_set, element, ';')) {
        array.push_back(stoi(element));
    } //+4*n байт в vector, где n - количество элементов в нем

    std::cout << "Original array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    gnomeSort(array);

    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "Sorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto duration = std::chrono::duration_cast <std::chrono::seconds>(stop - start);
    data_set.close();

    std::cout << duration.count() << " seconds";
}
