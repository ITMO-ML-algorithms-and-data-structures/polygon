#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <chrono>

void find_zero_subarrays(std::vector<int>& array) {
    unsigned short array_size = array.size(); //1 байт, O(1)
    
    //Сложность цикла O(N^5)
    for (unsigned short k1 = 0; k1 < array_size-4; k1++) { //1 байт
        for (unsigned short k2 = k1+1; k2 < array_size-3; k2++) { //1 байт
            for (unsigned short k3 = k2+1; k3 < array_size-2; k3++) { //1 байт
                for (unsigned short k4 = k3+1; k4 < array_size-1; k4++) { //1 байт
                    for (unsigned short k5 = k4+1; k5 < array_size; k5++) { //1 байт
                        if ((array[k1] + array[k2] + array[k3] + array[k4] + array[k5]) == 0) { // O(1) + O(1) + O(1) + O(1) + O(1)
                            std::cout << "[" << k1 << ", " << k2 << ", " << k3 << ", " << k4 << ", " << k5 << "]\n";
                        }
                    }
                }
            }
        }
    }
}

int main() {
    std::ifstream data_set("dataset.txt");

    std::string element; // 32 байта
    std::vector<int> array; // 24 байта

    while (getline(data_set, element, ';')) {
        array.push_back(stoi(element));
    } //+4*n байт в vector, где n - количество элементов в нем
    
    auto start = std::chrono::high_resolution_clock::now();

    find_zero_subarrays(array);
    
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast < std::chrono::microseconds > (stop - start);
    data_set.close();

    std::cout << duration.count() << " microseconds";
}