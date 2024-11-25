#include <gtest/gtest.h>
#include <vector>
#include "array_clustering.h"

using namespace std;

bool are_clusters_equal(const vector<vector<float>>& a, const vector<vector<float>>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

TEST(ClusterTest, SmallArrayTrivialCase) {
    vector<float> arr = {1.0, 2.0, 3.0};
    int k = 3;
    ClusterResult result = optimal_clusters(arr, k);
    vector<vector<float>> expected = {{1.0}, {2.0}, {3.0}};
    ASSERT_TRUE(are_clusters_equal(result.clusters, expected));
}

TEST(ClusterTest, NegativeAndPositiveNumbers) {
    vector<float> arr = {-1.0, -2.0, 3.0, 4.0};
    int k = 2;
    ClusterResult result = optimal_clusters(arr, k);
    ASSERT_NEAR(result.total_metric, 4.5, 2.5);
}

TEST(ClusterTest, SameElements) {
    vector<float> arr = {5.0, 5.0, 5.0};
    int k = 2;
    ClusterResult result = optimal_clusters(arr, k);
    ASSERT_EQ(result.total_metric, 0.0f);
}

TEST(ClusterTest, SingleElementArray) {
    vector<float> arr = {42.0};
    int k = 1;
    ClusterResult result = optimal_clusters(arr, k);
    vector<vector<float>> expected = {{42.0}};
    ASSERT_TRUE(are_clusters_equal(result.clusters, expected));
}

TEST(ClusterTest, MaxArraySize) {
    vector<float> arr(25, 1.0);
    int k = 7;
    ClusterResult result = optimal_clusters(arr, k);
    ASSERT_NEAR(result.total_metric, 0.0f, 1e-2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
