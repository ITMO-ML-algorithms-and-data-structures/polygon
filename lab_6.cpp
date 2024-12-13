#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> arr(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = matrix[i][j] - '0';
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[i][j] == 1) {
                    arr[i][j] += arr[i - 1][j];
                }
            }
        }

        int max_size = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[i][j] > 0) {
                    int height = arr[i][j];
                    int left = j, right = j;

                    while (left > 0 && arr[i][left - 1] >= height) {
                        left--;
                    }

                    while (right + 1 < cols && arr[i][right + 1] >= height) {
                        right++;
                    }
                    int width = right - left + 1;
                    max_size = max(max_size, width * height);
                }
            }
        }

        return max_size;
    }
};
