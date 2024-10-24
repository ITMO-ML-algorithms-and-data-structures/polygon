#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>

std::vector<int> countUniqueValues(std::string filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        throw std::runtime_error("Ошибка при открытии файла!");
    }

    std::vector<std::string> arr;
    std::string line;

    // Читаем строки из файла и добавляем их в массив
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string value;
        while (iss >> value) {
            arr.push_back(value);
        }
    }
    inputFile.close();

    std::unordered_map<std::string, int> countMap;

    // Подсчитываем количество вхождений каждого значения
    for (size_t i = 0; i < arr.size(); ++i) { // Используем индексы
        countMap[arr[i]]++;
    }

    std::vector<int> output;
    // Заполняем выходной массив количеством вхождений
    for (size_t i = 0; i < arr.size(); ++i) { // Используем индексы
        output.push_back(countMap[arr[i]]);
    }

    return output;
}

void Test(){
    std::vector<int> test_1 {2, 1, 1, 2};
    assert(countUniqueValues("input.txt") == test_1);
    std::cout << "OK";
}

int main() {
    // Тестируем функцию multiply с помощью assert
    Test();
    return 0;
}