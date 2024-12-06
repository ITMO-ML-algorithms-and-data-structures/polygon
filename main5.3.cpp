#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>

// using namespace std;


void encounter_sort(std::vector<int>& array, std::vector<int>& result) {
    int min = array[0], max = array[0];
    for (int i = 0; i < array.size(); i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }
    std::vector<int> counter(max - min + 1, 0);
    for (int i = 0; i < array.size(); i++) {
        counter[array[i] - min]++;
    }
    int i = 0;
    for (int j = 0; j < counter.size(); j++) {
        for (int k = 0; k < counter[j]; k++) {
            result[i] = j + min;
            i++;
        }
    }
}

void test(int len, int difference) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> arr(len, 0);
    std::vector<int> res(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = gen() % difference;
    }
    clock_t start = clock();
    encounter_sort(arr, res);
    clock_t end = clock();
    std::cout << "Len: " << len << " Time: " << (long double)(end - start) / (long double)(CLOCKS_PER_SEC) << "\n";
    bool ok = true;
    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i + 1] < res[i]) {
            ok = false;
            break;
        }
    }
    if (ok == true) {
        std::cout << "OK\n";
    } else {
        std::cout << "Test Failed\n";
    }

}

int main() {
    test(10000000, 1000000);
    test(20000000, 1000000);
    test(40000000, 1000000);
    std::vector<int> arr = {1, 3, 4, 10, 2};
    std::vector<int> res(arr.size(), 0);
    encounter_sort(arr, res);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    return 0;
}
