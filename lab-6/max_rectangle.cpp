#include <iostream>
#include <vector>
#include <algorithm>

int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int max_area = 0;

    //int y, x = 0, 0

    for (int y = 0; y < rows; y ++) {
        for (int x = 0; x < rows; x ++) {
            //while (y < rows && x < cols) {
            if (matrix[y][x] == '1') {
                int tmp_add_y = 1;

                while (matrix[y + tmp_add_y][x] == '1' && (y + tmp_add_y) < rows) {
                    tmp_add_y ++;
                }

                bool flag = true;
                int tmp_area = tmp_add_y;

                for (int j = 1; j < cols - x; j ++) {
                    for (int i = 0; i < tmp_add_y; i ++) {
                        if (matrix[y + i][x + j] == '1') {
                            continue;
                        }
                        else {
                            flag = false;
                            break;
                        }

                    }

                    if (flag) {
                        tmp_area += tmp_add_y;
                    }
                    else {
                        break;
                    }
                }

                max_area = std::max(max_area, tmp_area);
            }
        }
    }

    return max_area;

    // for (int i = 0; i < rows; i ++) {
    //     for (int j = 0; j < cols; j ++) {
    //         if matrix[i][j] == '1':
                

    //             while 
    //     }
    // }
}

int main() {
    std::vector<std::vector<char>> matrix = {{'1','0','1','0','0'},
                                            {'1','0','1','1','1'},
                                            {'1','1','1','1','1'},
                                            {'1','0','0','1','0'}};

    std::cout << maximalRectangle(matrix) << std::endl;            
}

