/*
Как установить mlpack читать тут: https://www.mlpack.org/doc/quickstart/cpp.html

Компиляция программы на mac m1:
g++-14 -O3 -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib feature_selection.cpp -o ./main -larmadillo
-fopenmp
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// библиотеки которые необходи установить. Читать тут: https://www.mlpack.org/download.html
#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>

// Файл в этой же папке, который я написал для задачи. Пока он обучает модель (черный ящик)
// и возвращает метрику качества (RMSE по умолчанию)
#include "modelling.cpp"

int feature_selection() {
    const char* path = "./WineQT.csv";
    int target_column_index = 11;
    int id_column_index = 12;

    // read dataset
    arma::mat dataset;
    if (!mlpack::data::Load(path, dataset)) {
        throw std::runtime_error("Could not read *.csv!");
    }

    // get target and drop id
    arma::rowvec target = dataset.row(target_column_index);
    std::vector<int> to_drop = {target_column_index};
    if (id_column_index >= 0) {
        to_drop.push_back(id_column_index);
    }
    dataset = drop_columns(dataset, to_drop);

    float score;
    int num_cols = dataset.n_rows;
    float best_score = std::numeric_limits<float>::max();
    std::vector<int> best_combination;

    for (int mask = 1; mask < (1 << num_cols); ++mask) {
        std::vector<int> combination;
        for (int j = 0; j < num_cols; ++j) {
            if (mask & (1 << j)) {
                combination.push_back(j);
            }
        }
        if (!combination.empty()) {
            arma::uvec arma_combination(combination.size());
            for (size_t i = 0; i < combination.size(); ++i) {
                arma_combination[i] = combination[i];
            }
            arma::mat sub_dataset = dataset.rows(arma_combination);

            float score = evaluate_dataset(sub_dataset, target);
            if (score < best_score) {
                best_score = score;
                best_combination = combination;
            }
            std::cout << "Combination: ";
            for (int col : combination) {
                std::cout << col << " ";
            }
            std::cout << "\n" << "RMSE: " << score << std::endl;
        }
    }

    std::cout << "\nBest combination: ";
    for (int col : best_combination) {
        std::cout << col << " ";
    }
    std::cout << "\n" << "Best RMSE: " << best_score << std::endl;

    return score;
}

int main() { feature_selection(); }