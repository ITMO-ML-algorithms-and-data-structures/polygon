#include <iostream>
#include <vector>
#include <limits>
#include <cassert>

using namespace std;

class ProductIterator {
public:
    ProductIterator(vector<int> elements, int repeat) : indices(repeat, 0) { // + n * 4 байт
        this->elements = elements;
        this->repeat = repeat;
    }

    bool is_done() {
        return done;
    }

    vector<int> next() {
        if (is_done()) {
            throw out_of_range("No more combinations");
        }
        vector<int> current_combination(repeat); // + n * 4 байт
        for (int i = 0; i < repeat; i++) { // O(repeat)
            current_combination[i] = elements[indices[i]];
        }
        increment_indices();
        return current_combination;
    }

private:
    vector<int> elements;
    int repeat;
    vector<int> indices;
    bool done = false; // + 1 байт

    void increment_indices() {
        for (int i = repeat - 1; i >= 0; i--) { // O(repeat)
            if (indices[i] < elements.size() - 1) {
                indices[i]++;
                return;
            }
            indices[i] = 0;
        }
        done = true;
    }
};


double mean_val(vector<double> arr) {
    int n = arr.size(); // + 4 байт
    double sum = 0; // + 8 байт
    for (int i = 0; i < n; i++) { // O(n)
        sum += arr[i];
    }
    return sum / n;
}


double score_cluster(vector<double> arr, double cluster_center) {
    int n = arr.size(); // + 4 байт
    double score = 0; // + 8 байт
    for (int i = 0; i < n; i++) { // O(n)
        score += abs(arr[i] - cluster_center);
    }
    return score;
}


vector<vector<double>> clustering(vector<double> numbers) {
    int n = numbers.size(); // + 4 байт
    int count = 5; // + 4 байт
    ProductIterator masks_iter({0, 1, 2, 3, 4}, n); // + 4 + 4 * count
    double best_score = numeric_limits<double>::infinity(); // + 8 байт
    vector<vector<double>> best_cluster(count);
    while (!masks_iter.is_done()) { // O(5^n)
        vector<int> mask = masks_iter.next(); // + n * 4 байт // O(n)
        vector<vector<double>> cluster(count);
        for (int i = 0; i < n; i++) { // O(n^2)
            cluster[mask[i]].push_back(numbers[i]); // + n * 8 байт
        }
        vector<double> cluster_center(count);
        vector<double> score(count);
        for (int i = 0; i < count; i++) { // O(n*count)
            if (cluster[i].size() > 0) {
                cluster_center[i] = mean_val(cluster[i]); // + 8 * k, где k - кол-во ненулевых кластеров
                score[i] = score_cluster(cluster[i], cluster_center[i]); // + 8 * k, где k - кол-во ненулевых кластеров
            } else {
                score[i] = numeric_limits<double>::infinity(); // + 8 * (count - k) байт
            }
        }
        double score_end = 0; // + 8 байт
        for (int i = 0; i < count; i++) { // O(count)
            score_end += score[i];
        }
        if (score_end < best_score) {
            best_score = score_end;
            for (int j = 0; j < count; j++) { // O(count)
                best_cluster[j] = cluster[j]; // + n * 8 байт
            }
        }
    }
    return best_cluster;
};

int main() {
    vector<double> numbers1 = {-9, 78, 76, 14, 38}; // + 8 * 5 байт
    vector<vector<double>> res1 = clustering(numbers1); // + 8 * n байт
    vector<vector<double>> test1 = {{-9},
                                    {78},
                                    {76},
                                    {14},
                                    {38}}; // + 8 * 5 байт
    assert(res1 == test1);
    vector<double> numbers2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // + 8 * 10 байт
    vector<vector<double>> res2 = clustering(numbers2); // + 8 * n байт
    vector<vector<double>> test2 = {{1, 2, 3},
                                    {4, 5, 6},
                                    {7, 8},
                                    {9},
                                    {10}}; // + 8 * 10 байт
    assert(res2 == test2);
    vector<double> numbers3 = {-9, 78, 76, 14, 38, 4, 15, 100, 46, 0}; // 8 * 10 байт
    vector<vector<double>> res3 = clustering(numbers3); // + 8 * n байт
    vector<vector<double>> test3 = {{-9, 4, 0},
                                    {78, 76},
                                    {14, 15},
                                    {38, 46},
                                    {100}}; // + 8 * 10 байт
    assert(res3 == test3);
    vector<double> numbers4 = {-9, 7.5, 6.6, 14, 38, 17, 15, 100, -46.2, 0}; // 8 * 10 байт
    vector<vector<double>> res4 = clustering(numbers4); // + 8 * n байт
    vector<vector<double>> test4 = {{-9, 7.5, 6.6, 0},
                                    {14, 17,  15},
                                    {38},
                                    {100},
                                    {-46.2}}; // + 8 * 10 байт
    assert(res4 == test4);
    return 0;
}
