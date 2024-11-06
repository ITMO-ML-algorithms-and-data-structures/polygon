#ifndef MODELLING_HPP
#define MODELLING_HPP

#include <mlpack.hpp>
#include <vector>

// Объявления функций
arma::mat drop_columns(arma::mat &dataset, std::vector<int> indices);
float evaluate_dataset(arma::mat dataset, short int target_column_index, short int id_column_index = -1);

#endif // MODELLING_HPP
