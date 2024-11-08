#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <cassert>
using namespace std;

// ������� ��� ���������� ������� �������� ��������
double calculateMean(const vector<double>& cluster) {
    return accumulate(cluster.begin(), cluster.end(), 0.0) / cluster.size(); // O(M)
}

// ������� ��� ���������� ������� ��� ������� ��������
double calculateMetric(const vector<double>& cluster) {
    double mean = calculateMean(cluster); // O(M)
    double metric = 0.0;
    for (double value : cluster) {
        metric += abs(value - mean); // O(M)
    }
    return metric; // O(1)
}

// ����������� ������� ��� ��������� ���� ��������� ��������� �������
void partition(int start, int k, const vector<double>& arr, vector<vector<vector<double>>>& result, vector<vector<double>>& currentPartition) {
    if (k == 1) { // ���� ������� ���� �������
        currentPartition.push_back(vector<double>(arr.begin() + start, arr.end())); // O(N - start)
        result.push_back(currentPartition); // O(1)
        currentPartition.pop_back(); // O(1)
        return;
    }

    for (int end = start; end < arr.size() - k + 1; ++end) { // O(N)
        currentPartition.push_back(vector<double>(arr.begin() + start, arr.begin() + end + 1));//O(1)
        partition(end + 1, k - 1, arr, result, currentPartition); // ����������� �����
        currentPartition.pop_back(); // O(1)
    }
}

// �������� ������� ��� ���������� ������������ ���������
pair<vector<vector<double>>, double> findOptimalClusters(const vector<double>& arr, int K) {
    vector<vector<vector<double>>> partitions; // ��� �������� ���� ���������
    vector<vector<double>> currentPartition; // ������� ���������

    partition(0, K, arr, partitions, currentPartition); // ��������� ���� ���������

    vector<vector<double>> bestPartition; // ��� �������� ������� ���������
    double minMetric = numeric_limits<double>::max(); // ������������� ������������ ���������

    for (const auto& partition : partitions) { // O(P), ��� P - ���������� ���������
        double totalMetric = 0.0;
        for (const auto& cluster : partition) { // O(K)
            totalMetric += calculateMetric(cluster); // O(M), ��� M - ������ ��������
        }
        if (totalMetric < minMetric) { // O(1)
            minMetric = totalMetric; // O(1)
            bestPartition = partition; // O(1)
        }
    }

    return { bestPartition, minMetric }; // O(1)
}
void test_partition() {
    int K = 9;
    {
        vector<double> arr = { 1.1, 2.1, 3.1, 4.1, 5.1, 6.1 };
        sort(arr.begin(), arr.end());// O(N�log(N))
        double min_cost = numeric_limits<double>::max();
        auto start = chrono::high_resolution_clock::now();
        pair<vector<vector<double>>, double> result = findOptimalClusters(arr, 2); // ������� ����������� ��������
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        vector<vector<double>> clusters = result.first;
        double metric = result.second;
        assert(metric < numeric_limits<double>::max());
        cout << duration.count() / 1e6 << '\n';
    }
    {
        vector<double> arr = { 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1 };
        sort(arr.begin(), arr.end());// O(N�log(N))
        double min_cost = numeric_limits<double>::max();
        auto start = chrono::high_resolution_clock::now();
        pair<vector<vector<double>>, double> result = findOptimalClusters(arr, K); // ������� ����������� ��������
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        vector<vector<double>> clusters = result.first;
        double metric = result.second;
        assert(metric < numeric_limits<double>::max());
        cout << duration.count() / 1e6 << '\n';
    }
    {
        vector<double> arr = { 3.0, 3.0, -93.0,  88.0, -63.0, 1.7,0.7, 8.0, -98.0, 49.0, 88.0, -71.0, 4.0, 3.2, 4.2 };
        sort(arr.begin(), arr.end());// O(N�log(N))
        double min_cost = numeric_limits<double>::max();
        auto start = chrono::high_resolution_clock::now();
        pair<vector<vector<double>>, double> result = findOptimalClusters(arr, K); // ������� ����������� ��������
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        vector<vector<double>> clusters = result.first;
        double metric = result.second;
        assert(metric < numeric_limits<double>::max());
        cout << duration.count() / 1e6 << '\n';
    }
    {
        vector<double> arr = { 3.0, 3.0, 93.0,  88.0, 63.0, 1.7,0.7, 8.0, 98.0, 49.0, 88.0, 71.0, 4.0, 3.2, 4.2, 74, 82, 1, -10 , -20 };
        sort(arr.begin(), arr.end());// O(N�log(N))
        double min_cost = numeric_limits<double>::max();
        auto start = chrono::high_resolution_clock::now();
        pair<vector<vector<double>>, double> result = findOptimalClusters(arr, K); // ������� ����������� ��������
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        vector<vector<double>> clusters = result.first;
        double metric = result.second;
        assert(metric < numeric_limits<double>::max());
        cout << duration.count() / 1e6 << '\n';
    }
    {
        vector<double> arr = { 3.0, 3.0, 88.0, -31.0, 1.7,0.9, 82.0, -1.0, 4.0, 2.5, 3.0, 32.0, -93.0,  88.0, -63.0, 1.7,0.7, 8.0, -98.0, 49.0, 88.0, -71.0, 4.0, 3.2, 4.2 };
        sort(arr.begin(), arr.end());// O(N�log(N))
        double min_cost = numeric_limits<double>::max();
        auto start = chrono::high_resolution_clock::now();
        pair<vector<vector<double>>, double> result = findOptimalClusters(arr, K); // ������� ����������� ��������
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        vector<vector<double>> clusters = result.first;
        double metric = result.second;
        assert(metric < numeric_limits<double>::max());
        cout << duration.count() / 1e6 << '\n';
    }
}
// �������� �������
int main() {
    test_partition();
    return 0;
}
// ����� ��������� O(2^(N-1) * N + N *log(N)) = O(N(2^(N-1) + log(N))) � ������ ������