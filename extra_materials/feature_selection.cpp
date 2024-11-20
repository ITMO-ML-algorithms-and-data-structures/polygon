
#include <armadillo>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>

// Файл в этой же папке, который я написал для задачи. Пока он обучает модель
// (черный ящик) и возвращает метрику качества (RMSE по умолчанию)

#include "modelling.cpp"
double get_information_gain(arma::mat dataset, arma::uword fi) {
  double res = 0;
  for (auto r = 0; r < dataset.n_rows - 2; r++) {
    if (r == fi)
      continue;
    arma::uword count_diff = 0;
    for (auto c = 0; c < dataset.n_cols; c++) {
      count_diff += dataset(fi, c) == dataset(r, c);
    }
    double p = (double)count_diff / dataset.n_cols;
    if (p != 0)
      res -= p * std::log2(p);
  }
  return res;
}

bool _cmp(std::pair<arma::uword, double> &a,
          std::pair<arma::uword, double> &b) {
  return a.second > b.second;
}
void filter_information_gain(arma::mat &dataset, double procent) {
  std::vector<std::pair<arma::uword, double>> inf_gain(dataset.n_rows);
  for (auto fi = 0; fi < dataset.n_rows - 2; fi++) {
    inf_gain[fi] = std::make_pair(fi, get_information_gain(dataset, fi));
  }
  std::sort(inf_gain.begin(), inf_gain.end(), _cmp);
  for (auto i : inf_gain) {
    std::cout << i.first << '\t' << i.second << std::endl;
  }
  arma::uword count_feature = (double)(dataset.n_rows - 2) * (1 - procent);
  std::cout << count_feature << std::endl;
  arma::uvec sheded_rows(count_feature);
  for (auto i = 0; i < sheded_rows.size(); i++) {
    sheded_rows[i] = inf_gain[i].first;
    std::cout << inf_gain[i].first;
  }
  dataset.shed_rows(sheded_rows);
}

int feature_selection() {
  // path to *.csv file
  // Будьте осторожны с путем. Сейчас вы в папке, но файл находится на уровень
  // выше
  const char *path = "../data/WineQT.csv";

  // Код, которым можно считать набор данных, который дальше требуется
  // анализировать
  arma::mat dataset;
  if (!mlpack::data::Load(path, dataset)) {
    // not fatal and not transpose (если false, false,
    // mlpack::data::FileType::AutoDetect)
    throw std::runtime_error("Could not read *.csv!");
  }

  float score;

  // Тут нужно перебрать все комбинации (глупый цикл - это просто заглушка)
  for (int i = 0; i < 1; i++) {
    std::cout << dataset.n_rows;
    std::cout << "\n\n\n";
    filter_information_gain(dataset, 0.4);
    std::cout << '\n' << dataset.n_rows << '\n';
    // Обучить модель (черный ящик), и получить метрику качество
    score = evaluate_dataset(dataset, dataset.n_rows - 2, dataset.n_rows - 1);

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
