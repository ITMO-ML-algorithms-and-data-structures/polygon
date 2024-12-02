#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функция для нахождения длины самой длинной действительной подстроки скобок
int longestValidParentheses(const string& s) {
    int n = s.size();
    if (n == 0) return 0;

    vector<int> dp(n, 0);
    int maxLength = 0;

    // Проходим по строке, начиная со второго символа
    for (int i = 1; i < n; ++i) {
        // Проверяем, является ли текущий символ закрывающей скобкой
        if (s[i] == ')') {
            // Если предыдущий символ - открывающая скобка
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2; // Увеличиваем длину на 2
            } 
            // Если предыдущая скобка закрывающая и есть открывающая перед ней
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + (i >= 2 + dp[i - 1] ? dp[i - 2 - dp[i - 1]] : 0) + 2; // Увеличиваем длину на длину предыдущей действительной подстроки плюс 2
            }
            // Обновляем максимальную длину, если текущая больше
            maxLength = max(maxLength, dp[i]);
        }
    }

    return maxLength;
}

int main() {
    string s = "(())(())";

    int result = longestValidParentheses(s);
    cout << "Длина самой длинной действительной подстроки: " << result << endl;

    return 0;
}
