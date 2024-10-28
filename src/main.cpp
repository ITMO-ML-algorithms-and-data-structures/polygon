#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>
#include "modelling.cpp"


std::pair<float, float> get_best_binarization_scores(const arma::mat& features, const arma::subview_row<double>& target_row) noexcept {
    std::vector<arma::mat> all_features_binarizations;
    all_features_binarizations.reserve(features.n_rows); // Выделяем память | O(n_features_rows)
    for (size_t i = 0; i < features.n_rows; ++i) {  // O(K * n_features_cols * n_features_rows)
        all_features_binarizations.emplace_back(5, features.n_cols); // Резервируем память | O(K * n_features_cols)
        const double min_value = features.row(i).min(); // O(n_features_cols)
        const double max_value = features.row(i).max(); // O(n_features_cols)
        // К сожалению min_max нету

        const double step = (max_value - min_value) / 6.0;
        for (uint8_t threshold_i = 1; threshold_i <= 5; ++threshold_i) {  // Cуммарно O(K * n_features_cols)
            const double threshold = min_value + threshold_i * step;
            all_features_binarizations[i].row(threshold_i - 1) = arma::conv_to<arma::rowvec>::from(features.row(i) >= threshold); // O(n_features_cols)
        }
    }

    // all_features_binarizations будет хранить 11 * 5 * 1143 * 8 байт (обобщённо n_features_rows * n_thresholds * n_features_cols * 8 байт)
    
    double best_score = std::numeric_limits<float>::max();
    double result_score = 0.0;

    std::vector<size_t> current(features.n_rows, 0); // 8 * 11 байт (обобщённо n_features_rows * 8 байт) | O(n_features_rows)
    arma::mat testing_dataset(features.n_rows, features.n_cols); // 11 * 1143 * 8 байт(обобщённо n_features_rows * n_features_cols * 8 байт) резервируем память | O(n_features_rows * n_features_cols)

    const auto start_time = std::chrono::high_resolution_clock::now();

    while (true) { // Суммарно O(K^n_features_rows * (n_features_cols * n_features_rows + O(LinearRegression)))
        for (size_t j = 0; j < features.n_rows; ++j) { // O(n_features_cols * n_features_rows)
            testing_dataset.row(j) = all_features_binarizations[j].row(current[j]); // O(n_features_cols)
        }

        result_score = evaluate_dataset(testing_dataset, target_row); // O(LinearRegression)
        if (result_score < best_score) {
            best_score = result_score;
        }

        long long i = features.n_rows - 1;
        while (i >= 0) { // Отдельно рассматривать этот цикл нет смысла.
            if (current[i] < 4) { 
                current[i]++;
                break;
            }
            else {
                current[i] = 1;
                i--;
            }
        }
        if (i < 0) {
            break;
        }
    }

    const std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - start_time;
    std::cout << "Execution Time: " << duration.count() << " seconds\n";

    // Суммарная Time complexity составляет O(K^n_features_rows * (n_features_cols * n_features_rows + O(LinearRegression)))

    return std::pair<float, float> (best_score, result_score); // Возвращает 16 байт
}

inline void run_tests() {
    arma::mat dataset;
    if (!mlpack::data::Load("../data/WineQT.csv", dataset)) { // Загружаем датасет 13 * 1143 * 8 байт (обобщённо n_rows * n_cols * 8 байт) | O(n_cols * n_rows)
        throw std::runtime_error("Could not read *.csv!");
    }
    else {
        std::pair<float, float> scores = get_best_binarization_scores(dataset.submat(0, 0, dataset.n_rows - 3, dataset.n_cols - 1), dataset.row(11)); // Получили 16 байт // -3
        std::cout << scores.first << "\n" << scores.second << "\n";
    }
}

int main() {
    run_tests();
}