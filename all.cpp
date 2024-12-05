#include <vector>
#include <limits> //библиотека с макс/мин значениями
#include <unordered_map> //библиотека для использования хэш-таблиц
#include <queue> //библиотека для работы с очередями
#include <cmath> //библиотека для математических функций
#include <cstdlib> //библиотека для управления памятью
#include <iostream>
#include <chrono>  // библиотека для контроля времени выполнения

// генерация всех возможных масок для 4 кластеров
std::vector<std::vector<char>> generate_all_masks(int size) {
    const int n_clusters = 4;

    std::vector<std::vector<char>> all_masks;
    std::vector<char> mask(size, 0);

    int total_combinations = std::pow(n_clusters, size);

    for (int i = 0; i < total_combinations; i++) {
        all_masks.push_back(mask);

        for (int j = size - 1; j >= 0; j--) {
            if (mask[j] < n_clusters - 1) {
                mask[j]++;
                break;
            } else {
                mask[j] = 0;
            }
        }
    }
    return all_masks;
}

// расчёт метрики для кластера
float calculate_cluster_metric(const std::vector<int>& cluster) {
    if (cluster.empty()) return 0;
    float mean = 0;
    for (int value : cluster) {
        mean += value;
    }
    mean /= cluster.size();
    
    float metric = 0;
    for (int value : cluster) {
        metric += std::abs(value - mean);  // суммируем отклонения от среднего
    }
    return metric;
}

// расчёт общей метрики
float calculate_total_metric(const std::vector<std::vector<int>>& clusters) {
    float total_metric = 0;
    for (const std::vector<int>& cluster : clusters) {
        total_metric += calculate_cluster_metric(cluster);
    }
    return total_metric;
}

// главная функция для 4 кластеров
std::vector<std::vector<int>> cluster_array(const std::vector<int>& arr, float& best_metric, int time_limit_seconds = 3600) {
    const int n_clusters = 4;
    int size = arr.size();

    std::vector<std::vector<char>> masks = generate_all_masks(size);

    best_metric = std::numeric_limits<float>::max();
    std::vector<std::vector<int>> best_clusters;

    auto start_time = std::chrono::steady_clock::now(); // запоминаем время начала

    for (const std::vector<char>& mask : masks) {
        std::vector<std::vector<int>> clusters(n_clusters);

        // формируем кластеры
        for (int i = 0; i < size; i++) {
            clusters[mask[i]].push_back(arr[i]);
        }

        // пропускаем комбинации, где есть пустые кластеры
        bool valid = true;
        for (const auto& cluster : clusters) {
            if (cluster.empty()) {
                valid = false;
                break;
            }
        }
        if (!valid) continue;

        float current_metric = calculate_total_metric(clusters);

        if (current_metric < best_metric) {
            best_metric = current_metric;
            best_clusters = clusters;
        }

        // проверяем время выполнения
        auto current_time = std::chrono::steady_clock::now();
        std::chrono::duration<float> elapsed_time = current_time - start_time;
        if (elapsed_time.count() > time_limit_seconds) {
            std::cout << "Достигнуто ограничение по времени. Завершение." << std::endl;
            break;
        }
    }

    return best_clusters;
}

// пример использования
int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    float best_metric;

    std::vector<std::vector<int>> result = cluster_array(arr, best_metric);

    // печать результата
    std::cout << "Лучшая метрика: " << best_metric << std::endl;
    std::cout << "Лучшие кластеры:" << std::endl;
    for (const auto& cluster : result) {
        std::cout << "{ ";
        for (int val : cluster) {
            std::cout << val << " ";
        }
        std::cout << "}" << std::endl;
    }

    return 0;
}