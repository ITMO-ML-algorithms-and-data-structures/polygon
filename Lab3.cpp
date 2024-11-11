#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void recursion(int start, vector<int>& subset,
    vector<vector<int>>& result, int k, const vector<int>& arr)
{
    if (subset.size() == k) {
        result.push_back(subset);
        return;
    }

    for (int i = start; i < arr.size(); i++) {
        subset.push_back(arr[i]);
        recursion(i + 1, subset, result, k, arr);
        subset.pop_back();
    }
}

vector<vector<int>> combinations(const vector<int>& arr, int k)
{
    vector<vector<int>> result;
    vector<int> subset;

    recursion(0, subset, result, k, arr);
    return result;
}

pair<vector<int>, vector<int>> can_partition(const vector<int>& arr)
{
    int total_sum = accumulate(arr.begin(), arr.end(), 0);

    if (total_sum % 2 != 0) {
        return {};
    }

    int target_sum = total_sum / 2;
    int n = arr.size();

    for (int i = 1; i <= n; i++) {
        vector<vector<int>> combs = combinations(arr, i);

        for (const vector<int>& subset : combs) {
            int subset_sum = accumulate(subset.begin(), subset.end(), 0);

            if (subset_sum == target_sum) {

                vector<int> filtered_elements;
                for (int element : arr) {

                    if (find(subset.begin(), subset.end(), element) == subset.end()) {
                        filtered_elements.push_back(element);
                    }
                }


                return { subset, filtered_elements };
            }
        }
    }

    return {};
}

int main() {
    setlocale(LC_ALL, "Ru");
    vector<int> arr = { 1, 5, 11, 5, 1, 5, 11, 5, 1, 5, 11, 5, 1, 5, 11, 5, 1, 5, 11, 5, 1, 5, 11, 5, 1, 5, 11, 5, 1, 5, 11, 5 };

    auto start = high_resolution_clock::now();

    pair<vector<int>, vector<int>> result = can_partition(arr);

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);

    if (!result.first.empty()) {
        cout << "Сумма 1: ";
        for (int num : result.first) {
            cout << num << " ";
        }
        cout << "\nСумма 2: ";
        for (int num : result.second) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Время выполнения: " << duration.count() << " миллисекунд." << endl;

    return 0;
}