#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

// длина всех строк 2, всего их 5, значит в сумме они занимают 10 байт(ASCII)

std::vector<int> LabelEncoder(const std::vector<std::string>& vec) {
    std::unordered_map<std::string, int> encodedMap;
    int nextLabel = 0;
    for (const auto& str : vec) {
        if (encodedMap.find(str) == encodedMap.end()) {
            encodedMap[str] = nextLabel++;
        } // хэш - ключи 5 байт
        // хэш - значения 4*3 = 12
        // all hash = 17 байт
    }

    std::vector<int> EncodedVector;
    // 20 байт занимает EncodedVector, так как 5 значений
    for (const auto& str : vec) {
        EncodedVector.push_back(encodedMap[str]);
    }

    return EncodedVector;
}
// всего - 10+17+20 = 47 байт

int main() {
    std::ifstream infile("input.txt");
    if (!infile) {
        std::cerr << "Error: Unable to open input.txt" << std::endl;
        return 1;
    }

    std::vector<std::string> vec;
    std::string word;
    while (infile >> word) {
        vec.push_back(word);
    }
    infile.close();

    std::vector<int> LabelVec = LabelEncoder(vec);

    for (int label : LabelVec) {
        std::cout << label << std::endl;
    } // O(N)

    return 0;
}
