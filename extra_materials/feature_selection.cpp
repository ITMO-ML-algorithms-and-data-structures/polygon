/*
Как установить mlpack читать тут: https://www.mlpack.org/doc/quickstart/cpp.html

Компиляция программы на mac m1:
g++-14 -O3 -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib feature_selection.cpp -o ./main -larmadillo -fopenmp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

// библиотеки которые необходимо установить. Читать тут: https://www.mlpack.org/download.html
#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>

// Файл с функцией обучения модели (черный ящик)
#include "modelling.cpp"

// Функция бинаризации данных по одному признаку и порогу
arma::mat binarize_feature(const arma::mat& dataset, int feature_index, double threshold) {
    arma::mat binary_dataset = dataset; // Создаем копию исходного набора данных
    binary_dataset.row(feature_index).transform([threshold](double val) {
        return val > threshold ? 1.0 : 0.0; // Преобразуем значения по порогу
    });
    return binary_dataset;
}

float feature_selection()
{
    // Путь к файлу *.csv
    const char* path = "../data/WineQT.csv";

    // Чтение набора данных
    arma::mat dataset;
    if (!mlpack::data::Load(path, dataset)) {
        throw std::runtime_error("Could not read *.csv!");
    }

    int target_column_index = 11;
    int id_column_index = 12;

    // Вектор для хранения оптимальных порогов для каждого признака
    std::vector<double> best_thresholds(dataset.n_rows, 0.0);
    std::vector<float> best_scores(dataset.n_rows, std::numeric_limits<float>::infinity());

    // Перебираем все признаки
    for (int feature_index = 0; feature_index < dataset.n_rows; ++feature_index) {
        if (feature_index == target_column_index || feature_index == id_column_index) {
            continue; // Пропускаем целевой и ID столбец
        }

        // Вычисляем минимальное и максимальное значение признака
        double min_val = dataset.row(feature_index).min();
        double max_val = dataset.row(feature_index).max();
        double step = (max_val - min_val) / 6.0;

        // Перебираем 5 порогов
        for (int j = 1; j <= 5; ++j) {
            double threshold = min_val + j * step;

            // Бинаризация текущего признака
            arma::mat binary_dataset = binarize_feature(dataset, feature_index, threshold);

            // Оценка модели с бинаризованным признаком
            float score = evaluate_dataset(binary_dataset, target_column_index, id_column_index);

            // Если текущий результат лучше, обновляем лучший результат для данного признака
            if (score < best_scores[feature_index]) {
                best_scores[feature_index] = score;
                best_thresholds[feature_index] = threshold;
            }
        }
    }

    // Оценка модели на исходном (не бинаризованном) наборе данных
    float original_score = evaluate_dataset(dataset, target_column_index, id_column_index);
    std::cout << "result_score = " << original_score << std::endl;

    // Бинаризация всех признаков с их оптимальными порогами
    arma::mat final_binary_dataset = dataset;
    for (int feature_index = 0; feature_index < dataset.n_rows; ++feature_index) {
        if (feature_index == target_column_index || feature_index == id_column_index) {
            continue; // Пропускаем целевой и ID столбец
        }

        // Бинаризуем текущий признак с его оптимальным порогом
        final_binary_dataset = binarize_feature(final_binary_dataset, feature_index, best_thresholds[feature_index]);
    }

    // Оценка модели на финальном бинаризованном наборе данных
    float final_score = evaluate_dataset(final_binary_dataset, target_column_index, id_column_index);
    std::cout << "best_score = " << final_score << std::endl;

    return final_score;
}

void run_tests() {
    // Проверка, что код работает корректно
    feature_selection();
}

int main() {
    run_tests();

    return 0;
}
