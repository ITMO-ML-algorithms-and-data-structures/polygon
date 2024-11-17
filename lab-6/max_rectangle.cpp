#include <iostream>
#include <vector>
#include <algorithm>

 int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int max_area = 0;

    for (int y = 0; y < rows; y ++) {
        for (int x = 0; x < cols; x ++) {
            if (matrix[y][x] == '1') {
                int tmp_max_add_y = 1;

                while ((y + tmp_max_add_y) < rows && matrix[y + tmp_max_add_y][x] == '1') {
                    tmp_max_add_y ++;
                }

                for (int tmp_add_y = 1; tmp_add_y <= tmp_max_add_y; tmp_add_y ++) {
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

                    if (max_area == rows * cols)
                        return max_area;
                } 
            }
        }
    }

    return max_area;
}


int main() {
    std::vector<std::vector<char>> matrix = {{'1','1','1','1','1','1','1','1'}, 
                                             {'1','1','1','1','1','1','1','0'},
                                             {'1','1','1','1','1','1','1','0'},
                                             {'1','1','1','1','1','0','0','0'},
                                             {'0','1','1','1','1','0','0','0'}};
    // std::vector<std::vector<char>> matrix = {{'0'}};

    int max_area = maximalRectangle(matrix);

    std::cout << "Result: " << max_area << std::endl;            
}

