#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

// Вычисление среднего значения подмассива
double average(const vector<double>& cluster) {
    double sum = 0;
    for (double val : cluster) {
        sum += val;
    }
    if (cluster.empty()) {
        return 0;
    }
    return sum / cluster.size();
}

// Метрика - сумма абсолютных отклонений от среднего
double lnsr(const vector<double>& cluster) {
    double mean = average(cluster);
    double sum = 0;
    for (double val : cluster) {
        sum += abs(val - mean);
    }
    return sum;
}

// Функция для генерации следующего разбиения с использованием битовых масок
bool next_partition(vector<int>& partition, int k) {
    int n = partition.size();
    int i = n - 1;
    while (i >= 0 && partition[i] == k - 1) {
        --i;
    }
    if (i < 0) {
        return false;  // Все разбиения перебраны
    }
    ++partition[i];
    fill(partition.begin() + i + 1, partition.end(), partition[i]);
    return true;
}

// Основной алгоритм кластеризации с жадной оптимизацией
vector<vector<double>> klast(const vector<double>& arr, int k = 6, int max_iterations = 100) {
    int n = arr.size();
    if (n < k) {
        throw invalid_argument("Количество кластеров не может быть больше количества элементов в массиве");
    }

    // Начальная кластеризация с помощью случайных разбиений
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, k - 1);

    vector<int> partition(n);
    for (int i = 0; i < n; ++i) {
        partition[i] = dis(gen);
    }

    vector<vector<double>> bestClusters(k);
    double minMetric = numeric_limits<double>::max();

    // Главный цикл, пытаемся улучшить разбиение
    for (int iter = 0; iter < max_iterations; ++iter) {
        vector<vector<double>> clusters(k);
        for (int i = 0; i < n; ++i) {
            clusters[partition[i]].push_back(arr[i]);
        }

        // Проверка текущей метрики
        double totalMetric = 0;
        for (const auto& cluster : clusters) {
            totalMetric += lnsr(cluster);
        }

        if (totalMetric < minMetric) {
            minMetric = totalMetric;
            bestClusters = clusters;
        }

        // Перераспределение элементов между кластерами
        for (int i = 0; i < n; ++i) {
            double bestMetric = numeric_limits<double>::max();
            int bestCluster = partition[i];

            // Пробуем переместить элемент в каждый кластер и смотрим на изменение метрики
            for (int j = 0; j < k; ++j) {
                if (j != partition[i]) {
                    partition[i] = j;
                    vector<vector<double>> newClusters(k);
                    for (int l = 0; l < n; ++l) {
                        newClusters[partition[l]].push_back(arr[l]);
                    }

                    double newMetric = 0;
                    for (const auto& cluster : newClusters) {
                        newMetric += lnsr(cluster);
                    }

                    // Если новая метрика лучше, то обновляем
                    if (newMetric < bestMetric) {
                        bestMetric = newMetric;
                        bestCluster = j;
                    }
                }
            }

            partition[i] = bestCluster;
        }
    }

    // Создание финальных кластеров с наименьшей метрикой
    vector<vector<double>> final_clusters(k);
    for (int i = 0; i < n; ++i) {
        final_clusters[partition[i]].push_back(arr[i]);
    }

    return final_clusters;
}

// Вывод кластеров
void printClusters(const vector<vector<double>>& clusters) {
    for (size_t i = 0; i < clusters.size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << "[";
        for (size_t j = 0; j < clusters[i].size(); ++j) {
            if (j > 0) {
                cout << ", ";
            }
            cout << clusters[i][j];
        }
        cout << "]";
    }
    cout << endl;
}

int main() {
    vector<vector<double>> testCases = {
            {0, -16, 3, 1, -10, 20, 1.05, 17, 2, 35, -20, 3.5, 5, -11, 0.5, 11, 12, -21, -1, -5 -11.1, 30.1, 24, 60.6, 11.051}
    };

    for (const auto& testCase : testCases) {
        cout << "Input: ";
        for (double val : testCase) {
            cout << val << " ";
        }
        cout << endl;

        auto start = chrono::high_resolution_clock::now();
        auto clusters = klast(testCase, 6);
        auto end = chrono::high_resolution_clock::now();

        cout << "Кластеры: ";
        printClusters(clusters);

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "Затраченное время: " << duration << " микросекунд" << endl;
    }

    return 0;
}