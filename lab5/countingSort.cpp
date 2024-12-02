#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <algorithm>

void countingSort(std::vector<int>& array) {
    if (array.empty()) return;

    int maxElement = *std::max_element(array.begin(), array.end());

    std::vector<int> count(maxElement + 1, 0);

    for (const auto& num : array) {
        count[num]++;
    }

    std::vector<int>::size_type index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            array[index++] = i;
            count[i]--;
        }
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
    std::string filename = "numbers10e5.txt";

    readFromFile(array, filename);

    auto start = std::chrono::high_resolution_clock::now();

    countingSort(array);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "CountingSort: " << duration.count() << " seconds" << std::endl;
    std::cout << "Array size: " << array.size() << std::endl;

    return 0;
}
