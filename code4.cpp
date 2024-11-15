#include <iostream>
#include <vector>

using namespace std;

// функция для проверки, равна ли сумма подмассива нулю
bool isZeroSum(const vector<int>& arr, const vector<int>& indices) {
    int sum = 0;
    for (int idx : indices) {
        sum += arr[idx];
    }
    return sum == 0;
}

// hекурсивная функция для генерации комбинаций
void findCombinations(const vector<int>& arr, vector<int>& current, int start, int K, vector<vector<int>>& result) {
    if (current.size() == K) {
        if (isZeroSum(arr, current)) {
            result.push_back(current);
        }
        return;
    }

    for (int i = start; i < arr.size(); ++i) {
        current.push_back(i);
        findCombinations(arr, current, i + 1, K, result);
        current.pop_back();
    }
}

int main() {
    vector<int> arr = {1, -1, 2, -3};
    int K = 3;
    vector<vector<int>> result;
    vector<int> current;

    // uенерация комбинаций
    findCombinations(arr, current, 0, K, result);

    // dывод результата
    cout << "Комбинации индексов размера " << K << ", где сумма элементов равна 0:" << endl;
    for (const auto& subarray : result) {
        cout << "[";
        for (size_t i = 0; i < subarray.size(); ++i) {
            cout << subarray[i];
            if (i != subarray.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}