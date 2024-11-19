#include <iostream>
#include <vector>
#include <fstream>

std::vector<short int> read_file(const std::string& filename) {
    std::vector<short int> arr;
    std::ifstream in(filename);
    short int number; // 2 байта

    while (in >> number) {
        arr.push_back(number); // + 24 байта * N
    }

    return arr;
}

int main() {
    std::vector<short int> arr = read_file("numbers.tsv");
    std::cout << "Start dataset:" << std::endl;
    for (short int i = 0; i < std::size(arr); i++) { //O(1 + 1 + 1 + ...) = O(N) + 4 байта
        std::cout << arr[i] << " "; // O(1)
    }
    std::cout << std::endl; // O(1)
    std::vector<short int> not_dublic; // O(1) 2 байта
    for (short int i = 0; i < std::size(arr); i++) { // O(1 + 1 + ...) = O(N) + 4 байта
        bool dublicate = false; // O(N) * O(1 + 1) + 1 байт
        for (short int j = 0; j < std::size(not_dublic); j++) { // O(N) * O(1 + 1), O(N) * O(1 + 1) + 4 байта
           if (arr[i] == not_dublic[j]) { // O(N) * O(1 + 1 + 1)
           // O(N) * O(1 + 1 + 1 + ...) = O(N) * O(N) = O(N^2)
            dublicate = true; // O(N^2 + 1) 1 байт
           } 
        }
        if (dublicate == false) { // O(N) * O(1 + 1) * O(1 + 1 + 1)
            not_dublic.push_back(arr[i]);
        }
    }
    std::cout << "Change dataset (remove dublicate)";
    for (short int i = 0; i < std::size(not_dublic); i++) { //O(1 + 1 + 1 + ...) = O(N) + 4 байта
        std::cout << not_dublic[i] << " "; // O(1)

    }
}