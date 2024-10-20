#include <iostream>
#include <string>
#include <array>
#include <unordered_map>

int IsIsomorph(const std::string str1, const std::string str2) // + 80 байт
{
    // создаём саму функцию проверки изоморфности двух строк

    std::unordered_map<char, char> map; // 0 байт, пока не используется
    // объявляем хэш таблицу, с помощью которой будем сравнивать символы

    if (std::size(str1) != std::size(str2) or std::size(str1) == 0) { return 2; }
    // проверка соответствия длин строк друг другу, при несоответствии возвращается 2

    for (int i = 0; i < std::size(str1); i++) // +4 байта
    {
        char a = str1[i]; char b = str2[i]; // + 2 * i байта
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

    return 1;
    // если всё хорошо и все проверки пройдены, возвращаем 1
}

void test() // тест
{
    short int i = 0; // + 2 байта
    {
        std::string str1 = ""; // + 40 байт
        std::string str2 = ""; // + 40 байт
        i += IsIsomorph(str1, str2) == 2;
    }
    {
        std::string str1 = "egg"; // + 40 байт
        std::string str2 = "add"; // + 40 байт
        i += IsIsomorph(str1, str2) == 1;
    }
    {
        std::string str1 = "cherry"; // + 40 байт
        std::string str2 = "pie"; // + 40 байт
        i += IsIsomorph(str1, str2) == 2;
    }
    {
        std::string str1 = "foo"; // + 40 байт
        std::string str2 = "bar"; // + 40 байт
        i += IsIsomorph(str1, str2) == 0;
    }
    {
        std::string str1 = "sas"; // + 40 байт
        std::string str2 = "bas"; // + 40 байт
        i += IsIsomorph(str1, str2) == 0;
    }
    std::cout << i << " tests passed of " << 5 << std::endl;
}

int main()
{
    test(); // выводим итоги теста

    std::string str1, str2; // + 80 байт
    
    std::cout << "str1: ";
    std::cin >> str1;
    std::cout << "str2: ";
    std::cin >> str2;
    // получаем 2 строки
    
    return IsIsomorph(str1, str2);
    // выводим итог функции
}

// Итого памяти занято: 40 * 2 * 5 (тесты) + 80 (str1 и str2) + 
// + 2 (short) + 4 (i) + 2 * i (char) + 80 байт (str1 и str2) = 566 + 2 * i байта
