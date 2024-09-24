#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

int main() {
    std::ifstream infile("dataset.txt");

    std::vector<std::string> arr; 
    std::string item; // выделяем память для каждого элемента при чтении, получается при максимальной длине строки до 100 символов -> до 100 байт памяти использования
    while (std::getline(infile, item, ',')) {
        arr.push_back(item); // (i + 24) * N, где N - кол-во строк, i - память строки, i <= 100
    }

    std::unordered_map<std::string, int> hashTable; // если все значения уникальны, то получим что (i + 4) * N 
    for (const auto& str : arr) {
        hashTable[str]++; // если строка уникальна, то в хэш таблицу добавляется до 100 байт для строки + 4 байта для int
    }

    std::vector<int> result; // для конечного резулятата N * 4
    for (const auto& str : arr) {
        result.push_back(hashTable[str]);
    }

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        std::cout << " ";
    }   

    // Итого 1. Расход на вектор N * (i + 24)
    // 2. Хэш таблица N * (i + 4)
    // 3. result N * 4 
    // N * (i + 24) + N * (i + 4) + N * 4 
    return 0;
}