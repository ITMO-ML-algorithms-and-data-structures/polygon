
#include <armadillo>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>

/*Дан датасет и некая модель МО (в виде функции). Модель может принимать на вход
датасет, и возвращает на выход некую оценку, которая ранжируется от 0 до inf.


Необходимо перебрать все возможные комбинации признаков и выбрать их минимальное
количество, при котором оценка уменьшится не меньше чем на 10% от наилучшего
(когда мы передаем в модель МО все признаки)

Подробнее про идею

Заготовка кода, как и модель "черного ящика" лежит тут. Кто понимает что
написано, и не боится - тому можно брать это задание*/
// Ежов Дмитрий j3113 471242
// lab-4
// hard+

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
  std::vector<std::pair<arma::uword, double>> inf_gain(dataset.n_rows - 2);
  for (auto fi = 0; fi < dataset.n_rows - 2; fi++) {
    inf_gain[fi] = std::make_pair(fi, get_information_gain(dataset, fi));
  }
  std::sort(inf_gain.begin(), inf_gain.end(), _cmp);
  std::cout << "\ninformation gain features: \n";
  for (auto i : inf_gain) {
    std::cout << i.first << '\t' << i.second << std::endl;
  }
  arma::uword count_feature = (double)(dataset.n_rows - 2) * (1 - procent);
  std::cout << count_feature << std::endl;
  arma::uvec sheded_rows(count_feature);
  for (auto i = 0; i < sheded_rows.size(); i++) {
    sheded_rows[i] = inf_gain[i].first;
  }
  dataset.shed_rows(sheded_rows);
}

arma::uvec transorf_dataset_comb(arma::mat &dataset, int comb) {

  std::vector<arma::uword> sheded_rows_vec;
  sheded_rows_vec.reserve(dataset.n_rows - 2);
  for (int i = 0; i < dataset.n_rows - 2; ++i) {
    if (!(comb & (1 << i))) {
      sheded_rows_vec.push_back(i);
    }
  }
  arma::uvec sheded_rows(sheded_rows_vec);

  dataset.shed_rows(sheded_rows);
  return sheded_rows;
}
float get_val_with_dataset_comb(arma::mat dataset,
                                float (*model)(arma::mat, short int, short int),
                                int comb, bool print = false) {
  auto sheded_rows = transorf_dataset_comb(dataset, comb);
  float val = model(dataset, dataset.n_rows - 2, -1);
  if (print) {
    std::cout << "Combination:\t" << comb << "\tValue\t" << val << std::endl;
    sheded_rows.print();
  }
  return val;
}

void exhaustive_selection(arma::mat &dataset,
                          float (*model)(arma::mat, short int, short int),
                          bool print = false) {
  float best_val = 1;
  int best_comb = 0;
  for (int comb = 0; comb < std::pow(2, dataset.n_rows - 2) - 10; comb++) {
    auto val = get_val_with_dataset_comb(dataset, model, comb, print);
    if (val < best_val) {
      best_val = val;
      best_comb = comb;
    }
  }
  transorf_dataset_comb(dataset, best_comb);
  if (print)
    std::cout << "\n\tBest combination:\t" << best_comb << "\tVal:\t"
              << best_val << "\n\tFinal n_rows: \t" << dataset.n_rows
              << std::endl;
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
    exhaustive_selection(dataset, evaluate_dataset, true);
    // Обучить модель (черный ящик), и получить метрику качество
    score = evaluate_dataset(dataset, dataset.n_rows - 2);

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
