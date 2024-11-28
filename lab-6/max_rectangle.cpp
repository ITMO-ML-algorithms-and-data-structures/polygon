#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>

std::vector<std::vector<char>> readMatrixFromCSV(const std::string& fileName) { // Чтение матрицы из csv
    std::vector<std::vector<char>> matrix;
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << fileName << std::endl;
        return matrix; // Вернем пустую матрицу в случае ошибки
    }

    while (std::getline(file, line)) {
        std::vector<char> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            if (!cell.empty()) {
                row.push_back(cell.at(0)); // Преобразуем строку в символ
            }
        }
        matrix.push_back(row);
    }

    file.close();
    return matrix;
}

// Для удобства скажем, что матрица квадратная, размера N^2
int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int max_area = 0;

    // Перебираем все ячейки по очереди
    for (int y = 0; y < rows; y ++) {       // O(N) итераций
        for (int x = 0; x < cols; x ++) {   // O(N) итераций
            if (matrix[y][x] == '1') { // Если в клетке 1 - начинаем строить прямоугольник от этой вершины
                int tmp_max_add_y = 1;

                while ((y + tmp_max_add_y) < rows && matrix[y + tmp_max_add_y][x] == '1') { // в среднем О(N / 2) итераций
                    tmp_max_add_y ++; // Ищем максимальную "добавку" к глубине
                }

                // Перебираем все возможные значения глубины
                for (int tmp_add_y = 1; tmp_add_y <= tmp_max_add_y; tmp_add_y ++) { // в среднем О(N / 2) итераций
                    bool flag = true;
                    int tmp_area = tmp_add_y;

                    // Строим максимально "длинный" прямоугольник при текущей глубине
                    // Перебор столбцов правее текущего
                    for (int j = 1; j < cols - x; j ++) { // в среднем О(N / 2) итераций
                        // Проверяем, состоит ли каждый столбец только из 1
                        for (int i = 0; i < tmp_add_y; i ++) { // в среднем О(N / 2) итераций
                            if (matrix[y + i][x + j] == '1') { // взятие по индексу - О(1)
                                continue;
                            }
                            else {
                                flag = false; // Если в столбце есть 0 - завершаем текущую итерацию
                                break;
                            }

                        }

                        if (flag) {
                            tmp_area += tmp_add_y; // Если столбец из 1 - "приклеиваем" этот столбец справа к текущему прямоугольнику
                        }
                        else {
                            break;
                        }
                    }

                    max_area = std::max(max_area, tmp_area); // Обновляем максимальную площадь

                    if (max_area == rows * cols) // Предельный случай - если с первого раза построили прямоугольник максимально возможного размера
                        return max_area;
                } 
            }
        }
    }

    return max_area;

    // Итого асиптотика:
    // O(N) * O(N) * O(N / 2) * O(N / 2) * O(N / 2) * О(1) = O(N ^ 5 / 8) - в среднем случае
    // можно апроксимировать до О(N ^ 5), что является худшим случаем

    // Дополнительная память для сложных структур не используется
    // на всех уровнях используются временные int-переменные,
    // использущие О(1) памяти, можно сказать, что память равна асимптотике - О(N ^ 5)
}


int main() {
    // std::vector<std::vector<char>> matrix = {{'1','1','1','1','1','1','1','1'}, 
    //                                          {'1','1','1','1','1','1','1','0'},
    //                                          {'1','1','1','1','1','1','1','0'},
    //                                          {'1','1','1','1','1','0','0','0'},
    //                                          {'0','1','1','1','1','0','0','0'}};
    // // std::vector<std::vector<char>> matrix = {{'0'}};

    // int max_area = maximalRectangle(matrix);

    // std::cout << "Result: " << max_area << std::endl;    

    for (int i = 1; i < 100; i ++) {
        std::string fileName = std::to_string(i) + "x" + std::to_string(i) + ".csv";
        std::vector<std::vector<char>> matrix = readMatrixFromCSV(fileName);

        auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

        int max_area = maximalRectangle(matrix);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;

        //std::cout << (matrix[0][0] == '1') << std::endl;

        // for (const auto& row : matrix) {
        //     for (char val : row) {
        //         std::cout << static_cast<int>(val) << " "; // Преобразуем char в int для вывода
        //     }
        //     std::cout << std::endl;
        // }

        std::cout << duration.count() << std::endl;
    }        
}

