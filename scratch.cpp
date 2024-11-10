#include <iostream>
#include <vector>
#include <unordered_map>

void print_vector(std::string prefix, const std::vector<int> &vec) {
    std::cout << prefix;
    for (auto val : vec) {
        std::cout << " " << val;
    }
    std::cout << std::endl;
}

std::vector<int> label_encoder(const std::string arr[], const int size) {
    std::vector<int> out(size, 0);

    std::unordered_map<std::string, int> word_map;

    int counter = 0;
    for (int i = 0; i < size; i++) {
        std::string word = arr[i];

        if (word_map.find(word) == word_map.end()) {
            word_map[word] = counter;
            counter++;
        }

        out[i] = word_map[word];
    }

    return out;
}
int main() {
    const std::string arr[] {"red", "green", "yellow", "yellow"};
    const int size = 4;

    std::vector<int> out = label_encoder(arr, size);

    print_vector("Encoded vector: ", out);

    return 0;
}