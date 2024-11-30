#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<float>& arr) {

    int n = arr.size();

    float minVal = *min_element(arr.begin(), arr.end());
    float maxVal = *max_element(arr.begin(), arr.end());

    // Создать ведра и распределить элементы
    vector<vector<float>> buckets(n);

    for (float num : arr) {

        int bucketIndex = (num - minVal) * n / (maxVal - minVal + 1); // Индексация ведра
        buckets[bucketIndex].push_back(num);

    }

    // Сортировать и объединять ведра
    arr.clear();

    for (auto& bucket : buckets) {

        sort(bucket.begin(), bucket.end());
        arr.insert(arr.end(), bucket.begin(), bucket.end());

    }
}

int main() {

    int n;
    cin >> n;

    vector<float> arr(n);

    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    bucketSort(arr);

    for (int i = 0; i < n; i ++){

        cout << arr[i] << ' ';

    }

    cout << '\n';

    return 0;
}

#include <gtest/gtest.h>

// Лучший и средний случай: равномерное распределение
TEST(BucketSortTest, BestCase) {
    vector<float> input = {0.1, 0.2, 0.3, 0.4, 0.5};
    vector<float> expected = {0.1, 0.2, 0.3, 0.4, 0.5};
    
    bucketSort(input);

    EXPECT_EQ(input, expected);
}

// Худший случай: почти все в одной корзине
TEST(BucketSortTest, WorstCase) {

    vector<float> input = {0.1, 0.11, 0.12, 0.13, 0.8};
    vector<float> expected = {0.1, 0.11, 0.12, 0.13, 0.8};
    
    bucketSort(input);

    EXPECT_EQ(input, expected);
}

// Массив с одинаковыми элементами
TEST(BucketSortTest, Duplicates) {
    vector<float> input = {0.3, 0.3, 0.3, 0.3, 0.3};
    vector<float> expected = {0.3, 0.3, 0.3, 0.3, 0.3};
    
    bucketSort(input);

    EXPECT_EQ(input, expected);
}

// Пустой массив
TEST(BucketSortTest, EmptyArray) {
    vector<float> input = {};
    vector<float> expected = {};
    
    bucketSort(input);

    EXPECT_EQ(input, expected);
}

// Массив с одним элементом
TEST(BucketSortTest, SingleElement) {
    vector<float> input = {0.42};
    vector<float> expected = {0.42};
    
    bucketSort(input);

    EXPECT_EQ(input, expected);
}
