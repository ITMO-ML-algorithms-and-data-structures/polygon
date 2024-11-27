#include <iostream>
#include <vector>


int findMinNeighbour(int firstNeighbour, int secondNeighbour) {
    return (firstNeighbour < secondNeighbour) ? firstNeighbour : secondNeighbour;
}

int findMinPathSum(std::vector<std::vector<int>>& grid) {
    if (grid.empty()) {
        return 0;
    }

    int rows = grid.size();
    int columns = grid[0].size();
    std::vector<std::vector<int>> subGrid(rows, std::vector<int>(columns, 0));

    // Инициализация первой ячейки
    subGrid[0][0] = grid[0][0];

    // Заполнение первой строки
    for (int j = 1; j < columns; j++) {
        subGrid[0][j] = subGrid[0][j - 1] + grid[0][j];
    }

    // Заполнение первого столбца
    for (int i = 1; i < rows; i++) {
        subGrid[i][0] = subGrid[i - 1][0] + grid[i][0];
    }

    // Заполнение остальной части subGrid
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            subGrid[i][j] = findMinNeighbour(
                subGrid[i - 1][j], subGrid[i][j - 1]) + grid[i][j];
        }
    }

    return subGrid[rows - 1][columns - 1];
}


int main() {
    std::vector<std::vector<int>> matrix = {{1,3}, {1,2}};

    std::cout << findMinPathSum(matrix);
    
    return 0;
}
