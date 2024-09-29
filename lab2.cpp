#include <iostream>
#include <vector>

int arr[]{3, 5, 6, 2, 2, 2, 4, 6, 7, 8, 8, 8, 4, 5, 5};

int main() {
    for (int i = 0; i < std::size(arr); i++) {
        std::cout << arr[i];
    }
    std::cout << std::endl;
    std::vector<int> not_dublic;
    for (int i = 0; i < std::size(arr); i++) {
        bool dublicate = false;
        for (int j = 0; j < std::size(not_dublic); j++) {
           if (arr[i] == not_dublic[j]) {
            dublicate = true;
           } 
        }
        if (dublicate == false) {
            not_dublic.push_back(arr[i]);
        }
    }
    for (int i = 0; i < std::size(not_dublic); i++) {
        std::cout << not_dublic[i];
    }
}