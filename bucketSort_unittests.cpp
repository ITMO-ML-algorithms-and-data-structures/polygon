#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void insertionSort(std::vector<int>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

std::vector<int> bucketSort(std::vector<int>& arr) {
    if (arr.empty()) return arr;

    int maxVal = *std::max_element(arr.begin(), arr.end());
    int minVal = *std::min_element(arr.begin(), arr.end());

    if (maxVal == minVal) return arr;

    int bucketCount = std::min(static_cast<int>(arr.size()), 1000);
    std::vector<std::vector<int>> buckets(bucketCount);

    for (int num : arr) {
        int bucketIndex = (num - minVal) * (bucketCount - 1) / (maxVal - minVal);
        buckets[bucketIndex].push_back(num);
    }

    arr.clear();

    for (auto& bucket : buckets) {
        if (!bucket.empty()) {
            insertionSort(bucket);
            arr.insert(arr.end(), bucket.begin(), bucket.end());
        }
    }
    return arr;
}

bool areEqual(const std::vector<int>& a, const std::vector<int>& b) {
    return a == b;
}

void testbucketSort() {
    // лучший случай
    std::vector<int> bestCase = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> sortedBestCase = bestCase; 
    assert(bucketSort(bestCase) == sortedBestCase);

    // средний случай (случайный порядок)
    std::vector<int> averageCase = {3, 1, 4, 9, 6, 7, 8, 2, 5, 10};
    std::vector<int> sortedAverageCase = averageCase;
    std::sort(sortedAverageCase.begin(), sortedAverageCase.end()); 
    assert(bucketSort(averageCase) == sortedAverageCase);

    // худший случай (обратный порядок)
    std::vector<int> worstCase = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> sortedWorstCase = worstCase;
    std::sort(sortedWorstCase.begin(), sortedWorstCase.end()); 
    assert(bucketSort(worstCase) == sortedWorstCase);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testbucketSort();
    return 0;
}