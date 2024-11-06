#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <limits>
#include <numeric> // Для std::accumulate

using namespace std;

// Функция для вычисления стоимости кластера
double calculate_absolute_dist(const vector<double>& cluster) {
    if (cluster.empty()) { // Сложность: O(1)
        return 0.0;
    }

    double avg_mean = accumulate(cluster.begin(), cluster.end(), 0.0) / cluster.size(); // Используем accumulate для нахождения суммы
    double dist = 0;

    for (double num : cluster) { // Сложность: O(M), где M — количество элементов в текущем кластере
        double diff = abs(num - avg_mean); // Память: О(1)
        dist += diff; // Память: O(1)
    }

    return dist; // Память: O(1)
}

// Функция для генерации кластеров
void generate_clusters(const vector<double>& arr, int start, int k, vector<vector<double>>& current_clusters,
                       vector<vector<double>>& best_clusters, double& min_dist) {
    int n = arr.size(); // Память: O(1) - получение размера массива

    // Если достигли конца массива и у нас осталось нужное количество кластеров
    if (start == n) {
        if (current_clusters.size() == k) {
            double total_dist = 0; // Память: O(1)
            for (const auto& cluster : current_clusters) {
                total_dist += calculate_absolute_dist(cluster); // Сложность: O(M_i), где M_i — количество элементов в i-м кластере
            }

            if (total_dist < min_dist) {
                min_dist = total_dist; // Память: O(1)
                best_clusters = current_clusters; // Память: O(k), где k - количество элементов в текущем кластере
            }
        }
        return;
    }

    // Добавляем текущий элемент в существующие кластеры
    for (int i = 0; i < current_clusters.size(); ++i) { // Сложность: O(K), где K — текущее количество кластеров
        current_clusters[i].push_back(arr[start]); // Память: O(1), добавление элемента
        generate_clusters(arr, start + 1, k, current_clusters, best_clusters, min_dist);
        current_clusters[i].pop_back(); // Убираем элемент после рекурсивного вызова
    }// Мы можем добавить текущий элемент в любой из существующих кластеров или создать новый,
    // что приводит к 2^N возможным комбинациям распределения элементов.

    // Если еще не достигли максимального количества кластеров, создаем новый кластер с текущим элементом
    if (current_clusters.size() < k) {
        current_clusters.push_back(vector<double>{arr[start]}); // Память: O(1), создание нового кластера
        generate_clusters(arr, start + 1, k, current_clusters, best_clusters, min_dist);
        current_clusters.pop_back(); // Убираем последний кластер для следующей итерации
    }
}
// Сложность: O(N*2^N)
// Память: O(N)

// функция кластеризации
void cluster_array(const vector<double>& arr, int k = 5) { // Устанавливаем k по умолчанию равным 5
    vector<vector<double>> best_clusters; // Для хранения лучшего разбиения
    vector<vector<double>> current_clusters; // Для хранения текущих кластеров

    double min_dist = numeric_limits<double>::max(); // Инициализация большим значением

    generate_clusters(arr, 0, k, current_clusters, best_clusters, min_dist);

    for (const auto& cluster : best_clusters) {
        cout << "[ ";
        for (double num : cluster) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

void run_tests() {
    cout << "K == 5" << endl;

    vector<vector<double>> test_cases = {
        {1,2,5,4,3,7,9,8,10,6},
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {99,-1.1,101},
        {1,2},
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {1.1,1.2,1.5, 2.1,1.5,2.3, 3.4,3.9, 3.9,4.0,4.1, 5.9, 5.8, 5.9, 11.0},
        {0,0,0,0,0},
        {-1,-2,-3,1,1,1,1,1,1,1,1,1,1,-9,-10},
        {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
        {5,-3,-2,-4,-1},
        {6,5,10,9,1,2,8,7,3,4},
        {1,9,2,10,3},
        {5.9,1.1,1.2,1.5},
        {0,0,0},
        {-1,-2,-3},
        {1.5,-2.3,-3.8,-4.5,-5.6},
        {10.5,-10.2,-20.3,-30.4,-40}
    };

    for (const auto& test_case : test_cases) {
        cout << "arr = [";
        for (size_t i = 0; i < test_case.size(); ++i) {
            cout << test_case[i];
            if (i != test_case.size() - 1) cout << ", ";
        }
        cout << "]" << endl;

        auto start_time = chrono::high_resolution_clock::now();

        cluster_array(test_case);

        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end_time - start_time;

        cout << "Execution time: " << elapsed.count() << " seconds" << endl;
        cout << endl;
    }
}

int main() {
    run_tests();

    return 0;
}
