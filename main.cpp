#include <string>
#include <iostream>
#include <fstream>
#include "LabelEncoder.h"


int main() {
    std::ifstream file("../input_data/input_2.txt"); // 160 байт

    LabelEncoder<std::string, int> encoder;

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }

    std::string line; // 24 байт
    std::vector<int> classes; // 24 байт
    while(std::getline(file, line)) {
        classes.push_back(encoder.fit_transform_by_one_label(line));
    }

    file.close();

    std::ofstream output_file; // 160 байт

    output_file.open("../output_data/output.txt");

    if (!output_file.is_open())
        throw std::runtime_error("Failed to open output file");

    for (auto i: classes) {
        output_file << i << "\n";
    }

    file.close();
}