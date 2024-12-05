#include <iostream>
#include <random>
#include <ctime>
#include <vector>

// using namespace std;

void quick_sort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

void test(int len, int difference) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> arr(len, 0);
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = gen() % difference;
    }
    clock_t start = clock();
    quick_sort(arr, 0, arr.size() - 1);
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
    test(1000000, 1000000);
    test(2000000, 1000000);
    test(4000000, 1000000);
    std::vector<int> arr = {1, 3, 4, 10, 2};
    quick_sort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
