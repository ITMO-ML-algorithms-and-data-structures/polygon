#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>


int MinMaxScaler(std::string nameoffile) {
    
    std::ifstream file(nameoffile); // Открытие файла

    if (!file.is_open()) { // Проверка того, что файл открылся
        std::cerr << "Ошибка чтения файла" << std::endl;
        return 1;
    }
    
    std::vector<double> inputArray;
    std::string value;

    while (std::getline(file, value, '\t')) { // Считываем значение до табуляции (до конца строки)
        inputArray.push_back(std::stod(value));
    }
    
    file.close();
    
    double minValue = *std::min_element(inputArray.begin(), inputArray.end());
    double maxValue = *std::max_element(inputArray.begin(), inputArray.end());

    if (maxValue == minValue) { // Проверка на корректность
        std::cerr << "Ошибка. Максимальный элемент не может быть равен минимальному" << std::endl;
        return 1;
    }

    for(double& value : inputArray) { // Запись нового значения
        value = (value - minValue)/(maxValue - minValue);
    }

    for(const double& value : inputArray) { // Вывод массива
        std::cout << value << "\t";
    }

    return 0;
}


int main() {
    std::string nameoffile;
    std::cout << "Введите название файла" << std::endl;
    std::cin >> nameoffile;
    MinMaxScaler(nameoffile);
}
