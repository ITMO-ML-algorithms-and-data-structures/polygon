#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <limits>

using namespace std;

double calculateMean(const vector<double>& cluster) {
    if (cluster.empty()) {
        return 0.0; 
    }

    double sum = 0.0;
    for (double num : cluster) {
        sum += num;
    }
    return sum / cluster.size();
}

double calculateMetric(const vector<double>& cluster) {
    if (cluster.empty()) {
        return 0.0;
    }
    double mean = calculateMean(cluster);
    double metric = 0.0;
    for (double num : cluster) {
        metric += fabs(num - mean);
    }
    return metric;
}

void generateClusters(vector<vector<double>>& clusters, const vector<double>& remaining, int k, double& bestMetric, vector<vector<double>>& bestClusters) {
    if (remaining.empty()) {
        bool valid = true;
        for (const auto& cluster : clusters) {
            if (cluster.empty()) {
                valid = false;
                break;
            }
        }
        if (valid && k <= 8) {
            double currentMetric = 0.0;
            for (const auto& cluster : clusters) {
                currentMetric += calculateMetric(cluster);
            }
            if (currentMetric < bestMetric || bestClusters.empty()) {
                bestMetric = currentMetric;
                bestClusters = clusters;
            }
        }
        return;
    }
    for (int i = 0; i < k; ++i) {
        clusters[i].push_back(remaining.back());
        generateClusters(clusters, vector<double>(remaining.begin(), remaining.end() - 1), k, bestMetric, bestClusters);
        clusters[i].pop_back(); 
    }
    if (k < 8) {
        clusters.push_back({remaining.back()});
        generateClusters(clusters, vector<double>(remaining.begin(), remaining.end() - 1), k + 1, bestMetric, bestClusters);
        clusters.pop_back();  
    }
}


void testCalculateMean() {
    cout << "Тест: testCalculateMean" << endl;
    vector<double> cluster1 = {1.0, 2.0, 3.0};
    assert(abs(calculateMean(cluster1) - 2.0) < 1e-6);

    vector<double> cluster2 = {10.0, 20.0, 30.0};
    assert(abs(calculateMean(cluster2) - 20.0) < 1e-6);

    vector<double> cluster3 = {5.0};
    assert(abs(calculateMean(cluster3) - 5.0) < 1e-6);

    vector<double> cluster4 = {};
    assert(abs(calculateMean(cluster4) - 0.0) < 1e-6);
    cout << "Тест testCalculateMean прошел успешно!" << endl;
}

void testCalculateMetric() {
    cout << "Тест: testCalculateMetric" << endl;
    vector<double> cluster1 = {1.0, 2.0, 3.0};
    assert(abs(calculateMetric(cluster1) - 2.0) < 1e-6);
    vector<double> cluster2 = {10.0, 20.0, 30.0};
    assert(abs(calculateMetric(cluster2) - 20.0) < 1e-6);
    vector<double> cluster3 = {5.0};
    assert(abs(calculateMetric(cluster3) - 0.0) < 1e-6);
    vector<double> cluster4 = {};
    assert(abs(calculateMetric(cluster4) - 0.0) < 1e-6);
    cout << "Тест testCalculateMetric прошел успешно!" << endl;
}

void testGenerateClusters() {
    cout << "Тест: testGenerateClusters" << endl;
    vector<double> data = {1.0, 2.0, 3.0}; 
    vector<vector<double>> clusters(1); 
    double bestMetric = numeric_limits<double>::infinity();
    vector<vector<double>> bestClusters;
    generateClusters(clusters, data, 1, bestMetric, bestClusters);

    assert(bestClusters.size() > 0);
    double calculatedMetric = 0.0;
    for (const auto& cluster : bestClusters) {
        calculatedMetric += calculateMetric(cluster);
    }
    assert(abs(calculatedMetric - bestMetric) < 1e-6);
    cout << "Тест testGenerateClusters прошел успешно!" << endl;
}

void testEmptyData() {
    cout << "Тест: testEmptyData" << endl;
    vector<double> data = {};
    vector<vector<double>> clusters(1);
    double bestMetric = numeric_limits<double>::infinity();
    vector<vector<double>> bestClusters;

    generateClusters(clusters, data, 1, bestMetric, bestClusters);
    assert(bestClusters.empty());
    cout << "Тест testEmptyData прошел успешно!" << endl;
}

void testSingleElement() {
    cout << "Тест: testSingleElement" << endl;
    vector<double> data = {10.0}; 
    vector<vector<double>> clusters(1);
    double bestMetric = numeric_limits<double>::infinity();
    vector<vector<double>> bestClusters;

    generateClusters(clusters, data, 1, bestMetric, bestClusters);
    
    assert(bestClusters.size() == 1); 
    assert(bestClusters[0].size() == 1); 
    assert(bestClusters[0][0] == 10.0);
    cout << "Тест testSingleElement прошел успешно!" << endl;
}

int main() {
    testCalculateMean();
    testCalculateMetric();
    testGenerateClusters();
    testEmptyData();
    testSingleElement();
    cout << "Все тесты прошли успешно!" << endl;
}
