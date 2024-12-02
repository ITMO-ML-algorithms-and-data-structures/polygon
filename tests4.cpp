#include <iostream>
#include <vector>
using namespace std;

bool canPartition(const vector<int>& nums, vector<int>& subset1, vector<int>& subset2) { 
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    if (totalSum % 2 != 0) {
        return false;
    }

    int target = totalSum / 2;
    int n = nums.size();

    for (int mask = 0; mask < (1 << n); ++mask) {
        int subsetSum = 0;
        subset1.clear();
        subset2.clear();

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subsetSum += nums[i];
                subset1.push_back(nums[i]);
            } else {
                subset2.push_back(nums[i]);
            }
        }

        if (subsetSum == target) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> testCases = {
        {10, 10, 10, 10},       // Тест 1: можно разделить, содержит одинаковые числа
        {0, 0, 0, 0},           // Тест 2: содержит нули
        {2, 9, 5, 6},           // Тест 3: можно разделить
        {3, 2, 5, 9},           // Тест 4: нельзя разделить
        {-1, 2, 3},             // Тест 5: содержит отрицательное число
        {4, 5, 6}               // Тест 6: нельзя разделить
    };

    for (const auto& arr : testCases) {
        // Проверка на положительные числа
        bool allPositive = true;
        for (int num : arr) {
            if (num <= 0) {
                allPositive = false;
                break;
            }
        }

        if (!allPositive) {
            cout << "Массив содержит неположительные числа. Пропускаем тест." << endl;
            continue; // Пропустить этот тест
        }

        vector<int> subset1, subset2;

        cout << "Тест с массивом: [";
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ", ";
        }
        cout << "]" << endl;

        if (canPartition(arr, subset1, subset2)) {
            cout << "Массив можно разделить на две части с равной суммой." << endl;
            cout << "Подмножества: ["; 
            for (int i = 0; i < subset1.size(); ++i) {
                cout << subset1[i];
                if (i < subset1.size() - 1) cout << ", "; 
            }
            cout << "], [";
            for (int i = 0; i < subset2.size(); ++i) {
                cout << subset2[i];
                if (i < subset2.size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        } else {
            cout << "Массив нельзя разделить на две части с равной суммой." << endl;
        }
        cout << endl; // Для разделения тестов
    }

    return 0;
}
