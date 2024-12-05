#include <iostream>
#include <random>
#include <ctime>
#include <vector>

// using namespace std;


void odd_even_sort(std::vector<int>& array) {
    bool is_sorted = false;
    while (!is_sorted) {
        is_sorted = true;
        for (int i = 0; i < array.size() - 1; i += 2) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                is_sorted = false;
            }
        }
        for (int i = 1; i < array.size() - 1; i += 2) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                is_sorted = false;
            }
        }
    }
}


void test(int len, int difference) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> arr(len, 0);
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = gen() % difference;
    }
    clock_t start = clock();
    odd_even_sort(arr);
    clock_t end = clock();
    std::cout << "Len: " << len << " Time: " << (long double)(end - start) / (long double)(CLOCKS_PER_SEC) << "\n";
    bool ok = true;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i + 1] < arr[i]) {
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
    test(10000, 1000000);
    test(20000, 1000000);
    test(40000, 1000000);
    std::vector<int> arr = {1, 3, 4, 10, 2};
    odd_even_sort(arr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
