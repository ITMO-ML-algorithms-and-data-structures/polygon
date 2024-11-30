#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(); // 4 байта
    int n = dungeon[0].size(); // 4 байта

    // dp массив для минимального здоровья рыцаря
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX)); // O(m * n) m*n*4 байт
    
    // заполняем клетку с принцессой
    dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
    
    // Заполняем таблицу снизу вверх
    for (int i = m - 1; i >= 0; --i) { // Сложность O(m * n) // 4 байт + 4 байт для i j
        for (int j = n - 1; j >= 0; --j) {
            if (i < m - 1) {
                dp[i][j] = min(dp[i][j], max(1, dp[i + 1][j] - dungeon[i][j]));
            }
            if (j < n - 1) {
                dp[i][j] = min(dp[i][j], max(1, dp[i][j + 1] - dungeon[i][j]));
            }
        }
    }
    
    return dp[0][0];
}
// Всего памяти 4*m*n + 4*m*n + 16 = 8 * m * n + 16 байт
int main() {
    vector<vector<int>> dungeon = { // 4*m*n байт
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    
    cout << calculateMinimumHP(dungeon) << endl;
    return 0;
}

};