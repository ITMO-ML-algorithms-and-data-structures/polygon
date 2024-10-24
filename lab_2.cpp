#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

// Функцмя для удаления дубликатов
void antiDUB(std::vector<int>& arr) {
    // Проверяем, пустой ли вектор
    if (arr.empty()) {
        return;   
    }
    
    // Сортирируем по возрастранию
    std::sort(arr.begin(), arr.end());

    // Ищем дубликаты в векторе
    int dublChek = 0; // + 4 байта
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[dublChek]) { // Если не равны, то заменяем следующий эл-т на не повторяющийся
            dublChek++;
            arr[dublChek] = arr[i];
        }
    } 
    // Выводим вектор без учетов дубликатов
    return arr.resize(dublChek + 1);
}

int main(){
    int size; // + 4 байта 
    std::cin >> size;
    std::vector<int> numbers(size); 
    // Вводим числа в вектор 
    for (int i = 0; i < size; ++i) {  
        std::cin >> numbers[i]; // 24 + 4 * size байта
    }

    // Убираем дубликат через функцию
    antiDUB(numbers);

    // Вывод вектора
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
}

// TEST
void test_antiDUB() {
    {   
        // Базовый случай
        std::vector<int> test = {1, 1, 2, 3, 2, 4, 4, 4, 1}; 
        std::vector<int> result = {1, 2, 3, 4};
        antiDUB(test); 
        assert(test == result);
    }

    {
        // Без дубликатов
        std::vector<int> test = {1, 2, 3}; 
        std::vector<int> result = {1, 2, 3}; 
        antiDUB(test); 
        assert(test == result);
    }

    {
        // Пустой вектор
        std::vector<int> test = {}; 
        std::vector<int> result = {}; 
        antiDUB(test); 
        assert(test == result);   
    }

    {
        // Только одинаковые элементы
        std::vector<int> test = {1, 1, 1, 1, 1, 1}; 
        std::vector<int> result = {1}; 
        antiDUB(test); 
        assert(test == result);
    }

    {
        // Один элемент 
        std::vector<int> test = {2}; 
        std::vector<int> result = {2}; 
        antiDUB(test); 
        assert(test == result);        
    }

    std::cout << "Все тесты прошли успешно!";
    }

