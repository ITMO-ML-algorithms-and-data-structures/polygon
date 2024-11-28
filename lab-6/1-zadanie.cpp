#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Если количество ступенек меньше 3, результат равен n (1 или 2 способа)
        if (n <= 2) {
            return n;
        }

        // dp[i] хранит количество способов добраться до i-й ступеньки
        vector<int> dp(n + 1, 0);

        // Базовые случаи
        dp[1] = 1; // 1 способ на 1 ступеньку
        dp[2] = 2; // 2 способа на 2 ступеньки

        // Заполняем массив dp
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main(int argc, char *argv[]) {
    Solution solution; // Создаем экземпляр класса Solution
    int n1 = 2, n2 = 3;

    cout << solution.climbStairs(n1) << endl; // 2
    cout << solution.climbStairs(n2) << endl; // 3

    return 0;
}