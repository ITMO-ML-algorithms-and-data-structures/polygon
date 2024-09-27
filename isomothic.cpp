#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <cassert>

// Определить являются ли 2 строки изоморфными
// Функция возвращает true - если строки изоморфны, false - нет

bool isIsomorphic(const std::string &string1, const std::string &string2) { // передаем строчки по ссылке, значит не создаем их
    // Если длины не равны, значит строки не изоморфны
    if (string1.length() != string2.length()) {
        return false;
    }

    // Оценка памяти для хеш-таблиц:
    // map_s1_to_s2: (1 * M + 8 * N) * N байта (M - количество уникальных ключей, N - количество уникальных символов)
    // map_s2_to_s1: (1 * M + 8 * N) * N байта (M - количество уникальных ключей, N - количество уникальных символов)
    // Для двух: (M*N + 8 * N^2) * 2 байта
    std::unordered_map<char, int> map_s1_to_s2; // Сопоставления индексов из string1 в string2
    std::unordered_map<char, int> map_s2_to_s1; // Сопоставления индексов из string2 в string1

    // Проходим по каждому символу строки для сравнения индексов элементов
    for (int i = 0; i < string1.length(); i++) { // 4 байта (локальная)
        char symbol1 = string1[i]; // 1 байт (локальная)
        char symbol2 = string2[i]; // 1 байт (локальная)

        // Проверяем, есть ли уже сопоставление для symbol1:
        if (map_s1_to_s2.count(symbol1)) {
            // Если есть, проверяем, соответствует ли оно symbol2
            if (map_s1_to_s2[symbol1] != symbol2) {
                return false;
            }
        } else {
            // Проверяем, есть ли уже сопоставление для symbol2:
            if (map_s2_to_s1.count(symbol2)) {
                return false;
            }
            // Добавляем соответствие, если проверки пройдены
            map_s1_to_s2[symbol1] = symbol2;
            map_s2_to_s1[symbol2] = symbol1;
        }
    }

    return true;
}

// Функция для тестирования
void Tests() {
    assert(isIsomorphic("egg", "add") == true);
    assert(isIsomorphic("foo", "bar") == false);
    assert(isIsomorphic("paper", "title") == true);
    assert(isIsomorphic("123", "321") == true);
    assert(isIsomorphic("1234567890", "0987654321") == true);
    assert(isIsomorphic("123123", "321321") == true);
    assert(isIsomorphic("abc", "xyz") == true);
    assert(isIsomorphic("ab", "aa") == false);
    assert(isIsomorphic("abab", "cdcd") == true);
    assert(isIsomorphic("abab", "cddc") == false);
    assert(isIsomorphic("paperpaperpaper", "paperpaperpaper") == true);
    assert(isIsomorphic("appleapple", "alivealive") == false);
    assert(isIsomorphic("AbnerAbner", "AbneyAbney") == true);
    assert(isIsomorphic("egg1234567890", "add0987654321") == true);
    assert(isIsomorphic("foo1234567890", "bar0987654321") == false);
    assert(isIsomorphic("abcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdea",
                        "bcdefbcdefbcdefbcdefbcdefbcdefbcdefbcdefbcdefb") == true);
    assert(isIsomorphic("12345678901234567890123456789012345678901234567890",
                        "09876543210987654321098765432109876543210987654321") == true);
    std::cout << "All tests passed!\n";
}

int main() {
    Tests();

    // Открываем файл с данными
    std::ifstream inputFile("C:\\ITMO-ML-algorithms-and-data-structures\\polygon\\input.txt");
    std::ofstream outputFile("C:\\ITMO-ML-algorithms-and-data-structures\\polygon\\output.txt");

    // Оценка памяти для строк:
    // str1 и str2: 32 * 2 байта = 64 байта для двух строк
    std::string str1, str2; // 32 * 2 байта = 64 для двух строк

    // В цикле мы читаем строки из файла и проверяем их на изоморфизм
    while (std::getline(inputFile, str1, ' ') && std::getline(inputFile, str2)) {
        if (isIsomorphic(str1, str2)) {
            outputFile << "true\n";
        } else {
            outputFile << "false\n";
        }
    }

    inputFile.close();
    outputFile.close();

    // Общая оценка использования памяти:
    // В функции isIsomorphic: (M*N + 8 * N^2) * 2 байта для хранения хэш-таблиц, где M - ключи, N - значения
    // Локальные переменные : 4 + 1 + 1 = 6 байт
    // В main: 64 байта (память для str1 и str2)
    // Общая память:  (M*N + 8 * N^2) * 2 + 64 байта
    return 0;
}
