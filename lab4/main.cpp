#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
using namespace chrono;

double calcDev(const vector<double>& arr, int start, int end) {
    double mean = 0;
    for (int i = start; i <= end; ++i) {
        mean += arr[i];
    }
    mean /= (end - start + 1);

    double dev = 0;
    for (int i = start; i <= end; ++i) {
        dev += abs(arr[i] - mean);
    }
    return dev;
}

void genParts(const vector<double>& arr, int index, vector<vector<double>>& currPart,
              vector<vector<vector<double>>>& allParts) {
    int n = arr.size();
    if (index == n) {
        allParts.push_back(currPart);
        return;
    }
    for (int i = index; i < n; ++i) {
        vector<double> part(arr.begin() + index, arr.begin() + i + 1);
        currPart.push_back(part);
        genParts(arr, i + 1, currPart, allParts);
        currPart.pop_back();
    }
}

double findBest(const vector<double>& arr, int k, vector<vector<double>>& bestClusters) {
    vector<pair<double, int>> indexedArr;
    for (int i = 0; i < arr.size(); ++i) {
        indexedArr.push_back({arr[i], i});
    }
    sort(indexedArr.begin(), indexedArr.end());

    vector<double> sortedArr;
    for (const auto& p : indexedArr) {
        sortedArr.push_back(p.first);
    }

    vector<vector<vector<double>>> allParts;
    vector<vector<double>> currPart;
    genParts(sortedArr, 0, currPart, allParts);

    double minDev = numeric_limits<double>::max();
    vector<vector<double>> bestPart;

    for (const auto& part : allParts) {
        if (part.size() == k) {
            double currDev = 0;
            for (const auto& clust : part) {
                int clStart = &clust - &part[0];
                currDev += calcDev(sortedArr, clStart, clStart + clust.size() - 1);
            }
            if (currDev < minDev) {
                minDev = currDev;
                bestPart = part;
            }
        }
    }

    // Восстановление исходного порядка для каждого кластера
    bestClusters.clear();
    for (auto& cluster : bestPart) {
        vector<pair<double, int>> indexedCluster;
        for (double num : cluster) {
            for (const auto& p : indexedArr) {
                if (p.first == num) {
                    indexedCluster.push_back(p);
                    break;
                }
            }
        }
        sort(indexedCluster.begin(), indexedCluster.end(),
             [](const pair<double, int>& a, const pair<double, int>& b) {
                 return a.second < b.second;
             });
        vector<double> orderedCluster;
        for (const auto& p : indexedCluster) {
            orderedCluster.push_back(p.first);
        }
        bestClusters.push_back(orderedCluster);
    }

    return minDev;
}

size_t calculateMemoryUsage(const vector<double>& arr, const vector<vector<vector<double>>>& allParts) {
    size_t memoryUsage = 0;

    // Память, занятая входным массивом
    memoryUsage += arr.size() * sizeof(double);

    // Память, занятая всеми частями (allParts)
    for (const auto& part : allParts) {
        for (const auto& cluster : part) {
            memoryUsage += cluster.size() * sizeof(double);
        }
    }

    return memoryUsage;
}

int main() {
    vector<vector<double>> test_cases = {
            {1.0},
            {1.0, 5.0, 8.0, 2.0, 6.0},
            {1.0, 5.0, 8.0, 2.0, 6.0, 3.0, 7.0, 4.0, 10.0, 9.0},
            {1.0, 5.0, 8.0, 2.0, 6.0, 3.0, 7.0, 4.0, 10.0, 9.0, 15.0, -7.0, 22.0, 3.5, 8.8},
            {1.0, 5.0, 8.0, 2.0, 6.0, 3.0, 7.0, 4.0, 10.0, 9.0, 15.0, -7.0, 22.0, 3.5, 8.8, -2.3, 0.9, 13.3, -10.0, 5.5},
            {1.0, 5.0, 8.0, 2.0, 6.0, 3.0, 7.0, 4.0, 10.0, 9.0, 15.0, -7.0, 22.0, 3.5, 8.8, -2.3, 0.9, 13.3, -10.0, 5.5, 6.1, 10.2, -3.5, 0.0, 6.6}
    };
    vector<int> K_values = {1, 2, 3, 4, 5, 6};

    for (size_t i = 0; i < test_cases.size(); ++i) {
        cout << "Test " << i + 1;

        vector<vector<double>> bestClusters;

        // Замер времени выполнения
        auto start = high_resolution_clock::now();
        double minDev = findBest(test_cases[i], K_values[i], bestClusters);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);

        cout << "\nTime: " << duration.count() << " ms\n";
        cout << "SAD: " << minDev << "\n";

        // Подсчет памяти, используемой для разбиений
        vector<vector<vector<double>>> allParts;
        vector<vector<double>> currPart;
        genParts(test_cases[i], 0, currPart, allParts);
        size_t memoryUsage = calculateMemoryUsage(test_cases[i], allParts);
        cout << "Memory used: " << memoryUsage << " bytes\n";

        for (const auto& cluster : bestClusters) {
            cout << "[ ";
            for (double num : cluster) {
                cout << num << " ";
            }
            cout << "] ";
        }
        cout << "\n\n";
    }

    return 0;
}


