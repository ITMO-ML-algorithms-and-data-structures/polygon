#define _CRT_SECURE_NO_DEPRECATE


#include <iostream>

#include <sstream>

#include <unordered_map>

#include <string>
#include <vector>

#include <cstdint>

#include <fstream>

#include <random>

#include <cmath>
#include <limits>

#include <algorithm>
#include <numeric>

using namespace std;

#define ASSERT_MSG(condition, message) \
    do { \
        if (!(condition)) { \
            cerr << "Assertion failed: (" #condition "), function " << __FUNCTION__ \
                      << ", file " << __FILE__ << ", line " << __LINE__ << "." << endl; \
            cerr << "Error in test: " << message << endl; \
            abort(); \
        } \
    } while (false)

double metric_func( vector<double>& cluster) {

    double sum = 0.0;

    for (int i = 0; i < cluster.size(); i++) {
        sum += cluster[i];
    }
    double mean = sum / cluster.size();

    double cost = 0.0;

    for (int i = 0; i < cluster.size(); i++) {
        cost += abs(cluster[i] - mean);
    }
    // calc metric
    return cost;              
}

void get_clusters(
    vector<double>& arr, int index, vector<vector<double>>& clusters,
    double current_cost, double& min_cost, vector<vector<double>>& top_clusters) {

    if (index == arr.size()) {
        if (clusters.size() == 8) {
            if (current_cost < min_cost) {
                min_cost = current_cost;
                top_clusters = clusters;
            }
        }
        return;
    }

    for (int i = 0; i < clusters.size(); ++i) {
        double cur_cost = metric_func(clusters[i]);
        clusters[i].push_back(arr[index]);
        double new_cost = metric_func(clusters[i]);

        get_clusters(arr, index + 1, clusters, current_cost - cur_cost + new_cost, min_cost, top_clusters);
        clusters[i].pop_back();
    }

    if (clusters.size() < 8) {
        clusters.push_back({ arr[index] });
        double new_cost = 0.0;

        get_clusters(arr, index + 1, clusters, current_cost + new_cost, min_cost, top_clusters);
        clusters.pop_back();
    }
}

vector<vector<double>> solve(vector<double>& inp) {

    double min_cost = 1e18;

    vector<vector<double>> clusters;
    vector<vector<double>> top_clusters;

    get_clusters(inp, 0, clusters, 0.0, min_cost, top_clusters);

    return top_clusters;

}
vector<vector<double>> run(vector<double>inp) {

    return solve(inp);

}

bool isEqual(vector<vector<double>> A, vector<vector<double>> B) {

    for (int i = 0; i < A.size(); i++) {

        if (A[i].size() != B[i].size()) {
            return false;
        }

        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }

    }

    return true;
}

#include <chrono>

using namespace std::chrono;

void test() {

    struct {
        vector<double> input;
        vector<vector<double>> expected;
    } tests[] = {
        {{1, 2, 3, 4, 5, 6, 7, 8}, {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {{1, 2, 3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10}, {{1, 2, 3}, {4}, {5}, {6}, {7}, {8}, {9}, {10, 10, 10}}},
        //{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 9, 9}, {{1, 2, 3}, {4}, {5}, {6}, {7}, {8}, {9, 9, 9}, {10, 10, 10}}},
    };

    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++) {

        auto t = tests[i];

        auto start = high_resolution_clock::now();

        vector<vector<double>> out = run(t.input);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << duration.count() << endl;

        vector<vector<double>> expected = t.expected;

        ASSERT_MSG(isEqual(out, expected), i + 1);

    }

    cout << "All tests Passed!";

}

int main() {

    test();

    return 0;
}