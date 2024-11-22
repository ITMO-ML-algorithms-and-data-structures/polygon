#ifndef MODELLING_H
#define MODELLING_H

#include <armadillo>
#include <vector>

arma::mat drop_columns(arma::mat &dataset, std::vector<int> indices);
float evaluate_dataset(arma::mat dataset, short int target_column_index, short int id_column_index);


#endif //MODELLING_H
