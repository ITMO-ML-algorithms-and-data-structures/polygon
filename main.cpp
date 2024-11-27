#include <iostream>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int size_n = dungeon.size(); // память равна размеру типа числа N и M
        int size_m = dungeon[0].size(); // т.е N+M = O(1)
        // будем считать необходимое хп обратным проходом, короче как в егэ
        // Память (N + 1) * (M + 1) * (тип данныХ) = O(N * M)
        vector<vector<int> > dp(size_n + 1, vector<int>(size_m + 1, INT_MAX));
        dp[size_n - 1][size_m] = 1;
        dp[size_n][size_m - 1] = 1;
        // Время N * M = O(N*M)
        for (int i = size_n - 1; i >= 0; i--) {
            for (int j = size_m - 1; j >= 0; j--) {
                int hp = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                if (hp <= 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = hp;
                }
            }
        }
        return dp[0][0];
    }
};
// итоговая память и время O(N*M)