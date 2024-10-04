#include<iostream>
#include<string>
#include<map>
#include<clocale>

bool check_str(std::string &s) {
    // проверка что в строке только допустимые символы
    // ссылка s весит 1 байт
    for (int i=0; i < s.size() ; i++) {
        // + 4 байта из за цикла
        // функция main использует 4 + k1 + 1 + k2 + 1 = k1 + k2 + 6 байт
        // итого k1 + k2 + 6 + 1 + 4 = k1 + k2 + 11 байт
        if (!(('a' <= s[i]) & (s[i] <= 'z')) & !(('0' <= s[i]) & (s[i] <= '9')) & !(('A' <= s[i]) & (s[i] <= 'Z'))) {
            return false;
        }
    }
    return true;
}

bool are_isomorphic(std::string &s1, std::string &s2) {
    // проверить на изоморфность строки
    // ссылки s1 и s2 весят по 1 байту
    if (s1.size() != s2.size()) {
        // если строки разного размера, то они не изоморфны
        return false;
    }
    // создаем словарь в котором хранится соответствие между символами
    std::map<char, char> accordance; // вычислим вес map по формуле (sizeof(char) + sizeof(char) + sizeof(_Rb_tree_node_base)) * M + sizeof(_Rb_tree)
    // получается (1 + 1 + 24) * M + 64 байта, где M - кол-во уникальных символов в строке, которое не превосходит 62
    for (int i=0; i < s1.size() ; i++) {
        // + 4 байта из за цикла
        if (accordance.find(s1[i]) != accordance.end()) {
            // проверка что символу s1[i] соответствует 1 элемент
            // здесь are_isomorphic использует 2 + (1 + 1 + 24) * M + 64 + 4 + 2= 26*M + 72 байт
            // а main использует 4 + 4 + k1 + 1 + k2 + 1 = k1 + k2 + 10 байт
            // итого 26*M + k1 + k2 + 82 байта
            if (accordance[s1[i]] != s2[i]) {
                return false;
            }
        } else {
            // добавляем соответствие если оно раньше не встречалось
            accordance[s1[i]] = s2[i];
        }
    }
    return true;
}

int main() {
    setlocale(LC_CTYPE, "rus");
    int n=-1; // 4 байта
    std::string input_str1, input_str2; // пустые строки весят по 1 байту
    do {
        // + 4 байта из за цикла
        std::cout << "Введите количество пар строк\n";
        // считываем кол-во пар пока оно не станет положительным
        std::cin >> n;
    } while (n < 1);
    for (int i=0; i < n ; i++) {
        // + 4 байта из за цикла
        do {
            // + 4 байта из за цикла
            std::cout << "Введите 1-ую строку\n";
            // считываем 1-ую строку пока она не будет корректной
            std::cin >> input_str1; // теперь строка весит k1 + 1 байт, где k1 - длина строки
        } while (!check_str(input_str1));
        do {
            // + 4 байта из за цикла
            std::cout << "Введите 2-ую строку\n";
            // считываем 2-ую строку пока она не будет корректной
            std::cin >> input_str2; // теперь строка весит k2 + 1 байт, где k2 - длина строки
        } while (!check_str(input_str2));

        if (are_isomorphic(input_str1, input_str2)) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }
    }
    // на вход 6 + k1 + k2 байт, где k1 и k2 длины строк на i-ой итерации
    // Максимальное число байт достигается в строке 37 и равно 26*M + k1 + k2 + 82 байта, где M - кол-во уникальных символов в строках на i-ой итерации
    return 0;
}
