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
#include <unordered_map>
#include <cmath>
#include <bitset>

// библиотеки которые необходи установить. Читать тут: https://www.mlpack.org/download.html
#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>

// Файл в этой же папке, который я написал для задачи. Пока он обучает модель (черный ящик)
// и возвращает метрику качества (RMSE по умолчанию)
#include "modelling.hpp"

int feature_selection()
{
    // path to *.csv file
    // Будьте осторожны с путем. Сейчас вы в папке, но файл находится на уровень выше
    const char* path = "D:/Projects/mlpack_project/polygon/data/Concrete_Data_Yeh.csv";//"D:/Projects/mlpack_project/polygon/data/WineQT.csv"; //"../data/WineQT.csv";

    // Код, которым можно считать набор данных, который дальше требуется анализировать
    arma::mat dataset;
    if (!mlpack::data::Load(path, dataset)) {
        // not fatal and not transpose (если false, false, mlpack::data::FileType::AutoDetect)
        throw std::runtime_error("Could not read *.csv!");
    }
    // Инициализация переменных для оценки качества
    float best_score, score, optimal_score=100000;
    best_score = evaluate_dataset(dataset, 8);

    float porog_score = best_score * 1.5; // Порог для отбора признаков, тут я поставил 50 %, т.к. ниже нет таких комбинаций для моей даты
    
    std::vector<int> result_inds; // Вектор для хранения индексов лучших признаков
    int n=dataset.n_rows - 2; // Количество признаков (без целевой переменной)
    int num_combinations = std::pow(2,n); // Общее количество комбинаций
    int max_features_num = dataset.n_rows - 2;

    // Перебираем все возможные комбинации признаков
    for (int i=0; i < num_combinations; i++) {
        std::bitset<16> binary(i); // Бинарное представление комбинации
        std::vector<int> IndsVector; // Вектор индексов выбранных признаков
        std::string binary_digit = binary.to_string().substr(16 - n);
        int num_nozero_inds=0;
        
        // Переводим битовую строку в индексы признаков
        for (int j=0; j < binary_digit.size(); j++) { 
            if (binary_digit[j]=='1') { // Если бит равен 1, добавляем признак
                IndsVector.push_back(j);
                num_nozero_inds += 1;
            }
        }

        // Пропускаем комбинации с нулем или максимальным количеством признаков
        if (IndsVector.size()==0 | IndsVector.size()==8 ) {
            continue;
        }

        IndsVector.push_back(8); // тут мы добавляем индекс таргета

        arma::uvec indices = arma::conv_to<arma::uvec>::from(IndsVector);
        arma::mat slice3 = dataset.rows(indices); // Отбираем нужные строки из набора данных

        score = evaluate_dataset(slice3, num_nozero_inds);
        
        // Проверяем, лучше ли текущее качество и меньше ли количество признаков
        if (score <= porog_score) {
            if (num_nozero_inds < max_features_num || (num_nozero_inds == max_features_num && score < optimal_score)) {
                max_features_num = num_nozero_inds;
                optimal_score = score;
                result_inds = IndsVector;
            }
        }
    }

    // Это просто пример вывода для отладки
    std::cout << "RMSE on all features: " << best_score << std::endl;
    std::cout << "RMSE on best min features: " << optimal_score << std::endl;
    for (int i=0; i < result_inds.size(); i++) {
        std::cout << i << " ";
    }

    return best_score;
}

void run_tests() {
    // Проверка, что код работает корректно
    feature_selection();
}

int main() {
    run_tests();

    return 0;
}