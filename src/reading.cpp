#include <armadillo>
#include <vector>
#include <iostream>
#include <sstream>


arma::mat loadDataset(const char* path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file.");
    }

    std::vector<std::vector<double>> data;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<double> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ';')) {
            row.push_back(std::stod(cell));
        }
        data.push_back(row);
    }

    file.close();

    size_t rows = data.size();
    size_t cols = data[0].size();
    arma::mat dataset(rows, cols);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            dataset(i, j) = data[i][j];
        }
    }

    return dataset;
}
