#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>

bool brackets(std::string& line) 
// создаём функцию, которая возвращает bool и на вход принимает string
{
    try // в этом блоке находится код, который может вызвать исключение (ошибку)
    {
        // создаём переменную для подсчёта открытых скобок
        int opened = 0; // O(1) - операция присваивания
        for (char i : line) // O(N) - каждый символ строки обрабатывается 1 раз
        {
            if (i == '(') // O(1) - проверка на равенство   
            // считаем открытые скобки
            {
                opened++; // O(1)
            }
            else if (i == ')') // O(1) - проверка на равенство
            // если встреттилась закрытая скобка, уменьшаем счётчик на 1
            {
                opened--; // O(1)
            }
            if (opened < 0) // O(1) - сравнение
            // если встретилась закрытая скобка без открытой, выводим ошибку
            {
                throw std::runtime_error("Error: a bracket isn't opened"); // O(1) - создание объекта исключения
            }
        }
        return opened > 0; // O(1) - операция сравнения и возврата
        // если есть незакрытые скобки, возвращаем true
    }
    catch(const std::exception& e) // O(1) - вывод сообщения об ошибке
    // обработка исключений, которые возникли в блоке try
    {
        std::cerr << e.what() << std::endl; // вывод сообщения об ошибке
        return false;
    }
}


void test1() // скобки открыты
{
    std::string str = "a(b)(((a)b)";
    bool ans = brackets(str);
    if (ans == true) {
        std::cout << "Test 1 passed" << std::endl;
    } else {
        std::cout << "Test 1 FAILED" << std::endl;
    }
}


void test2() // скобки закрыты
{
    std::string str = "a((b)(())(a)b)";
    bool ans = brackets(str);
    if (ans == false) {
        std::cout << "Test 2 passed" << std::endl;
    } else {
        std::cout << "Test 2 FAILED" << std::endl;
    }
}

void test3() // скобки без других символов
{
    std::string str = "((((((())(()))";
    bool ans = brackets(str);
    if (ans == true)
    {
        std::cout << "Test 3 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 3 FAILED" << std::endl;
    }
}

void test_dataset(const std::string &filename)
{
    // создаём объект file, который открывает файл с именем, указанным в параметре filename
    std::ifstream file(filename);
    // выводим ошибку, если не удалось открыть файл
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    std::string line;
    // читаем file построчно, строка сохраняется в line
    while (std::getline(file, line))
    {
        bool ans = brackets(line);
        if (ans == false)
        {
            std::cout << "Test with dataset passed!" << std::endl;
        }
        else
        {
            std::cout << "Test with dataset failed" << std::endl;
        }
    }

    file.close();
}

int main()
{
    test1();
    test2();
    test3();
    test_dataset("dataset.txt");
    return 0;
}