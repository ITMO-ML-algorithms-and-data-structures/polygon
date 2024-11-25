#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <limits>

using namespace std;

float calculate_metric(const vector<float>& cluster) {
    if (cluster.empty()) return 0.0f;
    float mean = accumulate(cluster.begin(), cluster.end(), 0.0f) / cluster.size();
    float sum = 0.0f;
    for (float val : cluster) {
        sum += abs(val - mean);
    }
    return sum;
}

struct ClusterResult {
    vector<vector<float>> clusters;
    float total_metric;
};

void find_clusters(const vector<float>& arr, int k, int start, vector<vector<float>>& current_clusters,
                   ClusterResult& best_result) {
    if (k == 1) {
        vector<float> last_cluster(arr.begin() + start, arr.end());
        current_clusters.push_back(last_cluster);

        float total_metric = 0.0f;
        for (const auto& cluster : current_clusters) {
            total_metric += calculate_metric(cluster);
        }

        if (total_metric < best_result.total_metric) {
            best_result.total_metric = total_metric;
            best_result.clusters = current_clusters;
        }
        current_clusters.pop_back();
        return;
    }

    for (int i = start; i <= arr.size() - k; ++i) {
        vector<float> cluster(arr.begin() + start, arr.begin() + i + 1);
        current_clusters.push_back(cluster);
        find_clusters(arr, k - 1, i + 1, current_clusters, best_result);
        current_clusters.pop_back();
    }
}

ClusterResult optimal_clusters(const vector<float>& arr, int k) {
    ClusterResult best_result;
    best_result.total_metric = numeric_limits<float>::max();
    vector<vector<float>> current_clusters;

    find_clusters(arr, k, 0, current_clusters, best_result);
    return best_result;
}
