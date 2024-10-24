#include <iostream>
#include <string>
#include <cassert>

// Функция для определеня, закрыты ли скобки в строке
int bracket_chek(std::string& arr) {
    int count_op = 0; // Счетчик открывающих скобок
    int count_cl = 0; // Счетчик закрывающих скобок
    
    // Цикл для поиска скобок
    for (int num = 0; num < arr.length(); num++) { // O(N) - где N это длина строки
        if (arr[num] == '(') { // O(1) – доступ по индексу и сравнение
            count_op++;
        } else if (arr[num] == ')'){ // O(1) – доступ по индексу и сравнение
            count_cl++;
        }
    }  
    // Есть ли отрытые скобки?
    if (count_op == count_cl) {  // O(1) – сравнение
        return false;
    }
    return true;

    // Общая сложность алгоритма составляет O(N)
}


void test() {
    // Базовые случаи
    {   
        std::string test = "a(b)(((a)b)";
        assert(bracket_chek(test) == true);
    }
    {   
        std::string test = "a(b)(((a))b)";
        assert(bracket_chek(test) == false);
    }
    // Только открые и закрытые скобки
    {   
        std::string test = "((((";
        assert(bracket_chek(test) == true);
    }
    {   
        std::string test = "))))";
        assert(bracket_chek(test) == true);
    }
        
    // Большое количество скобок
    {   
        std::string test = "(()()())";
        assert(bracket_chek(test) == false);
    }
    {   
        std::string test = "(((())))";
        assert(bracket_chek(test) == false);
    }

    // Без скобок
    {   
        std::string test = "";
        assert(bracket_chek(test) == false);
    }
    
    // Только символы
    {   
        std::string test = "abcabc";
        assert(bracket_chek(test) == false);
    }

    // Симбиоз
    {   
        std::string test = "((a*b) + c";
        assert(bracket_chek(test) == true);
    }
    {   
        std::string test = "(a * b)^2";
        assert(bracket_chek(test) == false);
    }
    std::cout << "Все тесты прошли успешно";
}

int main() {
    test();
}