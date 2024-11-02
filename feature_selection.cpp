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

// В общем сложность составляет примерно O(n!*n*((n*m)+(n^2*m+n^3)+m)), память около 2*n*m*n^2*8 байт
std::vector<int> feature_selection() {
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

    // Перебираем все перестановки признаков и их количество за O(n!*n)
    std::vector<int> cur_features;
    for (int i = 0; i < 11; i++)
        cur_features.push_back(i);
    do {
        std::vector<int> features = {11}; // Целевая переменная
        for (int i = 0; i < 11; i++) {
            features.push_back(cur_features[i]);

            // Переводим в нужный тип данных
            arma::uvec indices(features.size());
            for (int i = 0; i < features.size(); i++) {
                indices[i] = static_cast<arma::uword>(features[i]);
            }
            // Составление новой матрицы с данными за O(n*m), размера n*m*8 байт.
            arma::mat selectedFeatures = dataset.rows(indices);

            // Обучить модель (черный ящик), и получить метрику качество. Примерно O(n^2*m+n^3) через стандартную реализацию
            score = evaluate_dataset(selectedFeatures, 0);

            features.pop_back(); // Убираем целевую переменную
            if (full_score * 0.9 < score) { // Ухудшение не более чем на 10%
                if (min_features.empty() || min_features.size() > features.size()) {
                    std::cout << "New score: " << score << '\n' << "Features: " << features << "\n\n";
                    min_features = features;
                }
            }
        }
    } while (std::next_permutation(cur_features.begin(), cur_features.end())); // Берем следующую перестановку

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