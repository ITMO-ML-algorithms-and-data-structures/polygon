#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> null_to_sr_ar(std::vector<int> arr, const int size) {
    int count = size; // O(1)
    int sum = std::accumulate(arr.begin(), arr.end(), 0); // O(1)
    for (int i = 0; i < size; i++) { // O(N)
        if (arr[i] == 0) { // O(1)
            count--;
        }
    }
    int srar = sum / count; // O(1)
    if (count > 0) {
        for (int i = 0; i < size; i++) { // (O(N)
            if (arr[i] == 0) { // O(1)
                arr[i] = srar; // O(1)
            }
        }
    }
    return arr;
}

int main() {
    std::vector<int> arr = {0, 1, 0, 0}; // O(N)
    const int size = arr.size(); // O(1)
        std::vector<int> out = null_to_sr_ar(arr, size); // O(1)
        std::cout << "Filled vector: " << std::endl;
        for (int i = 0; i < size; i++) { // O(N)
            std::cout << out[i] << std::endl; // O(1)
        }
    return 0;
}