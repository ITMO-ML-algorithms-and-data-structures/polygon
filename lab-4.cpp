#include <iostream>
#include <vector>

using namespace std;
bool canPartition(const vector<int>& arr, int index, int sum1, int sum2) {
    if (index == arr.size()) { // O(1)
        return sum1 == sum2; // O(1)
    }
    if (canPartition(arr, index + 1, sum1 + arr[index], sum2)) { // O(2^n) 
        return true; // O(1)
    }
    if (canPartition(arr, index + 1, sum1, sum2 + arr[index])) { // O(2^n) 
        return true; // O(1)
    }
    return false; // O(1)
}
bool canPartition(const vector<int>& arr) {
    int totalSum = 0; // O(1)
    for (size_t i = 0; i < arr.size(); ++i) { // O(n)
        totalSum += arr[i]; // O(1)
    }
    if (totalSum % 2 != 0) { // O(1)
        return false; // O(1)
    }
    return canPartition(arr, 0, 0, 0); // O(2^n)
}
int main() {
    vector<int> arr(4); // O(1) 
    arr[0] = 1; // O(1)
    arr[1] = 5; // O(1)
    arr[2] = 11; // O(1)
    arr[3] = 5; // O(1)

    if (canPartition(arr)) { // O(2^n) 
        cout << "Массив можно разделить на две части с равной суммой." << endl; // O(1)
    } else {
        cout << "Массив нельзя разделить на две части с равной суммой." << endl; // O(1)
    }

    return 0; // O(1)
}
/*
Общая временная сложность: O(2^n)
Общая пространственная сложность: O(n)
*/