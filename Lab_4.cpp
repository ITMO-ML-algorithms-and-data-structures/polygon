#include <iostream>
#include <locale>
#include <vector>
#include <numeric>
#include <chrono>
#include <iomanip> 
#include <fstream>

using namespace std;

void generateCombinations(const vector<int>& arr, int k, int start, vector<int>& subset, vector<vector<int>>& combinations) {
    if (subset.size() == k) {
        combinations.push_back(subset);
        return;
    }

    for (int i = start; i < arr.size(); ++i) {
        subset.push_back(arr[i]);
        generateCombinations(arr, k, i + 1, subset, combinations);
        subset.pop_back();
    }
}

pair<vector<int>, vector<int>> canPartition(const vector<int>& arr) {
    int total_sum = accumulate(arr.begin(), arr.end(), 0);

    if (total_sum % 2 != 0) {
        return { {}, {} };
    }

    int target_sum = total_sum / 2;
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        vector<vector<int>> combinations;
        vector<int> subset;
        generateCombinations(arr, i, 0, subset, combinations);

        for (const auto& subset : combinations) {
            int subset_sum = accumulate(subset.begin(), subset.end(), 0);

            if (subset_sum == target_sum) {
                vector<int> remaining_elements = arr;

                for (int item : subset) {
                    auto it = find(remaining_elements.begin(), remaining_elements.end(), item);
                    if (it != remaining_elements.end()) {
                        remaining_elements.erase(it);
                    }
                }

                return { subset, remaining_elements };
            }
        }
    }

    return { {}, {} };
}

int main() {
    setlocale(LC_ALL, "Ru");
    system("chcp 65001 > nul");

    ifstream input_file("test.txt");

    vector<int> arr;
    int value;
    while (input_file >> value) {
        arr.push_back(value);
    }
    input_file.close();


    auto start_time = chrono::high_resolution_clock::now();
    auto result = canPartition(arr);
    auto end_time = chrono::high_resolution_clock::now();

    if (!result.first.empty() && !result.second.empty()) {
        wcout << L"Две части с равной суммой: { ";
        for (int num : result.first) wcout << num << L" ";
        wcout << L"} и { ";
        for (int num : result.second) wcout << num << L" ";
        wcout << L"}" << endl;
    }
    else {
        wcout << L"Невозможно разделить массив на две части с равной суммой." << endl;
    }

    chrono::duration<double> execution_time = end_time - start_time;
    wcout << fixed << setprecision(6);
    wcout << L"Время выполнения: " << execution_time.count() << L" секунд" << endl;

    return 0;
}