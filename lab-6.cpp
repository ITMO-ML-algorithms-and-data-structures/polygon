#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string inputString) {
        int stringLength = inputString.size(); // 4 байта
        if (stringLength == 0) return 0;

        // dp[i] хранит длину самой длинной валидной подстроки, заканчивающейся на позиции i
        vector<int> dp(stringLength, 0); // 24 байт + size * 4 байт
        int maxValidLength = 0; // 4 байта

        for (int currentIndex = 1; currentIndex < stringLength; ++currentIndex) { // O(n)
            if (inputString[currentIndex] == ')') { // Обрабатываем только закрывающие скобки
                if (inputString[currentIndex - 1] == '(') {
                    // Если пара "()", добавляем 2 к dp[currentIndex-2]
                    dp[currentIndex] = (currentIndex >= 2 ? dp[currentIndex - 2] : 0) + 2;
                } else if (currentIndex - dp[currentIndex - 1] - 1 >= 0 &&
                           inputString[currentIndex - dp[currentIndex - 1] - 1] == '(') {
                    // Если пара "...(...)", добавляем 2 к предыдущему валидному dp
                    int additionalLength;
                    if (currentIndex - dp[currentIndex - 1] - 2 >= 0) {
                        additionalLength = dp[currentIndex - dp[currentIndex - 1] - 2];
                    } else {
                        additionalLength = 0;
                    }
                    dp[currentIndex] = dp[currentIndex - 1] + additionalLength + 2;
                }
                // Обновляем максимальную длину
                maxValidLength = max(maxValidLength, dp[currentIndex]);
            }
        }

        return maxValidLength;
    }
};

int main() {
    Solution solution;

    string input = "(()";
    cout <<  solution.longestValidParentheses(input) << endl;

    return 0;
}

