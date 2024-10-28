#include <array>
#include <vector>
#include <algorithm>

#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>

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
inline double evaluate_dataset(const arma::mat& features, const arma::subview_row<double>& target) {
    // Создать объект модели
    mlpack::regression::LinearRegression lr;

    // Обучить модель и получить метрику качества
    const double rmse = lr.Train(features, target);

    return rmse;
}