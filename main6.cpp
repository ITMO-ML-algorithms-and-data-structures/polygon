#include <iostream>
#include <vector>
#include <algorithm>

// using namespace std;


int dfs(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& dp, int row, int col, int prev_val) {
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[row][col] <= prev_val) {
        return 0;
    }
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    int cur_value = matrix[row][col];
    int left = dfs(matrix, dp, row, col - 1, cur_value);
    int right = dfs(matrix, dp, row, col + 1, cur_value);
    int up = dfs(matrix, dp, row - 1, col, cur_value);
    int down = dfs(matrix, dp, row + 1, col, cur_value);
    dp[row][col] = 1 + std::max({left, right, up, down});
    return dp[row][col];
}

int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, -1));
    int max_path = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            max_path = std::max(max_path, dfs(matrix, dp, i, j, -1));
        }
    }
    return max_path;
}


void test() {
    std::vector<std::vector<int>> arr = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    if (longestIncreasingPath(arr) == 4) {
        std::cout << "OK\n";
    } else {
        std::cout << "Test Failed\n";
    }
    arr = {{3, 4, 5} ,{3, 2, 6}, {2, 2, 1}};
    if (longestIncreasingPath(arr) == 4) {
        std::cout << "OK\n";
    } else {
        std::cout << "Test Failed\n";
    }

}


int main() {
    test();
    std::vector<std::vector<int>> arr = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    std::cout << longestIncreasingPath(arr);
    return 0;
}

