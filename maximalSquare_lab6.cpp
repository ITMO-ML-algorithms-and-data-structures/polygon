#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) 
        return 0;

        int m = matrix.size(); // 4 байта
        int n = matrix[0].size(); // 4 байта
        vector<vector<int>> dp(m, vector<int>(n, 0)); // m*n байт, где m- количество строк в матрице n- количество столбцов
        int maxSide = 0; // Максимальная длина стороны найденного квадрата, 4 байта

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    // Если находимся в первой строке или первом столбце
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // Квадрат 1x1
                    } else {
                        // Заполняем dp[i][j] как минимум из трех соседних квадратов
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    // Обновляем максимальную сторону квадрата
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        // Площадь максимального квадрата
        return maxSide * maxSide;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> matrix = {
        {'0', '1', '1', '0'},
        {'1', '1', '1', '1'},
        {'0', '1', '1', '1'},
        {'0', '0', '0', '0'}
    };

    int result = solution.maximalSquare(matrix);
    cout << "The largest square containing only 1: " << result << endl;

    return 0;
}

// подсчет памяти: 4 + 4 + 4 + m*n = 12 + m*n, где m- количество строк в матрице n- количество столбцов

// временаая сложность: O(m*n),где m- количество строк в матрице n- количество столбцов
// пространственная сложность: O(m*n),где m- количество строк в матрице n- количество столбцов

// в данной задаче эффективно испльзовать ДП, 
// чтобы  вместо многократного перебора подматриц, проходить по всей матрице один раз, используя информацию из предыдущей строки и столбца для обновления текущего состояния