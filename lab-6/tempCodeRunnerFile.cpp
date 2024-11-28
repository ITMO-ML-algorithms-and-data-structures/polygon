#include <iostream>
#include <string>

bool isSubsequence(const std::string& s, const std::string& t) {
    int sIndex = 0; // Указатель для строки s
    int tIndex = 0; // Указатель для строки t

    // Проходим по строке t
    while (tIndex < t.length() && sIndex < s.length()) {
        // Если символы совпадают, перемещаем указатель s
        if (t[tIndex] == s[sIndex]) {
            sIndex++;
        }
        // Всегда перемещаем указатель t
        tIndex++;
    }

    // Если указатель s достиг конца, значит s является подпоследовательностью t
    return sIndex == s.length();
}

int main() {
    // Пример 1
    std::string s1 = "abc";
    std::string t1 = "ahbgdc";
    std::cout << "Результат (пример 1): " << (isSubsequence(s1, t1) ? "true" : "false") << std::endl; // Вывод: true

    // Пример 2
    std::string s2 = "axc";
    std::string t2 = "ahbgdc";
    std::cout << "Результат (пример 2): " << (isSubsequence(s2, t2) ? "true" : "false") << std::endl; // Вывод: false

    return 0;
}