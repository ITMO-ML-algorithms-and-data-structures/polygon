#ifndef BINARIZER_H
#define BINARIZER_H

#include <limits>

template<typename T>
class Binarizer {
private:
    arma::mat thresholds{};
    arma::vec optimal_thresholds{};
    int n_thresholds = 6;
    double best_score = std::numeric_limits<T>::infinity();
public:
    explicit Binarizer(int k);

    void find_thresholds(const arma::mat& dataset);

    void fit(const arma::mat& dataset, const arma::vec& target);

    arma::mat transform(const arma::mat& dataset);

    arma::mat transform_with_given_thresholds(const arma::mat& dataset, const arma::vec& thresholds);

    arma::mat fit_transform(const arma::mat& dataset, const arma::vec& target);

    arma::vec get_optimal_thresholds();

    double get_best_score();

    arma::mat get_thresholds();
};

#include "Binarizer.cpp"

#endif
