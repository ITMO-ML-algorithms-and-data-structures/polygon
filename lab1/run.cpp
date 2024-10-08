#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "label_encoder.cpp"

std::vector<std::string> read_file(const std::string& filePath) {
    std::vector<std::string> words;
    std::ifstream file(filePath);

    if (file.is_open()) {
        std::string line;
        if (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string word;

            // split by ","
            while (std::getline(ss, word, ',')) {
                words.push_back(word);
            }
        }
        file.close();
    } else {
        std::cerr << "Cant open ur file: " << filePath << std::endl;
    }

    return words;
}

void write_encoded_to_file(const std::string& filename, const std::vector<int>& encoded_labels) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const int label : encoded_labels) {
            file << label << " ";
        }
        file.close();
    } else {
        std::cerr << "Cant create result file: " << filename << std::endl;
    }
}

// dataset.txt -> dataset_encoded.txt
std::string create_output_filename(const std::string& input_filename) {
    std::size_t last_dot_pos = input_filename.find_last_of('.');
    if (last_dot_pos != std::string::npos) {
        return input_filename.substr(0, last_dot_pos) + "_encoded" + input_filename.substr(last_dot_pos);
    } else {
        return input_filename + "_encoded";
    }
}

int main(int argc, char* argv[]) {
    // check exists argument
    if (argc < 2) {
        std::cerr << "Usage ./run <path/filename>.txt" << std::endl;
        return 1;
    }

    // read filename
    std::string input_filename = argv[1];
    std::vector<std::string> categories = read_file(input_filename);

    if (categories.empty()) {
        std::cerr << "Ur file is empty" << std::endl;
        return 1;
    }

    LabelEncoder<int> encoder;
    encoder.fit(categories);
    std::vector<int> encoded_labels = encoder.transform(categories);

    std::cout << "Encoded labels: ";
    for (int label : encoded_labels) {
        std::cout << label << " ";
    }
    std::cout << std::endl;

    std::string output_filename = create_output_filename(input_filename);

    write_encoded_to_file(output_filename, encoded_labels);

    std::cout << "Encoded labels write to file: " << output_filename << std::endl;

    return 0;
}