#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>

std::vector<unsigned long long> function(std::vector<unsigned long long> array) {
    //Удалить все повторяющиеся элементы в массиве
    std::vector<unsigned long long> uniqueArr; //64*n byte
    std::unordered_set<unsigned long long> seen; // 64 bytes for each element

    for (unsigned long long num: array) {
        //Проверка на то, был ли элемент ранее и его добавление в итог если да
        if (seen.count(num) == 0) {
            uniqueArr.push_back(num); //64 bytes
            seen.insert(num); //64 bytes
        }
    }
    //64*(n+3) bytes total

    return uniqueArr;
}


void test() {
    std::vector<unsigned long long> arr1 = {1, 2, 3, 12, 4, 5, 6, 7, 8, 8, 9, 5, 10, 11, 1, 12, 13, 13, 14, 15};
    std::vector<unsigned long long> arr2 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<unsigned long long> arr3 = {};
    std::vector<unsigned long long> good3 = {};
    std::vector<unsigned long long> good2 = {1};
    std::vector<unsigned long long> good1 = {1, 2, 3, 12, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15};
    //Просто тест
    assert(function(arr1) == good1);
    //Тест со всеми одинаковыми
    assert(function(arr2) == good2);
    //Тест с пустым массивом
    assert(function(arr3) == good3);
}


int main() {
    test();
    //считываем Файл построчно
    std::ifstream inputFile("../input.txt");
    std::vector<unsigned long long> array;
    std::string number;
    while (std::getline(inputFile, number)) {
        array.push_back(std::stoi(number));
    }
    inputFile.close();

    std::vector<unsigned long long> uniqueArr = function(array);

    std::cout << "Массив без дубликатов: ";
    for (unsigned long long num: uniqueArr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
