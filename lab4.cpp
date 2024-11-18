#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sumArray(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

bool findSubset(vector<int>& arr, int n, int target, vector<int>& subset, bool& found) {
    if (found) return true; // Если уже нашли решение, останавливаемся
    if (target == 0) {
        found = true; // Отмечаем, что решение найдено
        return true;
    }
    if (n == 0 || target < 0) return false;

    // Пробуем включить текущий элемент
    subset.push_back(arr[n - 1]);
    if (findSubset(arr, n - 1, target - arr[n - 1], subset, found)) {
        return true;
    }

    // Пробуем исключить текущий элемент
    subset.pop_back();
    return findSubset(arr, n - 1, target, subset, found);
}

void splitArray(vector<int>& arr) {
    int totalSum = sumArray(arr);

    if (totalSum % 2 != 0) {
        cout << "Невозможно разделить массив на две равные части." << endl;
        return;
    }

    int target = totalSum / 2;
    vector<int> subset1;
    bool found = false;

    if (findSubset(arr, static_cast<int>(arr.size()), target, subset1, found)) {
        vector<int> subset2;
        unordered_map<int, int> count; // Для подсчёта оставшихся элементов
        for (int num : subset1) {
            count[num]++;
        }
        for (int num : arr) {
            if (count[num] > 0) {
                count[num]--;
            } else {
                subset2.push_back(num);
            }
        }

        cout << "Часть 1: ";
        for (int num : subset1) {
            cout << num << " ";
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

