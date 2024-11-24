#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
#include <math.h>
#include <chrono>

using namespace std; 
using namespace std::chrono; 


// Функция для расчета метрики (суммы абсолютных отклонений)
double calculate_metric(const vector<double>& cluster) {
    if (cluster.empty()) {
        return 0.0;
    }
    double mean = accumulate(cluster.begin(), cluster.end(), 0.0) / cluster.size();
    double metric = 0.0;
    for (double value : cluster) {
        metric += abs(value - mean);
    }
    return metric;
}

int main() {

    auto start = high_resolution_clock::now();
   
    vector<double> arr = { -2.38, 754.0, 3.0,864,345, 670, 765.0854, -268.89, 86, 4.88, 55, 88, 23};
    int k = 4;

    int n = arr.size();
    vector<vector<double>> best_clustering;
    double min_metric = numeric_limits<double>::max();

    // Перебор всех возможных комбинаций кластеров
    for (int i = 0; i < pow(k, n); ++i) {
        vector<vector<double>> clustering(k);
        int temp = i;
        for (int j = 0; j < n; ++j) {
            clustering[temp % k].push_back(arr[j]);
            temp /= k;
        }

        // Проверка на пустые кластеры
        bool valid_clustering = true;
        for (const auto& cluster : clustering) {
            if (cluster.empty()) {
                valid_clustering = false;
                break;
            }
        }

        if (valid_clustering) {
            double current_metric = 0.0;
            for (const auto& cluster : clustering) {
                current_metric += calculate_metric(cluster);
            }

            if (current_metric < min_metric) {
                min_metric = current_metric;
                best_clustering = clustering;
            }
        }
    }

    // Вывод результата
    std::cout << "[";
    for (size_t i = 0; i < best_clustering.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < best_clustering[i].size(); ++j) {
            std::cout << best_clustering[i][j] << (j == best_clustering[i].size() - 1 ? "" : ", ");
        }
        std::cout << "]" << (i == best_clustering.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << duration.count() << endl; 

    return 0;

}
