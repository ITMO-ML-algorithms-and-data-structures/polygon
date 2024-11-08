#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

double mean(const vector<double>& arr) {
    if (arr.size() == 0) return 0;
    double sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }
    return sum / arr.size();
}

double metric(const vector<vector<double>>& arr) {
    double ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        double sumc = 0;
        for (int k = 0; k < arr[i].size(); k++) {
            sumc += abs(mean(arr[i]) - arr[i][k]);
        }
        ans += sumc;
    }
    return ans;
}

vector<vector<int>> find_cluster_sizes_combs(int n) {
    vector<vector<int>> a;
    set<vector<int>> unique_combinations;
    for (int i1 = 1; i1 < n - 3; ++i1) {
        for (int i2 = i1 + 1; i2 < n - 2; ++i2) {
            for (int i3 = i2 + 1; i3 < n - 1; ++i3) {
                for (int i4 = i3 + 1; i4 < n; ++i4) {
                    for (int i5 = i4 + 1; i5 <= n; ++i5) {
                        if (i1 + (i2 - i1) + (i3 - i2) + (i4 - i3) + (i5 - i4) == n) {
                            vector<int> sorted_combination = { i1, i2 - i1, i3 - i2, i4 - i3, i5 - i4 };
                            sort(sorted_combination.begin(), sorted_combination.end());
                            unique_combinations.insert(sorted_combination);
                        }
                    }
                }
            }
        }
    }
    for (const auto& item : unique_combinations) {
        a.push_back(item);
    }
    return a;
}

vector<vector<double>> cluster5(vector<double>& arr) {
    vector<double> arr1 = arr;
    sort(arr1.begin(), arr1.end());
    vector<vector<int>> csc = find_cluster_sizes_combs(arr.size());
    vector<vector<double>> ans = { {1, 999999999}, {1, 999999999}, {1, 999999999},{1, 999999999},{1, 999999999} };

    do {
        for (int i = 0; i < csc.size(); i++) {
            vector<vector<double>> clcomb(5);
            int j = 0, k = 0;

            while (j < 5 && k < arr1.size()) {
                int c = 0;
                while (c < csc[i][j] && k < arr1.size()) {
                    clcomb[j].push_back(arr1[k]);
                    k++;
                    c++;
                }
                j++;
            }

            // Проверка на корректность clcomb перед использованием metric
            if ((clcomb.size() != 0) && metric(clcomb) < metric(ans)) {
                ans = clcomb;
            }
        }
    } while (next_permutation(arr1.begin(), arr1.end()));

    return ans;
}
bool test(vector<double> arr, vector<vector<double>> solution) {
    return (cluster5(arr) == solution);
}
void hui(const std::vector<std::vector<double>>& vec) {
    for (const auto& innerVec : vec) {
        std::cout << "{ ";
        for (int num : innerVec) {
            std::cout << num << " ";
        }
        std::cout << "}" << std::endl;
    }
}
int main() {
    vector<double> arr = { 1, 3, -3321, 5, 6, 82, 1555, -1123123, 234234, 33221 };
    hui(cluster5(arr));
    cout << test({ 2, 3, 4, 5, 6, 82, 100 }, { {2}, {3}, {82}, {100}, {4, 5, 6} });
    cout << test({ 1, 3, 4, 5, 6, 82, 1555, -1123123 }, { {-1123123}, {1}, {82}, {1555}, {3, 4, 5, 6} });
    cout << test({ 1, 3, -3321, 5, 6, 82, 1555, -1123123, 234234, -11111, 223321 }, { {-1123123}, {-3321}, {33221}, {234234}, {1, 3, 5, 6, 82, 1555} });
    return 0;
}