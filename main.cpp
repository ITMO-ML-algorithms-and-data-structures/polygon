#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include "label_encoder.h"



int main() {
    std::ifstream inputFile("input.txt");

    std::vector<int> encoded_values = label_encode(inputFile);

    for (const int value : encoded_values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
