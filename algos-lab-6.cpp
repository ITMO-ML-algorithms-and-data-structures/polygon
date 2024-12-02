#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();  // Длина строки
        int n = p.size();  // Длина паттерна
        
        // Создаем таблицу DP размером (m+1) x (n+1)
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Базовый случай: пустая строка и пустой паттерн совпадают
        dp[0][0] = true;

        // Заполняем таблицу для случаев, когда паттерн может соответствовать пустой строке
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2]; // '*' может соответствовать нулю символов
            }
        }

        // Заполняем таблицу DP
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == s[i-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1]; // Символы совпали или точка соответствует любому символу
                } else if (p[j-1] == '*') {
                    // Обработка случая с '*': оно может соответствовать нулю или более повторений предыдущего символа
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
            }
        }

        // Ответ находится в ячейке dp[m][n]
        return dp[m][n];
    }
};

int main() {
    Solution sol;

    // Пример 1
    string s1 = "aa";
    string p1 = "a";
    cout << sol.isMatch(s1, p1) << endl; // Ожидаемый вывод: false

    // Пример 2
    string s2 = "aa";
    string p2 = "a*";
    cout << sol.isMatch(s2, p2) << endl; // Ожидаемый вывод: true

    // Пример 3
    string s3 = "ab";
    string p3 = ".*";
    cout << sol.isMatch(s3, p3) << endl; // Ожидаемый вывод: true

    return 0;
}
