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

// библиотеки которые необходи установить. Читать тут: https://www.mlpack.org/download.html
#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>

// Файл в этой же папке, который я написал для задачи. Пока он обучает модель (черный ящик)
// и возвращает метрику качества (RMSE по умолчанию)
#include "modelling.cpp"


int feature_selection()
{
    // path to *.csv file
    // Будьте осторожны с путем. Сейчас вы в папке, но файл находится на уровень выше
    const char* path = "../data/WineQT.csv";

    // Код, которым можно считать набор данных, который дальше требуется анализировать
    arma::mat dataset;
    if (!mlpack::data::Load(path, dataset)) {
        // not fatal and not transpose (если false, false, mlpack::data::FileType::AutoDetect)
        throw std::runtime_error("Could not read *.csv!");
    }

    float score;

    // Тут нужно перебрать все комбинации (глупый цикл - это просто заглушка)
    for (int i = 0; i < 1; i++) {
        // Писать проверку каждой комбинации тут

        // Обучить модель (черный ящик), и получить метрику качество
        score = evaluate_dataset(dataset, 11, 12);

        // Это просто пример вывода для отладки
        std::cout << "RMSE: " << score << std::endl;
    }


    return score;
}

void run_tests() {
    // Проверка, что код работает корректно
    feature_selection();
}

int main() {
    run_tests();

    return 0;
}