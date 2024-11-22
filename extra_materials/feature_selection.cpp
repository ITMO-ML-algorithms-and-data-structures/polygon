/*
Как установить mlpack читать тут: https://www.mlpack.org/doc/quickstart/cpp.html

Компиляция программы на mac m1:
g++-14 -O3 -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib feature_selection.cpp -o ./main -larmadillo -fopenmp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// библиотеки которые необходи установить. Читать тут: https://www.mlpack.org/download.html
#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>

// Файл в этой же папке, который я написал для задачи. Пока он обучает модель (черный ящик)
// и возвращает метрику качества (RMSE по умолчанию)
#include "modelling.h"
#include <limits>
#include <armadillo>

float best_score = std::numeric_limits<float>::max();
float cur_best_score = std::numeric_limits<float>::max();
std::set<int> best_features;
short int target_index = 11;
short int id_index = 12;
short int features_count = 12;

void print_feature_evaluation(const std::vector<int> &current_features, float score) {
    std::cout << "Evaluating features: ";
    for (const int feature: current_features) {
        std::cout << feature << " ";
    }
    std::cout << "=> RMSE: " << score << std::endl;
}

// Функция для рекурсивного выбора признаков
void check_feature_score(arma::mat &dataset, std::vector<int> &current_features, int start, float threshold) {
    // Массив индексов колонок, которые нужно удалить (кроме таргета и id)
    std::vector<int> to_drop;
    for (int i = 1; i < dataset.n_rows; ++i) {
        if (i != target_index && i != id_index && std::ranges::find(current_features, i) == current_features.
            end()) {
            to_drop.push_back(i);
        }
    }

    // Урезаем датасет
    arma::mat reduced_dataset = drop_columns(dataset, to_drop);

    // std::cout << "Reduced dataset size: " << reduced_dataset.n_cols << " rows, " << reduced_dataset.n_rows << " columns." << std::endl;
    float score = evaluate_dataset(reduced_dataset, static_cast<short>(reduced_dataset.n_rows - 2),
                                   static_cast<short>(reduced_dataset.n_rows - 1));

    // Вывод информации о текущем наборе признаков и RMSE
    //print_feature_evaluation(current_features, score);

    // Условие для улучшения: Если RMSE меньше на 10% по сравнению с лучшим результатом
    if (score < best_score * threshold) {
        cur_best_score = score;
        best_features = std::set<int>(current_features.begin(), current_features.end());
        //std::cout << "New best score found!" << std::endl;
        //print_feature_evaluation(current_features, score);
    }

    for (int i = start; i < features_count; ++i) {
        current_features.push_back(i);
        check_feature_score(dataset, current_features, i + 1, threshold);
        current_features.pop_back();
    }
}

// Функция для выбора признаков
void feature_selection() {
    arma::mat dataset;
    if (auto path = "../data/WineQT.csv"; !mlpack::data::Load(path, dataset)) {
        throw std::runtime_error("Could not read *.csv!");
    }

    // Оценка качества модели с использованием всех признаков
    best_score = evaluate_dataset(dataset, 11, 12);
    std::cout << "Best score with all features (RMSE): " << best_score << std::endl;

    std::vector<int> current_features;
    float threshold = best_score * static_cast<float>(0.90);

    // Начинаем рекурсивный выбор признаков
    check_feature_score(dataset, current_features, 0, threshold);

    if (best_features.empty()) {
        std::cout << "No such combination of features";
    } else {
        std::cout << "Best features (indices): ";
        for (int feature: best_features) {
            std::cout << feature << " ";
        }
    }
    std::cout << "\nBest score after feature selection (RMSE): " << cur_best_score << std::endl;
}

// Тесты
void run_tests() {
    arma::mat dataset(150, 13, arma::fill::randu); // 150 строк, 13 столбцов (случайные данные)

    // Тест 1: Начинаем с минимального набора признаков
    std::cout << "Test 1: Starting with a minimal feature set" << std::endl;
    std::vector<int> current_features = {0};
    best_score = std::numeric_limits<float>::max();
    check_feature_score(dataset, current_features, 1, 0.90);
    std::cout << "Best score after test 1: " << best_score << std::endl;

    // Тест 2: Начинаем с заранее заданного набора признаков
    std::cout << "Test 2: Starting with a predefined set of features" << std::endl;
    current_features = {0, 1, 2};
    best_score = std::numeric_limits<float>::max();
    check_feature_score(dataset, current_features, 3, 0.90);
    std::cout << "Best score after test 2: " << best_score << std::endl;

    // Тест 3: Проверяем, что набор признаков не меняется, если RMSE уже оптимален
    std::cout << "Test 3: Best score is already found" << std::endl;
    current_features = {0, 1, 2, 3};
    best_score = 0.0005f;
    check_feature_score(dataset, current_features, 2, 0.90);
    std::set<int> set_from_vector(current_features.begin(), current_features.end());
    if(best_features != set_from_vector) {
        std::cout << "Test 3 passed!" << std::endl;
    }
    std::cout << "Best score after test 3: " << best_score << std::endl;

    // Тест 4: Проверка порога улучшения
    std::cout << "Test 4: Checking improvement threshold" << std::endl;
    current_features = {0, 1, 2, 3, 4, 5, 6};
    float initial_score = 0.0005f;
    best_score = initial_score;
    check_feature_score(dataset, current_features, 2, 0.90);
    if (best_score < initial_score) {
        std::cout << "Improvement found!" << std::endl;
    } else {
        std::cout << "No improvement" << std::endl;
    }
}

int main() {
    run_tests();

    feature_selection();

    return 0;
}
