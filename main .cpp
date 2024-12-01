#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int n;
    int dp[301][301]; // матрица для хранения ранее подсчитанных значений (4 байта * 90601)

    int rec_solve(vector<int>& sp, int i, int j) {
        // точки выхода:
        if (i > j) // i > j не имеет смысла
            return 0;

        if (i == j) { // остался только 1 элемент в промежутке (то, что нам интересно)
            int count = sp[i]; // 4 байта
            if (i - 1 >= 0)
                count *= sp[i - 1];
            if (i + 1 < n)
                count *= sp[i + 1];
            return count;
        }

        if (dp[i][j] != -1) // если искомое значение уже было подсчитано 
            return dp[i][j];

        int res = 0; // сюда будем записывать итоговую сумму, 4 байта

        for (int k = i; k <= j; k++) { // для каждого элемента из промежутка рекурсивно запускаем функцию, считая катый элемент последним удалённым, k = 4 байта
            int count = sp[k]; // здесь будем считать промежуточную сумму
            if (j + 1 < n)
                count *= sp[j + 1];
            if (i - 1 >= 0)
                count *= sp[i - 1];

            count += rec_solve(sp, i, k - 1) + rec_solve(sp, k + 1, j);

            res = max(res, count); // обновляем итоговую сумму
        }
        // находим все возможные промежутки [i, j] - таких всего n^2 / 2 * 2.
        // так мы заполним матрицу dp - повторные подсчеты производиться не будут.      всего k - n штук.  
        // следовательно, итоговая сложность - O(n^2 * n) = O(n^3)
        // по памяти имеем 4 байта * 90604 = 362 416 байт
	    dp[i][j] = res;
        return res;
    }

    int maxCoins(vector<int>& arr) {
        for (int i = 0; i < 301; ++i) { // заполним матрицу -1, чтобы было ясно, что ячейка пуста (незначительные 90601 операция)
            for (int j = 0; j < 301; ++j) {
                dp[i][j] = -1;
            }
        }
        vector<int> narr = { 1 };
        for (int y : arr) {
            narr.push_back(y);
        }
        narr.push_back(1);
        int i = 1;
        int j = narr.size() - 2;
        n = narr.size();
        return rec_solve(narr, i, j);
    }
};
