#include <cmath>
#include <vector>
#include <iostream>
#include <cassert>

double distance(double a, double b) {
    double dist = abs(a - b);
    return dist;
}


double calculateCentroid(std::vector<double> cluster) {
    double centroid = 0;
    for (int i = 0; i < cluster.size(); i++) {
        centroid += cluster[i];
    }
    centroid /= cluster.size();
    return centroid;
}

std::vector<std::vector<double>> kMeansCluster(int k, std::vector<double> points) {
    std::vector<double> centroids(k);
    std::vector<std::vector<double>> clusters(k);

    for (int i = 0; i < k; i++) {
        centroids[i] = points[i];
    }

    bool converged = false;
    while (!converged) {
        for (int i = 0; i < clusters.size(); i++) {
            clusters[i].clear();
        }

        for (int i = 0; i < points.size(); i++) {
            double point = points[i];
            int bestCluster = 0;
            double minDistance = distance(point, centroids[0]);

            for (int j = 1; j < k; j++) {
                double dist = distance(point, centroids[j]);
                if (dist < minDistance) {
                    minDistance = dist;
                    bestCluster = j;
                }
            }
            clusters[bestCluster].push_back(point);
        }

        converged = true;
        for (int i = 0; i < k; i++) {
            double newCentroid = calculateCentroid(clusters[i]);
            if (distance(newCentroid, centroids[i]) > 0.0001) {
                converged = false;
            }
            centroids[i] = newCentroid;
        }
    }
    if(converged)
        return clusters;
}

void test_kMeansCluster() {
    std::vector<double> points1 = {1, 2, 8, 9};
    int k1 = 2;
    std::vector<std::vector<double>> clusters1 = kMeansCluster(k1, points1);
    assert(clusters1.size() == 2);
    assert(clusters1[0].size() == 2 || clusters1[1].size() == 2);
    std::cout << "Test 1 passed.\n";

    std::vector<double> points2 = {1, 2, 2.5, 3, 10, 11};
    int k2 = 3;
    std::vector<std::vector<double>> clusters2 = kMeansCluster(k2, points2);
    assert(clusters2.size() == 3);
    assert(clusters2[0].size() > 0 && clusters2[1].size() > 0 && clusters2[2].size() > 0);
    std::cout << "Test 2 passed.\n";

    std::vector<double> points3 = {0};
    int k3 = 5;
    std::vector<std::vector<double>> clusters3 = kMeansCluster(k3, points3);
    assert(clusters3.size() == 5);
    assert(clusters3[0].size() == 1);
    for (int i = 1; i < clusters3.size(); i++) {
        assert(clusters3[i].empty());
    }
    std::cout << "Test 3 passed.\n";

    std::vector<double> points4 = {5, 5, 5, 5};
    int k4 = 2;
    std::vector<std::vector<double>> clusters4 = kMeansCluster(k4, points4);
    assert(clusters4.size() == 2);
    assert(clusters4[0].size() + clusters4[1].size() == 4);
    std::cout << "Test 4 passed.\n";
}



int main() {

    test_kMeansCluster();

    std::vector<double> points = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int k = 10;

    std::vector<std::vector<double>> clusters = kMeansCluster(k, points);

    for (int i = 0; i < clusters.size(); i++) {
        std::cout << "cluster " << i + 1 << ": ";
        for (int j = 0; j < clusters[i].size(); j++) {
            std::cout << clusters[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
