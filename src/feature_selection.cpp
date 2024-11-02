#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#define ARMA_DONT_PRINT_ERRORS
#include <mlpack.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>
#include <armadillo>

#include <iostream>
#include <vector>

#include "modelling.cpp"
#include "reading.cpp"

#define LOG(X) std::cout << X << "\n";

// идея такая - возьмем те, что коррелируют с таргетом больше чем на |mincorr|
std::vector<int> correlation_fiter(const arma::mat& dataset, int target, double mincorr) {
    arma::mat correlation = arma::cor(dataset);
    std::vector<int> features;

    for (size_t i = 0; i < dataset.n_cols; ++i) {
        if (i != target && std::abs(correlation(target, i)) >= mincorr) {
            features.push_back(i);
        }
    }

    return features;
}

float baseline(const arma::mat& dataset, int target_idx) {
    return evaluate_dataset(dataset, target_idx);
}

// оставляем в дс только те фичи, что нам нужны
arma::mat select(const arma::mat& dataset, const std::vector<int>& features) {
    arma::uvec indices(features.size());
    for (size_t i = 0; i < features.size(); ++i) {
        indices(i) = features[i];
    }
    return dataset.cols(indices);
}


int feature_selection(const char* path) {
    arma::mat dataset = loadDataset(path);
    LOG("ds rows:" << dataset.n_rows << " cols:" << dataset.n_cols);

    int target = dataset.n_cols - 1;
    float baseline_score = baseline(dataset, target);

    std::vector<int> filtered_features = correlation_fiter(dataset, target, 0.2);
    int num_features = filtered_features.size();
    if (num_features < 2) {
        return -1;
    }

    float best_score = 1;
    std::vector<int> best_features;

    int counter = 0;
    for (int mask = 1; mask < (1 << num_features); ++mask) {
        std::vector<int> features;
        
        for (int j = 0; j < num_features; ++j) {
            if (mask & (1 << j)) {
                features.push_back(filtered_features[j]);
            }
        }

        if (features.size() < 2) {
            continue;
        }

        counter++;

        float score = evaluate_dataset(select(dataset, features), target, 0);

        if (score <= (baseline_score * .9f) && score > 0) {
            if (score < best_score) {
                best_score = score;
                best_features = features;
            }
        }
    }
    
    LOG("baseline \t>" << baseline_score);
    LOG("best \t\t>" << best_score);
    LOG("total checked \t>" << counter);

    std::cout << "selected features idxs >";
    for (int idx : best_features) {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    return 0;
}

void run_tests() {
    feature_selection("data/beer_quality.csv");
}

int main() {
    run_tests();
    return 0;

    /* есть мааааленький трабл :
     `warning: solve(): system is singular; attempting approx solution`
     
     гпт говорит что это `...Armadillo указывает на то,
     что в процессе решения системы линейных уравнений функция solve()
     обнаружила сингулярную матрицу, что делает ее решение нестабильным или невозможным.
     Это может происходить, когда матрица не имеет полного ранга, 
     что приводит к проблемам при решении уравнений...`, но вроде как оно и нормально считается
    */
    // запускать - >/usr/bin/g++ -std=c++17 -I/usr/include -I/usr/lib -fdiagnostics-color=always -g /algs/polygon/src/extra_materials/feature_selection.cpp -o /algs/polygon/src/extra_materials/feature_selection -larmadillo -fopenmp 


    /* ps: вывод вот такой..
        baseline        >8.80457e-21
        total checked   >11
        best            >1.2326e-31
        selected features idxs >1 2 
     получается, что после оптимизаций у меня метрика выше чем бейзлайн.. ну типо на несколько порядков.. и выше на 20%. ну такой вот датасет, ну такой вот таск, че поделать

    */
}