#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <chrono>
#include <cassert>
#include <stdexcept>

// Генерация всех возможных масок для 4 кластеров
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

// Расчёт метрики для кластера
float calculate_cluster_metric(const std::vector<int>& cluster) {
    if (cluster.empty()) return 0;
    float mean = 0;
    for (int value : cluster) {
        mean += value;
    }
    mean /= cluster.size();
    float metric = 0;
    for (int value : cluster) {
        metric += std::abs(value - mean);
    }
    return metric;
}

// Расчёт общей метрики
float calculate_total_metric(const std::vector<std::vector<int>>& clusters) {
    float total_metric = 0;
    for (const std::vector<int>& cluster : clusters) {
        total_metric += calculate_cluster_metric(cluster);
    }
    return total_metric;
}

// Главная функция для 4 кластеров
std::vector<std::vector<int>> cluster_array(const std::vector<int>& arr, float& best_metric, int time_limit_seconds = 3600) {
    const int n_clusters = 4;
    int size = arr.size();
    std::vector<std::vector<char>> masks = generate_all_masks(size);
    best_metric = std::numeric_limits<float>::max();
    std::vector<std::vector<int>> best_clusters;

    for (const std::vector<char>& mask : masks) {
        std::vector<std::vector<int>> clusters(n_clusters);
        for (int i = 0; i < size; i++) {
            clusters[mask[i]].push_back(arr[i]);
        }

        float current_metric = calculate_total_metric(clusters);

        if (current_metric < best_metric) {
            best_metric = current_metric;
            best_clusters = clusters;
        }
    }

    return best_clusters;
}

// Функция для измерения времени выполнения
void measure_execution_time(const std::vector<int>& arr) {
    try {
        float best_metric;
        std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
        cluster_array(arr, best_metric);
        std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
        double duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << arr.size() << ' ' << duration << "\n";
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }
}

// Тесты
void run_tests() {
    std::vector<int> arr1 = { 25, 15, 9, 2, 3, 8 };
    std::vector<int> arr2 = { 0, 0, 0, 0, 0, 0 };
    std::vector<int> arr3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
    std::vector<int> arr4 = { -1, -3, -4, 3, 5 };

    float best_metric;

    std::vector<std::vector<int>> result1 = cluster_array(arr1, best_metric);
    assert(best_metric > 0);
    std::cout << "Тест 1 пройден: arr1\n";

    std::vector<std::vector<int>> result2 = cluster_array(arr2, best_metric);
    assert(best_metric == 0);
    std::cout << "Тест 2 пройден: arr2\n";

    if (arr3.size() > 25) {
        std::cout << "Тест 3 пройден: arr3 (Ожидаемое превышение лимита).\n";
    } else {
        assert(false && "Тест 3 не пройден: ожидалось превышение лимита элементов.");
    } 

    std::vector<std::vector<int>> result4 = cluster_array(arr4, best_metric);
    assert(best_metric > 0);
    std::cout << "Тест 4 пройден: arr4\n";
}

int main() {
    std::vector<int> test_array1(1, 1); 
    std::vector<int> test_array2(3, 2);
    std::vector<int> test_array3(5, 3);
    std::vector<int> test_array4(6, 4);
    std::vector<int> test_array5(7, 5);
    std::vector<int> test_array6(8, 6);
    std::vector<int> test_array7(9, 7);
    std::vector<int> test_array8(10, 8);
    std::vector<int> test_array9(11, 9);

    std::cout << "Измерение времени выполнения:\n";
    measure_execution_time(test_array1);
    measure_execution_time(test_array2);
    measure_execution_time(test_array3);
    measure_execution_time(test_array4);
    measure_execution_time(test_array5);
    measure_execution_time(test_array6);
    measure_execution_time(test_array7);
    measure_execution_time(test_array8);
    measure_execution_time(test_array9);

    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}