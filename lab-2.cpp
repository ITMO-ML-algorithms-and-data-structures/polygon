
#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
    std::string arr[] = {"яблоко", "яблоко", "яблоко", "апельсин", "груша", "апельсин", "киви", "вишня"};

    int size = sizeof(arr) / sizeof(arr[0]); 

    std::map<std::string, int> counts;

    for (int i = 0; i < size; ++i) {
        counts[arr[i]]++;
    }

    std::vector<int> result;
    for (int i = 0; i < size; ++i) {
        result.push_back(counts[arr[i]]);
    }

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
}


