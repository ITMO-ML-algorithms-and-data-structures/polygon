#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSubsequence(string s, string t) {
    int m = s.size();
    int n = t.size();

    // Матрица dp, где dp[i][j] указывает, является ли s[0..i-1] подпоследовательностью t[0..j-1]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Пустая строка s всегда является подпоследовательностью любой строки t
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = true;
    }

    // Заполнение матрицы dp
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                // Если текущие символы совпадают, берем результат для dp[i-1][j-1]
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Иначе результат берется из dp[i][j-1]
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "abc", t1 = "ahbgdc";
    string s2 = "axc", t2 = "ahbgdc";

    cout << (isSubsequence(s1, t1) ? "true" : "false") << endl; // true
    cout << (isSubsequence(s2, t2) ? "true" : "false") << endl; // false

    return 0;
}