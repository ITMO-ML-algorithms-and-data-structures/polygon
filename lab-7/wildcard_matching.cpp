#include <iostream>
#include <string>
#include <chrono>


bool isMatch(const std::string& s, const std::string& p) {
    int sLen = s.length();
    int pLen = p.length();
    
    int sIndex = 0, pIndex = 0;
    int starIndex = -1, matchIndex = -1;

    while (sIndex < sLen) { // проход по символам строки - O(N), где N - длина строки
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
    while (pIndex < pLen && p[pIndex] == '*') { // проход по оставщимся символам шаблона - O(M) в худшем случае, где M - длина шаблона
        pIndex++;
    }
    
    // Проверяем на соответствие, если шаблон полностью обработан
    return pIndex == pLen;

    // Итоговая сложность:
    // О(N) + O(M) = O(N + M)
}

int main() {
    struct Test {
        std::string s;
        std::string p;
        bool expected;
    };

    Test tests[] = {
        {"a", "a", true},                        // Длина 1
        {"ab", "ab", true},                      // Длина 2
        {"abc", "a?c", true},                   // Длина 3
        {"abcd", "a*d", true},                  // Длина 4
        {"abcde", "a*e", true},                 // Длина 5
        {"abcdef", "a?c?e", true},               // Длина 6
        {"abcdefg", "*defg", true},             // Длина 7
        {"abcdefgh", "a*d?f?h", true},          // Длина 8
        {"abcdefghi", "abcdefgh*", true},       // Длина 9
        {"abcdefghij", "a?c*g?i?j", true},     // Длина 10
        {"abcdefghijk", "a*b*c*d*e*k", true},  // Длина 11
        {"abcdefghijkl", "a*c*e*g*i*k", true}, // Длина 12
        {"abcdefghijklm", "a?c?e*i*m", true},  // Длина 13
        {"abcdefghijklmn", "a*e*n", true},     // Длина 14
        {"abcdefghijklmno", "abc*efg*", true}, // Длина 15
        {"abcdefghijklmnop", "a*d*?g", true},  // Длина 16
        {"abcdefghijklmnopq", "ab?c*e*i*k*q", true}, // Длина 17
        {"abcdefghijklmnopqr", "a*?k*r", true}, // Длина 18
        {"abcdefghijklmnopqrs", "a*e*?g*s", true}, // Длина 19
        {"abcdefghijklmnopqrst", "a?b*c*e?g*h*i*b*t", true}, // Длина 20
        {"abcdefghijklmnopqrstu", "abcdef*g*?", true}, // Длина 21
        {"abcdefghijklmnopqrstuv", "ab*c*d*?u", true}, // Длина 22
        {"abcdefghijklmnopqrstuvw", "ab*cd*?w", true}, // Длина 23
        {"abcdefghijklmnopqrstuvwx", "a*b*c*d*?x", true}, // Длина 24
        {"abcdefghijklmnopqrstuvwxy", "?bcdefgh?j?y", true}, // Длина 25
        {"abcdefghijklmnopqrstuvwxyz", "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z", true}, // Длина 26
        {"abcdefghijklmnopqrstuvwxyzabc", "a*?c*e*?a", true}, // Длина 27
        {"abcdefghijklmnopqrstuvwxyzabcd", "ab?*cd", true}, // Длина 28
        {"abcdefghijklmnopqrstuvwxyzabcde", "abc*d?e", true}, // Длина 29
        {"abcdefghijklmnopqrstuvwxyzabcdef", "abcdef*g*e", true}, // Длина 30
        {"abcdefghijklmnopqrstuvwxyzabcdefg", "abcde?g", true}, // Длина 31
        {"abcdefghijklmnopqrstuvwxyzabcdefgh", "abcd*hi*", true}, // Длина 32
        {"abcdefghijklmnopqrstuvwxyzabcdefghi", "abcdefgh?i", true}, // Длина 33
        {"abcdefghijklmnopqrstuvwxyzabcdefghij", "a?c*e*g*i*j", true}, // Длина 34
        {"abcdefghijklmnopqrstuvwxyzabcdefghijk", "a?c?g*h*j*k", true}, // Длина 35
        {"abcdefghijklmnopqrstuvwxyzabcdefghijkl", "a*e*c*?k*?", true}, // Длина 36
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklm", "ab*?e*g*", true}, // Длина 37
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmn", "aaaa*?b*?m", true}, // Длина 38
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmno", "abcd*?g*n", true}, // Длина 39
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnop", "a?bc*?f*mnop", true}, // Длина 40
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopq", "abcdefg?*q", true}, // Длина 41
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr", "abcd*f*g?j", true}, // Длина 42
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrs", "ab?*g*?" , true}, // Длина 43
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst", "a*b*c*d*?t", true}, // Длина 44
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv", "a?b*c*d*u", true}, // Длина 45
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvw", "abcd*?w?v", true}, // Длина 46
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx", "*xyz", true},  // Длина 47
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy", "abc*d*?y", true}, // Длина 48
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", "abc*dv*gh*o*?", true}, // Длина 49
        {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz0", "abcdefghijklmnopqrstuvwxyz*", true} // Длина 50
    };

    for (const auto& test : tests) {
        auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта

        bool result = isMatch(test.s, test.p);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;

        // std::cout << "Тест: s = \"" << test.s << "\", p = \"" << test.p << "\" - "
        //           << (result == test.expected ? "Совпадает!" : "Не совпадает.") << std::endl;

        // std::cout << duration.count() << std::endl;

        std::cout << test.p.length() << std::endl;
    }

    return 0;
}