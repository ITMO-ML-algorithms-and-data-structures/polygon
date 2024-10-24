#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <sstream>

// функция для удаления дубликатов
std::vector<int> removeDuplicates(const std::vector<int>& arr) {
    std::unordered_set<int> seen;
    std::vector<int> result;

    for (int num : arr) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }

    return result;
}

int main() {
    // краш-тест с огромным датасетом
    std::ifstream inputFile("./numbers.tsv");
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    std::vector<int> chest;
    std::string line;

    // чтение данных из файла
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            chest.push_back(num);
        }
    }

    inputFile.close();

    // удаление дубликатов
    std::vector<int> uniqueChest = removeDuplicates(chest);

    std::cout << "количество уникальных значений: " << uniqueChest.size() << std::endl;

    // пример
    std::vector<int> testArr = {1, 2, 3, 1};
    std::vector<int> testUniqueArr = removeDuplicates(testArr);

    std::cout << "тест на уникальные значения: ";
    for (int num : testUniqueArr) {
        std::cout << num << " ";
    }

    // считаем память
    std::cout << "\nРазмер вектора chest: " << sizeof(chest) << " байт" << std::endl;
    std::cout << "Размер вектора uniqueChest: " << sizeof(uniqueChest) << " байт" << std::endl;
    std::cout << "Размер unordered_set seen: " << sizeof(std::unordered_set<int>) << " байт" << std::endl;
    std::cout << "Размер строки line: " << sizeof(line) << " байт" << std::endl;
    std::cout << "Общий размер: " << sizeof(chest) + sizeof(uniqueChest) + sizeof(std::unordered_set<int>) + sizeof(line) << " байт" << std::endl;

    return 0;
}
