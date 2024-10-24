#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <stack>

bool brackets(const std::string& line) {
    try
    {
        std::stack <char> queue; // O(1) - выделяем память, стек пока пустой
        for (const char i: line) { // O(N), N - длина строки
            if ((i == '(') || (i == '[') ||  (i == '{')) { // O(1), проверяем, является ли символ открывающей скобкой
                queue.push(i); // O(1) - добавляем скобку
            }
            if ((i == ')') || (i == ']') || (i == '}')) { // O(1)
                if (queue.empty()) { // O(1) - если очередь пустая, значит, закрывающая скобка без соответствующей открывающей
                    throw std::runtime_error("Error: a bracket isn't opened"); // O(1)
                }
                char opened_bracket = queue.top(); // O(1), cмотрим на последнюю добавленную открывающую скобку
                queue.pop(); // O(1) - удаляем её из очереди
                if ((i == ')' && opened_bracket != '(') || (i == ']' && opened_bracket != '[') || (i == '}' && opened_bracket != '{')) //O (1)
                {
                    return true; // если не соответствует, возвращаем false
                }
            }
        }
        return !queue.empty(); // O(1), если очередь пустая, значит, все скобки закрыты
    }
    
    catch (const std::exception &e)
    // обработка исключений, которые возникли в блоке try
    {
        std::cerr << e.what() << std::endl; // O(1) - обработка исключений вывод сообщения об ошибке
        return false;
    }
}
// всего: O(1 + N + 1 + 1 + 1 + ... + 1) = O(N)

void test1() // скобки открыты
{
    std::string str = "a(b)(([a]b)";
    bool ans = brackets(str);
    if (ans == true) {
        std::cout << "Test 1 passed" << std::endl;
    } else {
        std::cout << "Test 1 FAILED" << std::endl;
    }
}

void test2() // скобки закрыты
{
    std::string str = "a[(b)]())({a})b)";
    bool ans = brackets(str);
    if (ans == false) {
        std::cout << "Test 2 passed" << std::endl;
    } else {
        std::cout << "Test 2 FAILED" << std::endl;
    }
}

void test3() // скобки без других символов
{
    std::string str = "{[{}()()(){{}()()]}";
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

void test_dataset(const std::string& filename)
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
            std::cout << "Test with dataset passed" << std::endl;
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