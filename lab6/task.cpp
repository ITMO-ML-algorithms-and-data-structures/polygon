#include <iostream>
#include <vector>
#include <cassert>
#include <random>
#include <chrono>


int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    const int n = matrix.size(), m = matrix[0].size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1' && j == 0) {
                dp[i][j] = 1;
            } else if (matrix[i][j] == '1') {
                dp[i][j] = dp[i][j - 1] + 1;
            }
            int line = dp[i][j];

            for (int z = i; z >= 0; z--) {
                line = std::min(line, dp[z][j]);
                ans = std::max(ans, line * (i - (z - 1)));
            }
        }
    }
    return ans;
}

std::vector<std::vector<char>> randMatrix(const int n, const int m) {
    std::vector<std::vector<char>> matrix(n, std::vector<char>(m));
    std::random_device rd;
    std::mt19937 seed(rd());
    std::vector<char> symb = {'0', '1'};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = symb[seed() % 2];
        }
    }
    return matrix;
}

void display(std::vector<std::vector<char>>& matrix, const int& ans) {
    for (std::vector<char> i : matrix) {
        for (char j : i) {
            std::cout << j;
        }
        std::cout << "\n";
    }
}


bool check(const int& ans, const int& true_ans) {
    return ans == true_ans;
}


void test(std::vector<std::vector<char>>& matrix, const int& true_ans) {
    // auto start = std::chrono::high_resolution_clock::now();
    const int ans = maximalRectangle(matrix);
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration = end - start;

   // std::cout << duration.count() << "\n";
    assert(check(ans, true_ans));
}


int main() {
    std::vector<std::vector<char>> matrix1 = {{'1','0','1','0','0'},
                                            {'1','0','1','1','1'},
                                            {'1','1','1','1','1'},
                                            {'1','0','0','1','0'}};
    test(matrix1, 6);


    std::vector<std::vector<char>> matrix2 = {{'1','1','1','0','0'},
                                            {'1','1','1','1','1'},
                                            {'1','1','1','1','1'},
                                            {'1','0','0','1','0'}};
    test(matrix2, 10);


    std::vector<std::vector<char>> matrix3 = {{'1','1','1','0','0','0'},
                                            {'1','1','0','1','1','1'},
                                            {'1','1','1','1','1','0'},
                                            {'1','0','0','1','1','1'}};
    test(matrix3, 6);

    return 0;
}