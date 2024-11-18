#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// Функция для вычисления метрики
double calculate_cluster_distance(const vector<double>& cluster) {

    double sum = 0; //8 bytes
    double mean = 0; //8 bytes

    //O(cluster_size)
    for (double value : cluster) {
        mean += value;
    }

    mean /= cluster.size();

    //O(cluster_szie)
    for (double value : cluster) {
        sum += abs(value - mean);
    }

    return sum;
}

// Функция для полного перебора всех комбинаций кластеров
vector<vector<double>> clusterize(const vector<double>& arr, int k) {

    int n = arr.size();

    // если количество кластеров больше, чем количество элементов

    if (k > n){

     return {};
    } 

    vector<vector<double>> best_clusters(k); //O(k) 8n bytes
    double min_distance = numeric_limits<double>::max();

    // Перебираем все возможные комбинации кластеров O(9^n)
    for (int i = 0; i < pow(k, n); ++i) {

        vector<vector<double>> clusters(k); //O(k) 8n bytes
        vector<int> number(n); //O(n) 8n bytes

        // Генерация индексов кластеров O(n)
        for (int j = 0; j < n; ++j) {
            number[j] = (i / static_cast<int>(pow(k, j))) % k; // Находим кластер для элемента j
        }

        // Разбиваем на кластеры O(n)
        for (int j = 0; j < n; ++j) {
            clusters[number[j]].push_back(arr[j]);
        }

        // O(k)
        bool valid_clusters = all_of(clusters.begin(), clusters.end(), [](const vector<double>& cluster) {
            return !cluster.empty();
        });

        // Вычисляем общую сумму расстояний для всех кластеров
        double total_distance = 0;

        //O(n)
        if (valid_clusters) {

            for (const auto& cluster : clusters) {
                total_distance += calculate_cluster_distance(cluster);
            }

            // Обновляем лучшие кластеры
            if (total_distance < min_distance) {
                min_distance = total_distance;
                best_clusters = clusters;
            }
        }
    }

    return best_clusters;
}

#include <gtest/gtest.h>

#include <gtest/gtest.h>

// Тестирование на случай, когда k больше n
TEST(Tests, NumberOfClustersGreaterThanElements) {
    vector<double> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    auto clusters = clusterize(arr, 9);

    ASSERT_TRUE(clusters.empty());
}

// Тестирование на случай, когда k равно n (каждый элемент в своем кластере)
TEST(Tests, NumberOfClustersEqualToElements) {
    vector<double> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto clusters = clusterize(arr, 9);

    // Ожидаем, что каждый элемент будет в своем кластере
    vector<vector<double>> expected_clusters = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}};
    ASSERT_EQ(clusters, expected_clusters);
}

// Тестирование на случай, когда есть повторяющиеся элементы и k меньше количества уникальных элементов
TEST(Tests, ClustersWithRepeatedElements) {
    vector<double> arr = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto clusters = clusterize(arr, 9);

    // Ожидаем, что 2 будет в одном кластере
    vector<vector<double>> expected_clusters = {{1}, {2, 2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}};  // Можно разное распределение
    ASSERT_EQ(clusters.size(), expected_clusters.size());

    // Проверка содержимого
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::sort(clusters[i].begin(), clusters[i].end());
        std::sort(expected_clusters[i].begin(), expected_clusters[i].end());
        ASSERT_EQ(clusters[i], expected_clusters[i]);
    }
}

// Основная функция для запуска тестов и основной логики
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    vector<double> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Данные
    int k = 9; // Количество кластеров

    vector<vector<double>> clusters = clusterize(arr, k);

    for (int i = 0; i < k; ++i) {
        cout << "Cluster " << i + 1 << ": ";
        for (double value : clusters[i]) {
            cout << value << " ";
        }
        cout << endl;
    }

    return RUN_ALL_TESTS();
}