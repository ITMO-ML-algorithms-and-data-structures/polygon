#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cassert>

std::vector<int> labelEncoder(const std::vector<std::string>& arr) {  // Задаем функцию (замена str -> int)
    std::unordered_map<std::string, int> label_map; //  32 байта на каждую запись (std::string + int)
    std::vector<int> encoded_arr;  //вектор интов конечный (4 байта на каждый int)
    int label = 1; // 4 байта для int

    for (const std::string& str : arr) {
        if (label_map.find(str) == label_map.end()) {  // нахождение стринга в мапе
            label_map[str] = label++; // задание значения каждому стрингу, который еще не нашелся в мапе
        }
        encoded_arr.push_back(label_map[str]); // добавление int (4 байта на элемент) в encoded_arr
    }

    return encoded_arr; // encoded_arr содержит n элементов, каждый занимает 4 байта (где n — длина arr)
}

int main() {
    std::vector<std::string> arr = { "Orange", "Red", "Green", "Orange", "Red" };
    std::vector<std::string> arrEmpty = {}; // пустой вектор (8-16 байт)
    std::vector<int> encoded_arr = labelEncoder(arr); // результат labelEncoder содержит 5 элементов, каждый занимает 4 байта

     // Тест на пустой массив
    std::vector<std::string> arrEmpty = {};
    assert(labelEncoder(arrEmpty).empty());

    // Тест на уникальные элементы
    std::vector<std::string> arrUnique = {"apple", "banana", "cherry"};
    auto encodedUnique = labelEncoder(arrUnique);
    assert(encodedUnique == std::vector<int>({1, 2, 3}));

    // Тест на повторяющиеся элементы
    std::vector<std::string> arrRepeated = {"apple", "banana", "apple", "banana"};
    auto encodedRepeated = labelEncoder(arrRepeated);
    assert(encodedRepeated == std::vector<int>({1, 2, 1, 2}));

    // Тест на чувствительность к регистру
    std::vector<std::string> arrCaseSensitive = {"apple", "Apple"};
    auto encodedCaseSensitive = labelEncoder(arrCaseSensitive);
    assert(encodedCaseSensitive == std::vector<int>({1, 2}));

    // Тест на большой объем данных (проверка только размера результата)
    std::vector<std::string> largeInput(10000, "apple");
    auto encodedLarge = labelEncoder(largeInput);
    assert(encodedLarge.size() == 10000);
    assert(encodedLarge[0] == 1 && encodedLarge[9999] == 1);

    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
    std::cout << "[ ";
    for (const int& val : encoded_arr) { // вывод значений из encoded_arr (4 байта на int)
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
    
    return 0;
}
