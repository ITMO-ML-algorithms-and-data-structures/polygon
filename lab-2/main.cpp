//
// Created by timof on 03.10.2024.
//

#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int size;
    std::string el;

    std::vector<std::string> names;
    std::unordered_map<std::string, int> counts;

    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cin >> el;
        names.push_back(el);
        if (counts.find(el) == counts.end()) {
            counts[el] = 1;
        }
        else {
            counts[el]++;
        }
    }
    for (int i = 0; i < size; i++) {
        std::cout << counts[names[i]] << " ";
    }
}