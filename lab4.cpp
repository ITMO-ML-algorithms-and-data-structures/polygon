#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <cassert>

using namespace std;

//Функция расчета суммы отклонений элементов от среднего значения кластера
double calculate_metric(const vector<double>& cluster) {
    if (cluster.empty()) return 0; //Обработка пустого кластера
    double sum = 0; // 8 байт
    double mean = 0; // 8 байт
    for (double val : cluster) {
        mean += val;
    }
    mean /= cluster.size();
    for (double val : cluster) {
        sum += abs(val - mean);
    }
    return sum;
}

// Поиск лучшего разбиения
void findBestClustering(const vector<double>& data, int k, int index, vector<vector<double>>& currentClusters, double currentMetric, double& minMetric, vector<vector<double>>& bestClusters) {
    // data - N*8 байт, index - 4 байта, currentMetric - 8 байт
    // Базовый вариант: все точки данных, назначенные кластерам
    if (index == data.size()) {
        if (currentClusters.size() == k) { //Проверка, есть ли у нас k кластеров
            if (currentMetric < minMetric) {
                minMetric = currentMetric;
                bestClusters = currentClusters;
            }
        }
        return;
    }

    // Итерируемся по существующим кластерам и добавляем текущий элемент
    for (size_t i = 0; i < currentClusters.size(); ++i) {
        vector<vector<double>> nextClusters = currentClusters; // nextClusters - max N*8 байт
        nextClusters[i].push_back(data[index]);
        double nextMetric = currentMetric + calculate_metric(nextClusters[i]) - calculate_metric(currentClusters[i]); //Обновляем метрику // nextMetric - 8 байт
        findBestClustering(data, k, index + 1, nextClusters, nextMetric, minMetric, bestClusters);
    }

    // Создаём новый кластер, если это возможно
    if (currentClusters.size() < k) {
        vector<vector<double>> nextClusters = currentClusters; // nextClusters - max N*8 байт
        nextClusters.push_back({data[index]});
        findBestClustering(data, k, index + 1, nextClusters, currentMetric, minMetric, bestClusters);
    }
}
// Сложность O(k^N)

vector<vector<double>> clusterData(const vector<double>& data, int k) {
    // k - 4 байта
    vector<vector<double>> bestClusters; // max N*8 байт
    vector<vector<double>> currentClusters; // max N*8 байт
    double minMetric = numeric_limits<double>::infinity(); // Инициализируем максимальное значение метрики minMetric - 8 байт

    findBestClustering(data, k, 0, currentClusters, 0.0, minMetric, bestClusters);
    return bestClusters;
}

void print_vector(const vector<double>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i < vec.size() - 1 ? ", " : "");
    }
    cout << "] ";
}

void test() {
    using namespace chrono;

    auto runTest = [&](const vector<double>& input, int k, int expectedClusters, bool checkClusterSize = true) {
        auto start = high_resolution_clock::now();
        vector<vector<double>> result = clusterData(input, k);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        cout << "Input: ";
        print_vector(input);
        cout << "k: " << k << endl;
        cout << "Resulting Clusters:\n";
        for (const auto& cluster : result) {
            print_vector(cluster);
        }
        cout << endl;

        assert(result.size() == expectedClusters);
        if (checkClusterSize) {
            for (const auto& cluster : result) {
                assert(!cluster.empty());
            }
        }
        cout << "Time: " << duration.count() / 1e6 << " seconds\n\n";

    };

    runTest({1, 2, 3, 4, 5, 6}, 2, 2);
    runTest({1, 10, 9, 2, 3, 8}, 2, 2);
    runTest({99.5, -1.1, 101}, 2,2);
    runTest({1.0, 2.0, 3.0, 7.0, 3.2, 4.1, 5.2, 4.9, 88}, 8, 8);
    runTest({10.0, 20.0, 30.0, 40.0, 50.0, 90.5, 12.0, 32.9, 123.0, 35.8}, 8, 8); // k=8 N=10
    runTest({1.0, 2.5, 3.5, 8.0, 20.0, 25.0, 30.0, 1.0, -1.9, 12.3, 1.7, 13.77, 333.0, 14.0, 97.0}, 8, 8); // Массив с числами с разными знаками N = 15
    runTest({-1.5, 0.0, 1.7, 0.6, 0.9, 8.0, -1.0, 4.0, 5.0, 7.0, 99.0, -12.0, -30.9, -20.5, 40.0, 0.3, 0.45, 6.24, 5.05, 9.0}, 8, 8);// Массив с большими значениями N=20
    runTest({1.5, 0.0, 1.7, 0.6, 0.9, 8.0, -1.0, 4.0, 5.0, 7.0, 99.0, -12.0, -30.9, -20.5, 40.0, 0.3, 0.45, 6.24, 5.05, 9.0, 1.5, -12.0, 4.0, 3.0, 5.0}, 8, 8);// N=25
}


int main() {

    test();

    return 0;
}

