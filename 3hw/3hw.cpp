#include <cmath>
#include <sstream>
#include <unordered_set>
#include <vector>
#include "../execute.h"


double mean(const std::vector<double> &v) {
    double sum = 0;
    for (const double &x: v)
        sum += x;
    return sum / v.size();
}

double cluster_metric(const std::vector<double> &v) {
    double metric = 0;
    for (const double &x: v)
        metric += std::abs((x - mean(v)));
    return metric;
}

double clusters_metric(const std::vector<std::vector<double>> &cluster_distribution) {
    double metric = 0;
    for (const std::vector<double> &cluster: cluster_distribution)
        metric += cluster_metric(cluster);
    return metric;
}


std::pair<double, std::vector<std::vector<double>>> clustering(const std::vector<double> &original_array,
                                                               std::vector<std::vector<double>> &cluster_distribution,
                                                               size_t number_of_element,
                                                               const size_t &number_of_clusters) {
    if (number_of_element == original_array.size())
        return {clusters_metric(cluster_distribution), cluster_distribution};

    std::pair<double, std::vector<std::vector<double>>> best_clusters = {10e20, std::vector<std::vector<double>>()};

    size_t number_of_empty_clusters = 0;
    for (const auto &cluster: cluster_distribution)
        if (cluster.empty())
            ++number_of_empty_clusters;
    if (number_of_empty_clusters > original_array.size() - number_of_element)
        return best_clusters;

    for (size_t i = 0; i < number_of_clusters; ++i) {
        if (number_of_element == original_array.size() - 2 and number_of_empty_clusters == 1 and
            !cluster_distribution[i].empty())
            continue;

        cluster_distribution[i].push_back(original_array[number_of_element]);
        std::pair<double, std::vector<std::vector<double>>> current_clusters =
                clustering(original_array, cluster_distribution, number_of_element + 1, number_of_clusters);

        if (current_clusters.first < best_clusters.first)
            best_clusters = current_clusters;

        cluster_distribution[i].pop_back();
    }

    return best_clusters;
}

std::vector<std::vector<double>> clusterization(const std::vector<double> &original_array, const size_t &number_of_clusters) {
    std::vector<std::vector<double>> cluster_distribution(number_of_clusters);

    return clustering(original_array, cluster_distribution, 0, number_of_clusters).second;
}

std::string execute_clusterization(const std::string &input) {
    std::vector<double> original_array;
    size_t number_of_clusters;

    std::istringstream input_ss(input);
    input_ss >> number_of_clusters;
    double tmp;
    while (input_ss >> tmp)
        original_array.push_back(tmp);

    std::vector<std::vector<double>> result = clusterization(original_array, number_of_clusters);
    std::ostringstream output_ss;

    for (auto &cluster: result) {
        for (auto &element: cluster)
            output_ss << element << ' ';
        output_ss << "| ";
    }

    return output_ss.str();
}


std::vector<std::vector<double>> string_to_clusters(const std::string &input_string) {
    std::vector<std::vector<double>> cluster(1);
    std::stringstream ss(input_string);
    std::string tmp;

    while (ss >> tmp) {
        if (tmp == "|")
            cluster.emplace_back();
        else
            cluster.back().push_back(std::stod(tmp));
    }

    return cluster;
}


bool clusters_contain_same_elements(const std::vector<std::vector<double>> &v1,
                                    const std::vector<std::vector<double>> &v2) {
    std::unordered_multiset<double> s1, s2;

    for (const std::vector<double> &cluster: v1)
        for (const double &element: cluster)
            s1.insert(element);

    for (const std::vector<double> &cluster: v2)
        for (const double &element: cluster)
            s2.insert(element);

    return s1 == s2;
}


bool compare_function(const std::string &s1, const std::string &s2) {
    std::stringstream ss1(s1), ss2(s2);

    std::vector<std::vector<double>> v1 = string_to_clusters(s1), v2 = string_to_clusters(s2);

    return clusters_metric(v1) == clusters_metric(v2) and clusters_contain_same_elements(v1, v2);
}


int main() {
    tester(4, execute_clusterization, "C:/Users/vorandpav_mini/Documents/CppProject/polygon/3hw/tests/",
           compare_function);
}
