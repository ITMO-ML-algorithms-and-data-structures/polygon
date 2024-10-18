#include <iostream>
#include <string>
#include <array>
#include <unordered_map>

int IsIsomorph(std::string str1, std::string str2)
{
    // создаём саму функцию проверки изоморфности двух строк

    std::unordered_map<char, char> map;
    // объявляем хэш таблицу, с помощью которой будем сравнивать символы

    if (std::size(str1) != std::size(str2)) { return 2; }
    // проверка соответствия длин строк друг другу, при несоответствии возвращается 2

    for (int i = 0; i < std::size(str1); i++)
    {
        char a = str1[i]; char b = str2[i]; // 1 байт каждая = 2 байта
        // конвертируем для удобности каждый символ строки в char

        if ((map.count(b) == 0 and map.count(a) == 1) or
            (map.count(b) == 1 and map.count(a) == 0)) {
            return 0;
        } // проверка существования символов в хэш таблице

        else if (map.count(b) == 0 and map.count(a) == 0)
        {
            map[b] = a; map[a] = b;
        } // если ещё не существуют оба символа, то мы создаём их 
          // и соответствие друг другу в хэш таблице

        else if (map[b] != a or map[a] != b) { return 0; }
        // проверка соответствия двух символов по хэш таблице
    }
    
    std::cout << "Memory usage of map = " << sizeof(map) << " bytes " << std::endl;
    // вывод используемой памяти хэш-таблицей

    return 1;
    // если всё хорошо и все проверки пройдены, возвращаем 1
}

void test() // тест
{
    short int i = 0;

    {
        std::string str1 = "egg";
        std::string str2 = "add";
        i += IsIsomorph(str1, str2) == 1;
    }
    {
        std::string str1 = "cherry";
        std::string str2 = "pie";
        i += IsIsomorph(str1, str2) == 2;
    }
    {
        std::string str1 = "foo";
        std::string str2 = "bar";
        i += IsIsomorph(str1, str2) == 0;
    }
    {
        std::string str1 = "sas";
        std::string str2 = "bas";
        i += IsIsomorph(str1, str2) == 0;
    }
    std::cout << i << " tests passed of " << 4 << std::endl;
}

int main()
{
    test(); // выводим итоги теста

    std::string str1, str2;
    
    std::cout << "str1: ";
    std::cin >> str1;
    std::cout << "str2: ";
    std::cin >> str2;
    // получаем 2 строки

    std::cout << "Memory usage of str1 = " << sizeof(str1) << " bytes" << std::endl;
    std::cout << "Memory usage of str2 = " << sizeof(str2) << " bytes" << std::endl;
    
    return IsIsomorph(str1, str2);
    // выводим итог функции
}
