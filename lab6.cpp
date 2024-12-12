#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(); // количество строк
    int n = dungeon[0].size(); // количество столбцов

    // создаем двумерный массив для хранения минимального здоровья
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Начинаем с клетки, где находится принцесса
    dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]); // минимальное здоровье для последней клетки

    // Заполняем последнюю строку (движемся влево)
    for (int j = n - 2; j >= 0; j--) {
        dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
    }

    // Заполняем последний столбец (движемся вверх)
    for (int i = m - 2; i >= 0; i--) {
        dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
    }

    // Заполняем остальную часть массива dp
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            // Минимальное здоровье для текущей клетки
            int minHealthOnExit = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(1, minHealthOnExit - dungeon[i][j]);
        }
    }

    // Возвращаем минимальное здоровье для входа в первую клетку
    return dp[0][0];
}

int main() {
    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    cout << "The minimum initial health of a knight: " << calculateMinimumHP(dungeon) << endl;
    return 0;
}