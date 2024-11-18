#include <iostream>
#include <vector>
using namespace std;


int sumArray(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}


bool findSubset(vector<int>& arr, int n, int target, vector<int>& subset) {
    if (target == 0) return true;
    if (n == 0 || target < 0) return false;
    
    subset.push_back(arr[n - 1]);
    if (findSubset(arr, n - 1, target - arr[n - 1], subset)) {
        return true;
    }

    
    subset.pop_back();
    return findSubset(arr, n - 1, target, subset);
}


void splitArray(vector<int>& arr) {
    int totalSum = sumArray(arr);

    
    if (totalSum % 2 != 0) {
        cout << "Невозможно разделить массив на две равные части." << endl;
        return;
    }

    int target = totalSum / 2;
    vector<int> subset1;

    
    if (findSubset(arr, static_cast<int>(arr.size()), target, subset1)) {
        
        vector<int> subset2;
        for (int num : arr) {
            bool found = false;
            for (int& selected : subset1) {
                if (num == selected) {
                    found = true;
                    selected = -1;
                    break;
                }
            }
            if (!found) {
                subset2.push_back(num);
            }
        }

        
        cout << "Часть 1: ";
        for (int num : subset1) {
            if (num != -1) cout << num << " ";
        }
        cout << endl;

        cout << "Часть 2: ";
        for (int num : subset2) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "Невозможно разделить массив на две равные части." << endl;
    }
}

int main() {
    vector<int> arr = {1, 5, 11, 5};
    splitArray(arr);
    return 0;
}
