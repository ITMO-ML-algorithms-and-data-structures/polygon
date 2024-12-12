#include <iostream>
#include <string>


bool isMatch(const std::string& s, const std::string& p) {
    int sLen = s.length();
    int pLen = p.length();
    
    int sIndex = 0, pIndex = 0;
    int starIndex = -1, matchIndex = -1;

    while (sIndex < sLen) {
        // Если символы совпадают или есть '?'
        if (pIndex < pLen && (s[sIndex] == p[pIndex] || p[pIndex] == '?')) {
            sIndex++;
            pIndex++;
        }
        // Если встречаем '*', запоминаем текущее положение
        else if (pIndex < pLen && p[pIndex] == '*') {
            starIndex = pIndex;       // запоминаем позицию '*'
            matchIndex = sIndex;      // запоминаем позицию строки
            pIndex++;                 // переходим к следующему символу шаблона
        }
        // Если символы не совпадают, но есть предыдущее '*'
        else if (starIndex != -1) {
            pIndex = starIndex + 1;  // возвращаемся к '*' в шаблоне
            sIndex = ++matchIndex;    // увеличиваем позицию в строке
        }
        // Если ничего не подходит, возвращаем false
        else {
            return false;
        }
    }

    // Проверяем оставшиеся символы в шаблоне
    while (pIndex < pLen && p[pIndex] == '*') {
        pIndex++;
    }
    
    // Проверяем на соответствие, если шаблон полностью обработан
    return pIndex == pLen;
}

int main() {
    std::string s, p;
    std::cout << "Enter the string: ";
    std::cin >> s;
    std::cout << "Enter the pattern: ";
    std::cin >> p;

    if (isMatch(s, p)) {
        std::cout << "Match!" << std::endl;
    } else {
        std::cout << "Doesn't match." << std::endl;
    }

    return 0;
}