#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;



vector<int> shift(vector<int> arr, int k) {
    int len = arr.size(); // O(N) выделение памяти
    k = k % len; 
    vector<int> new_arr(len); // O(len) выделяется определенное кол во памяти


    for(int i = 0; i < k; i++){ // O(N) - Цикл зависит от кол во элементов
        new_arr[i] = arr[len - k + i];  // O(1) + O(1) + O(1) - взятие эл-та по индексу +присваивание 
    }
    

    for(int i = 0; i < len - k; i++){ // O(N) - Цикл зависит от кол во элементов
        new_arr[i + k] = arr[i]; // O(1) + O(1) + O(1) - взятие эл-та по индексу +присваивание
    }
    // сложность алгоритма состовляет O(N) в худшем случае 
    // алгоритмическая сложность зависит от размера вектора 

    return new_arr;
}

int test_passed = 0;
int test_failed = 0;


void assertEqual(vector<int> shifted_list, vector<int> expected_list, const std::string& testName) {
    if (shifted_list == expected_list) {
        std::cout << "[PASSED]" << testName << "\n";
        test_passed++;
    } else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}

void report() {
    std::cout << "\nPassed tests: " << test_passed << "\n";
    std::cout << "\nFailed tests: " << test_failed << "\n";
} 

int main(){
    assertEqual(shift({1, 2, 3, 4, 5}, 1), {5, 1, 2, 3, 4}, "Test 1");
    assertEqual(shift({1, 2}, 3), {2, 1}, "Test 2");
    assertEqual(shift({1}, 5), {1}, "Test 3");
    assertEqual(shift({1, 1, 1, 1, 1, 1, 1, 1, 1}, 3435), {1, 1, 1, 1, 1, 1, 1, 1, 1}, "Test 4");
    assertEqual(shift({1, 2, 3, 4, 5}, 0), {1, 2, 3, 4, 5}, "Test 5");
    report();
    // vector<int> arr = shift({}, 2);
    // for(int i = 0; i < 3; i++){
    //     cout << arr[i];
    // }

    return 0;
}
