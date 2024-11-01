//Поиск подмассивов размера K в массиве размера N, сумма элементов которых равна нулю
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


vector<int> new_indexes(vector<int> index, int N) {
    bool flag = false;
    if (index[0] == N - index.size()) {
        flag = true;
        for (int i = 1; i < index.size(); i++) {
            if (index[i] != index[i - 1] + 1) {
                flag = false;
            }
        }
    }

    if (flag) { // isEmpty?
        return vector(1, -1);
    }

    int i = index.size() - 1;
    index[i]++;
    while (index[i] == N) {
        index[i] = 0;
        i--;
        index[i]++;
    }
    return index;
}

vector<int> new_indexes_increasing (vector<int> index, int N) {
    bool flag = true;
    while (flag){
        index = new_indexes(index, N);
        if (index == vector(1,-1)) {
            return vector(1,-1);
        }
        flag = false;
        for (int i = 0; i < index.size() - 1; i++) {
            if (index[i] >= index[i+1]) {
                flag = true;
            }
        }
    }
    return index;
}



bool is_sum_zero(int arr[], vector<int> index, int K) {
    long sum = 0;
    for (int i = 0; i < K; i++) {
        sum += arr[index[i]];
    }
    if (sum == 0) {
        return true;
    } else {
        return false;
    }
}



vector<vector<int>> subarrays_with_sum_0(int arr[], int N, int K) {
    vector<vector<int>> result;
    if (K == 1 && arr[0] == 0) { // Проверь на пустой массив
        result.push_back({0});
    }
    vector<int> index = new_indexes_increasing(vector(K, 0), N);
    while (index != vector(1, -1)) {
        if (is_sum_zero(arr, index, K)) {
            result.push_back(index);
        }
        /*for (int i = 0; i < K; i++) {
            cout << index[i] << " ";
        }
        cout << "\n";*/
        index = new_indexes_increasing(index, N);
    }
    return result;
}



int test_passed = 0;
int test_failed = 0;

void assertEqual(vector<vector<int>> condition, vector<vector<int>> need, const std::string& testName) {
    if (condition == need) {
        std::cout << "[PASSED]" << testName << "\n";
        test_passed++;
    } else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}

void report() {
    std::cout << "\nИтого тестов пройдено: " << test_passed << "\n";
    std::cout << "\nИтого тестов не пройдено: " << test_failed << "\n";
}

void time(int arr[], int N, int K) {
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> result = subarrays_with_sum_0(arr, N, K);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << duration.count() << " milliseconds\n";
}

void times_for_different_K(int arr[], int N) {
    for (int K = 1; K < 6; K++) {
        time(arr, N, K);
    }
}

void asimptotika(int N) {
    long a = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int z = 0; z < N; z++) {
                for (int v = 0; v < N; v++) {
                    for (int d = 0; d < N; d++) {
                        a++;
                    }
                }
            }
        }
    }
}

int main() {
    /*int test = 0;
    int arr1[] {1,-1,2,-2};
    int arr2[] {1,-1,2,-3};
    int arr3[] {1,1,-1,-1};
    int arr4[] {0};
    int arr5[] {0,1,1,1};*/
    int arr6[] {1,2,3,-2,5,6,7,8,9,10,-1,12,13,-2,15,16,17,18,19,20,21,22,23,24,25};
    int arr7[] {1,2,3,-2,5,6,7,8,9,10,-1,12,13,-2,15,16,17,18,19,20};
    int arr8[] {1,2,3,-2,5,6,7,8,9,10,-1,12,13,-2,15};
    int arr9[] {1,2,3,-2,5,6,7,8,9,10};
    int arr10[] {1,2,3,-2,5};
    /*auto start = chrono::high_resolution_clock::now();
    assertEqual(subarrays_with_sum_0(arr1, 4, 2),{{0,1},{2,3}}," test1 from task");
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << duration.count() << " milliseconds\n";
    assertEqual(subarrays_with_sum_0(arr2,4,3),{{0,2,3}}," test2 from task");
    assertEqual(subarrays_with_sum_0(arr3,4,2),{{0,2},{0,3},{1,2},{1,3}}," test3 from task");
    assertEqual(subarrays_with_sum_0(arr4, 1, 1),{{0},}," {0}");
    assertEqual(subarrays_with_sum_0(arr5, 4, 2),{}," without solutions");
    assertEqual(subarrays_with_sum_0(arr6, 25, 5),{{0,1,10,13,24},{2,3}}," test1 from task");*/
    /*times_for_different_K(arr6, 25);
    times_for_different_K(arr7, 20);
    times_for_different_K(arr8, 15);
    times_for_different_K(arr9, 10);
    times_for_different_K(arr10, 5);*/
    auto start = chrono::high_resolution_clock::now();
    asimptotika(25);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << duration.count() << " milliseconds\n";
    /*for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }*/
    //report();
    return 0;

}