#include <iostream>
using namespace std;
// // короче как на егэ забубенить и найти минимальный в матрице
// int main () {
//     читаем матрицу
//     делааем как матрицу
//     тут минимум задаем
//     тут тупым циклом переделываем
//     тут ответ выводим
//     // надеюс
//     return 0;


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int size_n = dungeon.size();
        int size_m = dungeon[0].size();
        // будем считать необходимое хп обратным проходом, короче как в егэ
        vector<vector<int>> dp(size_n + 1, vector<int>(size_m + 1, INT_MAX));
		dp[size_n - 1][size_m] = 1;
        dp[size_n][size_m - 1] = 1;
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
