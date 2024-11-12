#include <cassert>///проверяет, что определенное условие является истинны
#include <iostream>///файл организации ввода-вывода
#include <map>///ключ-значение
#include <vector>///быстрое добавление новых элементов в конец,изменение размера при необходимости
#include <string>///позволяет легко выполнять операции, такие как конкатенация, поиск, замена
using namespace std;

vector<string> arr = {"Orange", "Red", "Green", "Orange"};/// объявляем
void countAndReplace(vector<string>& arr) {
    map<string, int> unique_counts;///объявляет карту unique_counts для подсчета уникальных значений в векторе arr.
                                  ///ключи типа string и значения типа int
    

    // Подсчет количества вхождений каждого элемента
    for (const auto& value : arr) { 
        unique_counts[value]++;
    }

    // Замена элементов в векторе на количество их вхождений
    for (int i = 0; i < arr.size(); i++) {     
        arr[i] = to_string(unique_counts[arr[i]]); ///преобразует значение u_c в строку и присваивает элементу arr[i]
    }
}

void runTests() {
    // Тест 1: все элементы одинаковы
    vector<string> test1 = {"Orange", "Orange", "Orange"};
    vector<string> expected1 = {"3", "3", "3"};
    countAndReplace(test1);
    assert(test1==expected1);
    
   
    // Тест 2: все элементы уникальны
    vector<string> test2 = {"Orange", "Red", "Green"};
    vector<string> expected2 = {"1", "1", "1"};
    countAndReplace(test2);
    assert(test2==expected2);
   
    // Тест 3: обычный случай, +- повтор
    vector<string> test3 = {"Orange", "Red", "Green", "Orange"};
    vector<string> expected3 = {"2", "1", "1", "2"};
    countAndReplace(test3);
    assert(test3==expected3);
    
    vector<string> test4 = {};
    vector<string> expected4 = {};
    countAndReplace(test4);
    assert(test4==expected4);
    
    
}

int main() {
    runTests(); 
    return 0;
}

