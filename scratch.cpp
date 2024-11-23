#include <iostream>
#include <vector>

std::vector<int> null_to_sr_ar(std::vector<int> &arr, const int size) {
    double srar = 0;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != -1) {
            count += 1;
            sum = sum + arr[i];
            std::cout << sum;
    srar = sum / count;
        }
        for (int i = 0; i < size; ++i) {
            if (arr[i] == -1) {
                arr[i] = srar;
            }
        }
    }
    return arr;
}

int main() {
    std::vector<int> arr = {1, -1, 10, 4};
    const int size = 4;
        std::vector<int> out = null_to_sr_ar(arr, size);
        std::cout << "Filled vector: ";
        for (int i = 0; i < size; ++i) {
            std::cout << out[i];
    }
    return 0;
}