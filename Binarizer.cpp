#include "Binarizer.h"
#include "utils.cpp"
#include <chrono>
#include <indicators/cursor_control.hpp>
#include <indicators/progress_bar.hpp>
#include <indicators/block_progress_bar.hpp>

using namespace indicators;

template<typename T>
Binarizer<T>::Binarizer(int n_intervals)
{
    n_thresholds = n_intervals - 1;
}

template<typename T>
void Binarizer<T>::find_thresholds(const arma::mat& dataset)
{
    thresholds.set_size(n_thresholds, dataset.n_cols);

    for (auto col_index = 0; col_index < dataset.n_cols; col_index++)
    {
        arma::vec col = dataset.col(col_index);

        auto min_value = col.min();
        auto max_value = col.max();

        for (auto threshold_index = 0; threshold_index < n_thresholds; threshold_index++)
        {
            thresholds(threshold_index, col_index) =
                min_value + (threshold_index + 1) * (max_value - min_value) / (n_thresholds + 1);
        }
    }
}

template <typename T>
void Binarizer<T>::fit(const arma::mat& dataset, const arma::vec& target)
{
    find_thresholds(dataset);
    optimal_thresholds.set_size(dataset.n_cols);
    arma::vec tmp_threshold_indices = arma::vec(dataset.n_cols);

    show_console_cursor(false);

    BlockProgressBar bar{
        option::BarWidth{80},
        option::Start{"["},
        option::End{"]"},
        option::ForegroundColor{Color::blue},
        option::FontStyles{std::vector<FontStyle>{FontStyle::bold}},
        option::ShowElapsedTime{true},
        option::ShowRemainingTime{true},
    };

    auto progress = 0.0f;
    for (auto combination_index = 0; combination_index < std::pow(n_thresholds, dataset.n_rows); combination_index++)
    {
        bar.set_progress(progress);

        if (bar.is_completed())
            break;

        progress = combination_index / std::pow(n_thresholds, dataset.n_cols) * 1.0f;
        auto combination = combination_index;
        for (auto i=0; i<dataset.n_cols; i++)
        {
            tmp_threshold_indices(i) = thresholds(combination % n_thresholds, i);
            combination /= n_thresholds;
        }

        auto binarized_dataset = transform_with_given_thresholds(dataset, tmp_threshold_indices);

        double score = evaluate_dataset(binarized_dataset, target);

        if (score < best_score)
        {
            best_score = score;
            optimal_thresholds = tmp_threshold_indices;
        }
    }

    show_console_cursor(true);
}

template <typename T>
arma::mat Binarizer<T>::transform_with_given_thresholds(const arma::mat& dataset, const arma::vec& thresholds)
{
    arma::mat binarized_dataset = arma::mat(dataset.n_rows, dataset.n_cols, arma::fill::zeros);

    for (auto col_index=0; col_index < dataset.n_cols; col_index++)
    {
        for(auto row_index=0; row_index < dataset.n_rows; row_index++)
        {
            if (dataset(row_index, col_index) > thresholds(col_index))
                binarized_dataset(row_index, col_index) = 1;
        }
    }

    return binarized_dataset;
}


template<typename T>
arma::mat Binarizer<T>::transform(const arma::mat& dataset)
{
    arma::mat binarized_dataset = arma::mat(dataset.n_rows, dataset.n_cols, arma::fill::zeros);

    for (auto col_index=0; col_index < dataset.n_cols; col_index++)
    {
        for(auto row_index=0; row_index < dataset.n_rows; row_index++)
        {
            if (dataset(row_index, col_index) > optimal_thresholds(col_index))
                binarized_dataset(row_index, col_index) = 1;
        }
    }

    return binarized_dataset;
}

template<typename T>
arma::mat Binarizer<T>::fit_transform(const arma::mat& dataset, const arma::vec& target)
{
    fit(dataset, target);
    return transform(dataset);
}

template<typename T>
arma::vec Binarizer<T>::get_optimal_thresholds()
{
    return optimal_thresholds;
}

template <typename T>
double Binarizer<T>::get_best_score()
{
    return best_score;
}

template <typename T>
arma::mat Binarizer<T>::get_thresholds()
{
    return thresholds;
}
