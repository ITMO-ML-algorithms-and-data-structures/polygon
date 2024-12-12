#include <iostream>
#include <string>
using namespace std;

bool isMatch(string input_string, string pattern) { // 32 байта 32 байта
    int string_len = input_string.length(), pattern_len = pattern.length(); // 4 байта 4 байта
    int string_ind = 0, pattern_ind = 0; // Указатели для строки и шаблона // 4 байта 4 байта
    int last_star_idx = -1;        // Последняя позиция символа '*' в шаблоне // 4 байта
    int match = 0;            // Позиция в строке, соответствующая '*' // 4 байта

    // O(n)
    while (string_ind < string_len) {
        // Случай 1: Совпадают символы или в шаблоне '?'
        if (pattern_ind < pattern_len && (pattern[pattern_ind] == input_string[string_ind] || pattern[pattern_ind] == '?')) {
            string_ind++;
            pattern_ind++;
        }
            // Случай 2: Символ '*' в шаблоне
        else if (pattern_ind < pattern_len && pattern[pattern_ind] == '*') {
            last_star_idx = pattern_ind; // Запоминаем позицию '*'
            match = string_ind;    // Запоминаем текущую позицию строки
            pattern_ind++;
        }
            // Случай 3: Несовпадение, но ранее встречался '*'
        else if (last_star_idx != -1) {
            pattern_ind = last_star_idx + 1; // Возвращаем указатель шаблона к '*'
            match++;              // Пробуем следующий символ строки
            string_ind = match;
        }
            // Случай 4: Полное несовпадение
        else {
            return false;
        }
    }

    // Проверяем оставшиеся символы в шаблоне
    // O(m) m длина шаблона
    while (pattern_ind < pattern_len && pattern[pattern_ind] == '*') {
        pattern_ind++;
    }

    if (pattern_ind != pattern_len) return false;
    else return true;
}

void Test() {
    int test_sizes[] = {1, 5, 10, 50, 100, 200, 300, 400, 500};

    for (int size : test_sizes) {
        string test_string(size, 'a'); // строка из 'a' длиной size
        string test_pattern(size, 'a'); // шаблон из 'a' длиной size

        auto start = chrono::high_resolution_clock::now();
        bool result = isMatch(test_string, test_pattern);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;

        cout << "Size: " << size
             << ", Result: " << (result ? "Matched" : "Not Matched")
             << ", Time: " << elapsed.count() << " seconds" << endl;
    }
}

int main() {
    Test();
    string s = "aa", p = "a";
    cout << isMatch(s, p);
    return 0;
}