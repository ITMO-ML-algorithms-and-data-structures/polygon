#include "SamplingArray.h"

#include <vector>
#include <fstream>
#include <unordered_map>

#include "Utils/LCG.h"

// O(n)
std::vector<int> SamplingArray(const std::string& path, const int newSize) {
    std::ifstream inputFile(path); // O(1) 24-32 byte
    std::vector<int> outputValues(newSize); // O(n) int * n
    LCG lcg(time(nullptr) * 10, time(nullptr) * 100, time(nullptr) * 1000, time(nullptr) * 10000); // 4 long long vars - 32 byte O(1)
    std::unordered_map<int, int> countValues; // O(1) n * (int + int) byte
    std::vector<int> uniqueValues; // O(1) n * int byte

    if (!inputFile.is_open()) {
        return {}; // O(1)
    }

    while (!inputFile.eof()) {
        std::string currentLineValue; // 24 byte
        std::getline(inputFile, currentLineValue); // O(n)
        int currentValue = std::stoi(currentLineValue); // 4 byte
        countValues[currentValue] += 1;
        if (countValues[currentValue] > 1) {
            continue;
        }
        uniqueValues.push_back(currentValue);
    }
    inputFile.close(); // O(1)

    for (int i = 0; i < newSize; i++) {
        const int iterator = static_cast<int>(lcg.NextInRange(0, uniqueValues.size())); // 4 byte
        const int currentNumber = uniqueValues[iterator]; // 4 byte
        outputValues[i] = currentNumber;
        uniqueValues.erase(uniqueValues.begin() + iterator); // O(1)
    }

    return outputValues;
}