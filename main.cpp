#include <string>
#include <iostream>
#include <fstream>
#include "LabelEncoder.h"


int main() {
    std::ifstream file("../input_data/input_2.txt");

    LabelEncoder<std::string, int> encoder;

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }

    std::string line;
    std::vector<int> classes;
    while(std::getline(file, line)) {
        classes.push_back(encoder.fit_transform_by_one_label(line));
    }

    file.close();

    std::ofstream output_file;

    output_file.open("../output_data/output.txt");

    if (!output_file.is_open())
        throw std::runtime_error("Failed to open output file");

    for (auto i: classes) {
        output_file << i << "\n";
    }

    file.close();
}