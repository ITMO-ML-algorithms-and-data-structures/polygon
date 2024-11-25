#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <cmath>

struct ClusterResult {
    std::vector<std::vector<float>> clusters;
    float total_metric;
};

ClusterResult optimal_clusters(const std::vector<float>& arr, int k);

#endif