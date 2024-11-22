#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>


// Чтение данных из файла
std::vector<double> readFile(const std::string& nameoffile) {
    std::ifstream file(nameoffile);
    std::vector<double> inputArray; // +4 байта

    if (not(file.is_open())) { // Проверка, что файл открылся
        std::cerr << "Ошибка чтения файла" << std::endl;
        return inputArray;
    }

    std::string value; // +24 байта
    while (std::getline(file, value, '\t')) { // Считываем строку до табуляции
        inputArray.push_back(std::stod(value)); // +8*N байт, где N - количество чисел
    }

    file.close();
    return inputArray;
}


// MinMaxScaler
std::vector<double> MinMaxScaler(std::vector<double>& inputArray) {
    if (inputArray.empty()) { // Если массив пустой, вернуть его же
        std::cerr << "Ошибка: пустой массив" << std::endl;
        return inputArray;
    }

    double minValue = *std::min_element(inputArray.begin(), inputArray.end()); // +8 байт
    double maxValue = *std::max_element(inputArray.begin(), inputArray.end()); // +8 байт

    if (maxValue == minValue) { // Проверка на корректность
        std::cerr << "Ошибка: максимальный элемент не может быть равен минимальному" << std::endl;
        return inputArray;
    }

    for (double& value : inputArray) { // Записываем новые значения в вектор
        value = (value - minValue) / (maxValue - minValue);
    }

    return inputArray;
}


// Функция для вывода данных
int printArray(const std::vector<double>& array) {
    for (const double& value : array) {
        std::cout << value << "\t";
    }
    return 0;
}


// Функция для тестов
void tests() {
    // Проверка чтения данных из файла
    {
        std::ofstream testFile("test.txt");
        testFile << "1\t2\t3\t4\t5\t";
        testFile.close();
        std::vector<double> testArray = {1.0, 2.0, 3.0, 4.0, 5.0};
        assert(readFile("test.txt") == testArray);
    }

    // Проверка MinMaxScaler
    {
        std::vector<double> testArray = {2.0, 2.0, 3.0, 4.0, 5.0};
        testArray = MinMaxScaler(testArray);
        double minValue = *std::min_element(testArray.begin(), testArray.end());
        double maxValue = *std::max_element(testArray.begin(), testArray.end());
        assert(minValue == 0.0);
        assert(maxValue == 1.0);
        assert(testArray[0] == testArray[1]);
    }
    
    std::cout << "Всё чётко" << std::endl;
}


int main() {
    // Запуск тестов
    tests();

    // Считывание имени файла
    std::string nameoffile; // +24 байта
    std::cout << "Введите название файла: ";
    std::cin >> nameoffile;

    // Сама программа
    std::vector<double> inputArray = readFile(nameoffile);
    inputArray = MinMaxScaler(inputArray);
    printArray(inputArray);
}

// 4 + 8*N + 24 + 8 + 8 + 24 = 8*N + 68 байт
