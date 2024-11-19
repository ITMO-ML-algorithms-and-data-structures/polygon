#include <iostream>
#include <vector>

using namespace std;

bool split(const vector<int>& arr, int n, int sum1, int sum2, vector<int>& subset1, vector<int>& subset2) {
    if (n == 0) {
        return sum1 == sum2;
    }

    subset1.push_back(arr[n - 1]);
    if (split(arr, n - 1, sum1 + arr[n - 1], sum2, subset1, subset2)) {
        return true;
    }
    subset1.pop_back();

    subset2.push_back(arr[n - 1]);
    if (split(arr, n - 1, sum1, sum2 + arr[n - 1], subset1, subset2)) {
        return true;
    }
    subset2.pop_back();

    return false;
}

int main() {
    vector<int> arr = {1, 1, 1, 1, 2};
    vector<int> subset1, subset2;
    const int N = size(arr);
    int totalSum = 0;
    for (int num : arr) {
        totalSum += num;
    }

    if (totalSum % 2 != 0) {
        cout << "Невозможно разделить массив на две части с равной суммой." << endl;
        return 0;
    }

    if (split(arr, N, 0, 0, subset1, subset2)) {
        cout << "Первый массив: ";
        for (int num : subset1) {
            cout << num << " ";
        }
        cout << endl;

        cout << "Второй массив: ";
        for (int num : subset2) {
            cout << num << " ";
        }
        cout << endl;
    } 
    else {
        cout << "Невозможно разделить массив на две части с равной суммой." << endl;
    }

    return 0;

}
