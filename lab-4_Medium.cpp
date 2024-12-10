#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<vector<int>> serch_sum_6(vector<int>& arr) {
    int size = std::size(arr);
    vector<vector<int>> result;

    for (int i = 0; i < size - 5; i++) {
        for (int j = i + 1; j < size - 4; j++) {
           for (int k = j + 1; k < size - 3; k++) {
                for (int l = k + 1; l < size - 2; l++) {
                    for (int g = l + 1; g < size - 1; g++) {
                        for (int f = g + 1; f < size; f++) {
                            if (arr[i] + arr[j] + arr[k] + arr[l] + arr[g] + arr[f] == 0) {
                                result.push_back({i, j, k, l, g, f});
                            }
                        }
                    }
                }
            } 
        }
    }
    return result;
}


int main() {
    vector<int> arr = {1, -1, 2, -2, 3, -3, -3};
    vector<vector<int>> result = serch_sum_6(arr);

    for (const auto& a : result) {
        std::cout << "[";
        for (int i = 0; i < std::size(a); ++i) {
            std::cout << a[i];
            if (i < std::size(a) - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}