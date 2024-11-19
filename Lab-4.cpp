#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Вычисление среднего значения подмассива
double srznach(const vector<double>& cluster) {
    double sum = 0;
    for (double val : cluster){
        sum += val;
    }
    if (cluster.empty()){
        return 0;
    }
    else{
        return sum / cluster.size();
    }
}

// Вычисление суммы расстояний до среднего
double lnsr(const vector<double>& cluster) {
    double mean = srznach(cluster);
    double sum = 0;
    for (double val : cluster){
        sum += abs(val - mean);
    }
    return sum;
}

// Разбиение массива на два кластера с минимизацией метрики
pair<vector<double>, vector<double>> klast(const vector<double>& arr) {
    int n = arr.size();
    double minMetric = numeric_limits<double>::max();
    pair<vector<double>, vector<double>> bestClusters;

    // Перебираем все разбиения
    for (int mask = 1; mask < (1 << n) - 1; ++mask) {
        vector<double> cluster1, cluster2;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)){
                cluster1.push_back(arr[i]);
            }
            else{
                cluster2.push_back(arr[i]);
            }
        }

        // Минимизируем сумму метрик
        double totalMetric = lnsr(cluster1) + lnsr(cluster2);
        if (totalMetric < minMetric) {
            minMetric = totalMetric;
            bestClusters = {cluster1, cluster2};
        }
    }

    return bestClusters;
}

// Вывод кластеров
void prClusters(const pair<vector<double>, vector<double>>& clusters) {
    cout << "[";
    for (size_t i = 0; i < clusters.first.size(); ++i) {
        if (i > 0){
            cout << ", ";
        }
        cout << clusters.first[i];
    }
    cout << "], [";
    for (size_t i = 0; i < clusters.second.size(); ++i) {
        if (i > 0){
            cout << ", ";
        }
        cout << clusters.second[i];
    }
    cout << "]" << endl;
}

int main() {
    vector<vector<double>> testCases = {
        {1, 2, 3, 4, 5, 6},
        {1, 10, 9, 2, 3, 8},
        {99.5, -1.1, 101}
    };

    for (const auto& testCase : testCases) {
        cout << "Input: ";
        for (double val : testCase){
            cout << val << " ";
        }
        cout << endl;

        auto clusters = klast(testCase);

        cout << "Clusters: ";
        prClusters(clusters);
        cout << endl;
    }

    return 0;
}

