// LabelEncoder.cpp
#include "LabelEncoder.h"
#include <unordered_map>

std::vector<int> labelEncoder(const std::vector<std::string>& arr) {
    std::unordered_map<std::string, int> labelMap;
    std::vector<int> encodedArr;
    int label = 1;

    for (const auto& str : arr) {
        if (labelMap.find(str) == labelMap.end()) {
            labelMap[str] = label++;
        }
        encodedArr.push_back(labelMap[str]);
    }

    return encodedArr;
    // for N elements in arr It will
    // N * 4 + N * 32 bytes
}
//Contiene la implementación de las funciones.

