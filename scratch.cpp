#include <iostream>
#include <vector>
#include <unordered_map>

void print_vector(std::string prefix, const std::vector<int> &vec) {
    // 1 * prefix.size() byte + 4 * vec.size() byte + additional bytes
    std::cout << prefix;
    for (auto val : vec) { // + 4 bytes
        std::cout << " " << val;
    }
    std::cout << std::endl;
}

std::vector<int> label_encoder(const std::string arr[], const int size) { // size * string[i].size() + 4 + 4 * size
    std::vector<int> out(size, 0);

    std::unordered_map<std::string, int> word_map; // w.p.c. size * string[i].size() + 4 * size
    int counter = 0; // 4
    for (int i = 0; i < size; i++) { // 4
        std::string word = arr[i]; // word.size() bytes

        if (word_map.find(word) == word_map.end()) {
            word_map[word] = counter;
            counter++;
        }
        out[i] = word_map[word];
    }
// size * string[i].size() + 4 + 4 * size + size * string[i].size() + 4 * size + 4 + 4 + word.size() = O(N)
    return out;
}
int main() {
    const std::string arr[] {"red", "green", "yellow", "yellow"};
    const int size = 4;

    std::vector<int> out = label_encoder(arr, size);

    print_vector("Encoded vector: ", out);

    return 0;
}