/*
Компиляция программы на mac m1:
g++-14 -O3 -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib feature_selection.cpp -o ./main -larmadillo -fopenmp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>

#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>

#include "modelling.cpp"

// Перегружаем оператор вывода для вектора с произвольным типом данных
template <typename T>
std::ostream& operator<<(std::ostream &out, std::vector <T> &a) {
    for (auto i : a)
        out << i << ' ';
    return out;
}

std::vector<int> feature_selection()
{
    // path to *.csv file
    const char* path = "WineQT.csv";

    arma::mat dataset;
    if (!mlpack::data::Load(path, dataset)) {
        // not fatal and not transpose (если false, false, mlpack::data::FileType::AutoDetect)
        throw std::runtime_error("Could not read *.csv!");
    }

    float score, full_score = evaluate_dataset(dataset, 11, 12);
    std::cout << "Full score: " << full_score << "\n\n";
    std::vector<int> min_features;

    // Перебираем битмаску выбранных признаков
    for (int mask = 1; mask < (1 << 11); mask++) {
        std::vector<int> features;
        for (int i = 0; i < 11; i++)
            if (mask & (1 << i)) // Если i бит равен 1, то возьмем признак
                features.push_back(i);
        features.push_back(11); // Целевая переменная

        // Переводим в нужный тип данных
        arma::uvec indices(features.size());
        for (int i = 0; i < features.size(); i++) {
            indices[i] = static_cast<arma::uword>(features[i]);
        }
        arma::mat selectedFeatures = dataset.rows(indices);

        // Обучить модель (черный ящик), и получить метрику качество
        score = evaluate_dataset(selectedFeatures, (int)features.size() - 1);

        features.pop_back(); // Убираем целевую переменную
        if (full_score * 0.9 < score) { // Ухудшение не более чем на 10%
            if (min_features.empty() || min_features.size() > features.size()) {
                std::cout << "New score: " << score << '\n' << "Features: " << features << "\n\n";
                min_features = features;
            }
        }
    }

    return min_features;
}

void run_tests() {
    auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта

    std::vector<int> res = feature_selection();
    std::cout << "Minimum features: " << res << '\n';

    auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания

    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time for " << duration.count() << " seconds" << '\n'; // Выводим время работы
}

int main() {
    run_tests();
    return 0;
}