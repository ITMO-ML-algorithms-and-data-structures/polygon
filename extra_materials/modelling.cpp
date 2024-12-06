#include <array>
#include <vector>
#include <algorithm>

#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>

template <typename T>
arma::mat mat_from_vectors(std::vector<std::vector<T>> &matrix) {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();

    // Инициализируем матрицу Armadillo
    arma::mat mat(rows, cols);

    // Заполнение матрицы данными из вектора
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            mat(i, j) = matrix[i][j];
        }
    }

    return mat;
}

arma::mat drop_columns(arma::mat &dataset, std::vector<int> indices) {
    arma::uvec columns_to_left(dataset.n_rows - indices.size());

    int j = 0;
    for (int i = 0; i < dataset.n_rows; i++) {
        bool not_exists = std::find(indices.begin(), indices.end(), i) == indices.end();
        if (not_exists) {
            columns_to_left(j) = i;
            j++;
        }
    }

    return dataset.rows(columns_to_left);
}

/**
 * @brief Функция обучения модели МО (черного ящика), возвращающая метрику качества
 * 
 * Функция принимает на вход набор данных, и индексы столбцов целевого и индекс столбцов.
 * Главые действия: удалить индекс столбец, если он есть; извлечь целевой столбец, обучить модель
 * и вернуть метрику качества
 * 
 * @param[in] dataset Набор данных
 * @param[in] target_column_index Индекс целевого столбца (считать в датасете с индекса 0)
 * @param[in] id_column_index Индекс id или index столбца если он есть, который не важен модели при обучении
 * @return Метрика качества RMSE
 */
float evaluate_dataset(arma::mat dataset, short int target_column_index, short int id_column_index = -1) {
    // Взять целевой столбец из датасета (таргет)
    arma::rowvec y = dataset.row(target_column_index);

    // Удалить столбцы таргета и id (индекс) если они есть
    std::vector<int> to_drop = {target_column_index};
    if (id_column_index >= 0) {
        to_drop.push_back(id_column_index);
    }
    arma::mat X = drop_columns(dataset, to_drop);

    // Создать объект модели
    mlpack::regression::LinearRegression lr;

    // Обучить модель и получить метрику качества
    float rmse = lr.Train(X, y);
    
    return rmse;
}