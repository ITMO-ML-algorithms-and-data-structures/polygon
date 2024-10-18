#include "label_encoder.h"
#include <unordered_map>

std::vector<int> label_encode(std::ifstream& input) {
    std::vector<std::string> arr; // +24
    std::string line; // +32

    while (std::getline(input, line)) {
        if (!line.empty()) {
            arr.push_back(line); // +32
        }
    }

    std::vector<int> T; // +24
    std::unordered_map<std::string, int> labelencoder; // +56
    int cur_ind = 0; // +4

    for (const auto& str : arr) {
        if (labelencoder.find(str) == labelencoder.end()) {
            labelencoder[str] = cur_ind + 1; // +5
            cur_ind += 1;
        }
        T.push_back(labelencoder[str]); // +4
    }

    return T;
}
