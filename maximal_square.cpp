#include <iostream>
#include <vector>
#include <algorithm>


int findMinNeighbour(int i, int j, 
    const std::vector<std::vector<int>>& subMatrix){

    int minFrom2Upper= std::min(subMatrix[i-1][j], subMatrix[i-1][j-1]);

    return std::min(minFrom2Upper, subMatrix[i][j-1]);
}


int maximalSquare(const std::vector<std::vector<char>>& matrix) {
    if (matrix.empty()){
        return 0;
    }

    short int rows = matrix.size();
    short int columns = matrix[0].size();

    std::vector<std::vector<int>> subMatrix(rows, std::vector<int>(columns, 0));

    int maxElem = 0;
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < columns; j++){

            // Переводим char в int
            int elem = matrix[i][j] - '0';

            // Если в первой строке/столбце, то просто переносим элемент
            if ((i == 0) || (j == 0)){
                subMatrix[i][j] = elem;
            } else {
                // Если в другом месте, то вычисляем минимум из соседей 
                // и + 1, если элемент = 1, иначе оставляем 0
                if (elem == 1){
                    subMatrix[i][j] = findMinNeighbour(i,j,subMatrix) + 1;
                }
            }

            if (subMatrix[i][j] > maxElem){
                maxElem = subMatrix[i][j];
            }
        }
    }

    return maxElem * maxElem;
}


int main(){
    std::vector<std::vector<char>> matrix = {{'1','0','1','1'}, {'1','1','0','1'}};

    std::cout << maximalSquare(matrix);
    
    return 0;
}