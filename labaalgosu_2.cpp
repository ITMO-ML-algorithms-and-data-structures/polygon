#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::vector <int>  arr = { 1, 2, 3, 1 }; // кол - во памяти 40 байт; т.к  тип int занимает 4 байта, вся строка = 4 * n(в нашем случае 4 * 4 = 16), где n - кол - во элементов вектора + std::vectore хранит 8 байт на каждый указатель у нас их три то есть 3 * 8 = 24
        int size = arr.size(); // int - 4 байта

        std::unordered_set<int> unique_values; // 12байт   int - 4 байта, хранит 3 элемента
    std::vector<int> result; // 24 байт т.к 3*8

    for (int i = 0; i < size; ++i) {  //4 байта
        if (unique_values.find(arr[i]) == unique_values.end()) {
            unique_values.insert(arr[i]); //20   4 + 16 байтдля доп информации
            result.push_back(arr[i]); // 4 байта на 1 элемент + какое-то кол-во доп.памяти
        }
    }

    for (int i = 0; i < result.size(); ++i) { // 4байта i 
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}  // всего памяти  40+4+12=24+4+20+4+4= 112 байт