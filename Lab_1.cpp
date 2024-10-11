#include <iostream>
#include <vector>
#include <set>
#include <cassert>

// Функция для удаления дубликатов 
std::vector<int> antiDUB(std::vector<int>& numbers){ 
    std::set<int> uniq (numbers.begin(), numbers.end()); // + 32 * N байт
    std::vector<int> uniqNum (uniq.begin(), uniq.end()); // Переносим все обратно в вектор
    return uniqNum;
}

// Программа для удаления дубликатов
int main(){
    int size; // + 4 байта 
    std::cin >> size;
    std::vector<int> numbers(size); 
    // Вводим числа в вектор 
    for (int i = 0; i < size; ++i) {  
        std::cin >> numbers[i]; // 24 + 4 * size байта
    }

    // Убираем дубликат через функцию
    std::vector<int> numbTrue = antiDUB(numbers); // 24 + 4 * N байт

    // Вывод вектора
    for (const int& num : numbTrue) {
        std::cout << num << " ";
    }
}


// TEST
void test_antiDUB() {
    {   
        // Базовый случай
        std::vector<int> test = {1, 1, 2, 3, 2, 4, 4, 4, 1}; 
        std::vector<int> result = {1, 2, 3, 4}; 
        assert(antiDUB(test) == result);
    }

    {
        // Без дубликатов
        std::vector<int> test = {1, 2, 3}; 
        std::vector<int> result = {1, 2, 3}; 
        assert(antiDUB(test) == result);
    }

    {
        // Пустой вектор
        std::vector<int> test = {}; 
        std::vector<int> result = {}; 
        assert(antiDUB(test) == result);   
    }

    {
        // Только одинаковые элементы
        std::vector<int> test = {1, 1, 1, 1, 1, 1}; 
        std::vector<int> result = {1}; 
        assert(antiDUB(test) == result);
    }

    {
        // Один элемент 
        std::vector<int> test = {2}; 
        std::vector<int> result = {2}; 
        assert(antiDUB(test) == result);
    }

    std::cout << "Все тесты прошли успешно!";
    }