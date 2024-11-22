#include <mlpack.hpp>
#include <iostream>

#include "Binarizer.h"

int main()
{
    arma::mat dataset;
    mlpack::data::DatasetInfo info;
    mlpack::data::Load("../data/yacht_hydrodynamics.csv", dataset, info, true, false);

    arma::mat X = dataset.cols(0, 5);
    arma::mat y = dataset.col(6);

    Binarizer<double> binarizer = Binarizer<double>(6);

    binarizer.fit(X, y);
    arma::mat binarized_dataset = binarizer.transform(X);
    std::cout << "Best score MSE:" << binarizer.get_best_score() << std::endl;

    print_matrix(binarizer.get_optimal_thresholds());
    std::cout << std::endl;
    print_matrix(binarized_dataset);
}