#include <iostream> 
#include <fstream>  
#include <sstream>  
#include <vector>   
#include <unordered_map> 
#include <string>   

std::vector<int> countUniqueValues(std::string filename) {
    std::ifstream inputFile(filename); // Сложность: O(1) - открытие файла
    if (!inputFile) { // Сложность: O(1) - проверка успешности открытия файла
        throw std::runtime_error("Ошибка при открытии файла!"); // Сложность: O(1) - выброс исключения
    }

    std::vector<std::string> arr; // Сложность: O(1) - создание вектора
    std::string line; // Сложность: O(1) - создание строки

    // Читаем строки из файла и добавляем их в массив
    while (std::getline(inputFile, line)) { // Сложность: O(n) - чтение строк из файла (n - количество строк)
        std::istringstream iss(line); // Сложность: O(1) - создание строкового потока
        std::string value; // Сложность: O(1) - создание строки
        while (iss >> value) { // Сложность: O(n) - чтение значений из строки (n - количество значений в строке)
            arr.push_back(value); // Сложность: O(1) - добавление элемента в вектор
        }
    }
    inputFile.close(); // Сложность: O(1) - закрытие файла

    std::unordered_map<std::string, int> countMap; // Сложность: O(1) - создание хэш-таблицы

    // Подсчитываем количество вхождений каждого значения
    for (size_t i = 0; i < arr.size(); ++i) { // Сложность: O(n) r
        countMap[arr[i]]++; // Сложность: O(1) - вставка/обновление в хэш-таблице
    }

    std::vector<int> output; // Сложность: O(1) - создание выходного вектора
    // Заполняем выходной массив количеством вхождений
    for (size_t i = 0; i < arr.size(); ++i) { // Сложность: O(n) 
        output.push_back(countMap[arr[i]]); // Сложность: O(1) - доступ к элементу хэш-таблицы
    }

    return output; 
}

int main() {
    std::vector<int> result = countUniqueValues("input.txt"); // Сложность: O(n) 

    // Выводим результат
    for (size_t i = 0; i < result.size(); ++i) { // Сложность: O(n) - n- количество элементов в result
        std::cout << result[i] << " "; // Сложность: O(1) - вывод элемента
    }

    return 0; 
}