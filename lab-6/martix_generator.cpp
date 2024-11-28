#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

void generateRandomMatrix(std::vector<std::vector<char>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        std::vector<char> row;
        for (int j = 0; j < cols; ++j) {
            row.push_back(rand() % 2); // Заполняем 0 или 1
        }
        matrix.push_back(row);
    }
}

void writeMatrixToCSV(const std::vector<std::vector<char>>& matrix, const std::string& fileName) {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << fileName << std::endl;
        return;
    }

    for (const auto& row : matrix) {
        for (size_t j = 0; j < row.size(); ++j) {
            file << static_cast<int>(row[j]); // Преобразуем char в int для записи
            if (j < row.size() - 1) {
                file << ","; // Разделитель
            }
        }
        file << "\n"; // Переход на новую строку
    }

    file.close();
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Инициализация генератора случайных чисел

    for (int i = 20; i < 100; i ++) {
        int rows = i; // Количество строк
        int cols = i; // Количество столбцов
        std::vector<std::vector<char>> matrix;

        generateRandomMatrix(matrix, rows, cols);

        std::string filename = std::to_string(rows) + "x" + std::to_string(cols) + ".csv";
        writeMatrixToCSV(matrix, filename);

        std::cout << "Generated and written to " << filename << std::endl;
    }

    

    return 0;
}
