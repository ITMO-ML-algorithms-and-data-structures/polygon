#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>

int main() {
    std::ifstream infile("dataset.txt");

    std::string data;
    std::getline(infile, data);
    infile.close();

    std::vector<std::string> arr;
    std::stringstream ss(data);
    std::string item;
    while (std::getline(ss, item, ',')) {
        arr.push_back(item);
    }

    std::unordered_map<std::string, int> hashTable;
    for (const auto& str : arr) {
        hashTable[str]++;
    }

    std::vector<int> result;
    for (const auto& str : arr) {
        result.push_back(hashTable[str]);
    }

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}