#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <chrono>
#include <algorithm>
#include <numeric> 

double best_metric; 
std::vector<std::vector<double>> final_clusters; 
int required_clusters; 

double compute_cluster_metric(const std::vector<double>& cluster) {
    if (cluster.empty()) return 0.0;

    double mean = std::accumulate(cluster.begin(), cluster.end(), 0.0) / cluster.size();
    double metric = 0.0;

    for (double value : cluster) {
        metric += std::abs(value - mean);
    }

    return metric;
}

void generate_clusters(const std::vector<double>& data, int index, 
                       std::vector<std::vector<double>>& clusters) {
    if (index == data.size()) {
        if (clusters.size() == required_clusters) {
            double current_metric = 0.0;
            for (const auto& cluster : clusters) {
                current_metric += compute_cluster_metric(cluster);
            }
            if (current_metric < best_metric) {
                best_metric = current_metric;
                final_clusters = clusters; 
            }
        }
        return;
    }

    for (size_t i = 0; i < clusters.size(); ++i) {
        clusters[i].push_back(data[index]); 
        generate_clusters(data, index + 1, clusters); 
        clusters[i].pop_back(); 
    }

    if (clusters.size() < required_clusters) {
        clusters.push_back({ data[index] }); 
        generate_clusters(data, index + 1, clusters); 
        clusters.pop_back(); 
    }
}

void check_results(const std::vector<std::vector<double>>& actual, 
                   const std::vector<std::vector<double>>& expected, 
                   const std::string& test_name) {
    if (actual == expected) {
        std::cout << test_name << " - Passed\n";
    } else {
        std::cout << test_name << " - Failed\n";
    }
}

void run_test(const std::vector<double>& data, int cluster_count, 
              const std::vector<std::vector<double>>& expected, 
              const std::string& test_name) {
    required_clusters = cluster_count;
    best_metric = std::numeric_limits<double>::infinity();
    std::vector<std::vector<double>> clusters;

    auto start_time = std::chrono::high_resolution_clock::now();
    generate_clusters(data, 0, clusters);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;
    std::cout << test_name << " - Execution time: " << duration.count() << " seconds\n";
    
    check_results(final_clusters, expected, test_name);

}

int main() {
    // Тест 1: Массив из 10 элементов
    std::vector<double> input1 = {1.5, 3.2, -2.4, 7.1, -5.8, 4.3, 0.9, -1.2, 8.5, 2.0};
    std::vector<std::vector<double>> expected1 = {{1.5, 0.9, 2}, {3.2, 4.3}, {-2.4}, {7.1}, {-5.8}, {-1.2}, {8.5}};
    run_test(input1, 7, expected1, "Test 1: 10 elements into 7 clusters");

    // Тест 2: Массив из 6 одинаковых элементов
    std::vector<double> input2 = {-3, -3, -3, -3, -3, -3, -3};
    std::vector<std::vector<double>> expected2 = {{-3}, {-3}, {-3}, {-3}, {-3}, {-3}, {-3}};
    run_test(input2, 7, expected2, "Test 2: 6 identical elements into 7 clusters");

    // Тест 3: Массив из 25 элементов
    std::vector<double> input3 = {-1.2, 2, -3.1, 4, -5.3, 6, -7.8, 8, -9.6, 10,
                                   -11.5, 12, -13.7, 14, -15.2, 16, -17.4, 18, -19.1, 20,
                                   -21.3, 22, -23.8, 24, -25.9};
    std::vector<std::vector<double>> expected3 = {{-1.2, -3.1, -5.3}, {2, 4, 6}, {8, 10, 12}, 
                                                   {14, 16}, {-7.8, -9.6, -11.5}, {-13.7, -15.2}, 
                                                   {-17.4, -19.1, -21.3, -23.8, -25.9}};
    run_test(input3, 7, expected3, "Test 3: 25 elements into 7 clusters");

    return 0;
}
