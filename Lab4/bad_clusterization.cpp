#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "../Source/doctest.h"

std::vector<std::vector<int>> pivots(int elements) {

    std::vector<std::vector<int>> pivots;
    pivots.reserve(pow(elements, 6));

    for (int p1 = 0; p1 <= elements - 1; p1++)
        for (int p2 = p1 + 1; p2 <= elements - 1; p2++)
            for (int p3 = p2 + 1; p3 <= elements - 1; p3++)
                for (int p4 = p3 + 1; p4 <= elements - 1; p4++)
                    for (int p5 = p4 + 1; p5 <= elements - 1; p5++)
                        for (int p6 = p5 + 1; p6 <= elements - 1; p6++)
                            pivots.push_back({p1, p2, p3, p4, p5, p6});

    return pivots;

}

double cluster_sum(const std::vector<double>& vector, const std::vector<int>& cluster_in_inds) {

    double sum = 0;

    for (int i = 0; i < cluster_in_inds.size(); i++) {
        sum += vector[cluster_in_inds[i]];
    }

    return sum;

}

double cluster_score(const std::vector<double>& vector, const std::vector<int>& cluster_in_inds, bool added_new_element = false, const double& new_element = 0) {

    double score = 0;
    double cur_sum = cluster_sum(vector, cluster_in_inds);

    if (added_new_element) {
        for (int i = 0; i < cluster_in_inds.size(); i++) {
            double i_score = std::abs( ( (cur_sum + new_element) / (cluster_in_inds.size() + 1) ) - vector[cluster_in_inds[i]] );
            score = std::max(score, i_score);
        }
    } else {
        for (int i = 0; i < cluster_in_inds.size(); i++) {
            double i_score = std::abs( ( cur_sum / cluster_in_inds.size() ) - vector[cluster_in_inds[i]] );
            score = std::max(score, i_score);
        }
    }

    return score;

}

double partition_score(const std::vector<double>& vector, const std::vector<std::vector<int>>& partition_in_inds) {

    double result_score = 0;

    for (int i = 0; i < partition_in_inds.size(); i++)
        result_score = std::max(result_score, cluster_score(vector, partition_in_inds[i]));

    return result_score;

}

int uniformity_score(const std::vector<std::vector<int>> partition) {

    size_t min_len = std::numeric_limits<int>::max(), max_len = 0;
    for (int i = 0; i < partition.size(); i++) {
        min_len = std::min(min_len, partition[i].size());
        max_len = std::max(max_len, partition[i].size());
    }

    return (max_len - min_len);

}

std::vector<std::vector<double>> clusterization(const std::vector<double>& vector) {

    std::vector<std::vector<int>> pivs = pivots(vector.size());
    std::vector<std::vector<int>> best_partition_in_inds;
    double best_score = std::numeric_limits<double>::max();
    int best_uniformity_score = std::numeric_limits<int>::max();

    for (auto pivs_inds : pivs) {

        std::vector<std::vector<int>> partition_in_inds;
        for (auto i : pivs_inds)
            partition_in_inds.push_back({i});

        for (int i = 0; i < vector.size(); i++) {

            if (std::find(pivs_inds.begin(), pivs_inds.end(), i) != pivs_inds.end())
                continue;

            int best_cluster = -1;
            double best_cluster_score = std::numeric_limits<double>::max();

            for (int j = 0; j < partition_in_inds.size(); j++) {

                double cur_cluster_sum = cluster_sum(vector, partition_in_inds[j]);
                double cur_cluster_score = cluster_score(vector, partition_in_inds[j], true, vector[i]);                

                if (cur_cluster_score < best_cluster_score) {
                    best_cluster_score = cur_cluster_score;
                    best_cluster = j;
                }

            }

            partition_in_inds[best_cluster].push_back(i);

        }

        double score = partition_score(vector, partition_in_inds);

        if (score < best_score) {
            best_score = score;
            best_partition_in_inds = partition_in_inds;
            best_uniformity_score = uniformity_score(partition_in_inds);
        }
        else if (score == best_score) {
            if (uniformity_score(partition_in_inds) < best_uniformity_score) {
                best_uniformity_score = uniformity_score(partition_in_inds);
                best_partition_in_inds = partition_in_inds;
            }
        }

    }

    for (int i = 0; i < best_partition_in_inds.size(); i++)
        std::sort(best_partition_in_inds[i].begin(), best_partition_in_inds[i].end());

    std::vector<std::vector<double>> best_partition;
    for (int i = 0; i < best_partition_in_inds.size(); i++) {

        std::vector<double> cluster;
        for (int j = 0; j < best_partition_in_inds[i].size(); j++) {
            cluster.push_back(vector[best_partition_in_inds[i][j]]);
        }

        best_partition.push_back(cluster);

    }

    return best_partition;

}
