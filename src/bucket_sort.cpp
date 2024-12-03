#include <vector>
#include <algorithm>

void bucketSort(std::vector<int>& arr, int bucketSize = 10) {
    if (arr.empty()) return;

    int minValue = *std::min_element(arr.begin(), arr.end());
    int maxValue = *std::max_element(arr.begin(), arr.end());

    int bucketCount = (maxValue - minValue) / bucketSize + 1;
    std::vector<std::vector<int>> buckets(bucketCount);

    for (int num : arr) {
        int bucketIndex = (num - minValue) / bucketSize;
        buckets[bucketIndex].push_back(num);
    }

    arr.clear();
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}
