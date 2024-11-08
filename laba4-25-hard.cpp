#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void inputV(int n, vector<vector<int>>& matrix) {
    for (int i = 0; i < n; ++i) {
        int m;
        cout << "Введите количество элементов в подмассиве " << i + 1 << ": ";
        cin >> m;

        vector<int> innerVector(m);
        cout << "Введите элементы подмассива " << i + 1 << ": ";
        for (int j = 0; j < m; ++j) {
            std::cin >> innerVector[j];
        }
        matrix.push_back(innerVector);
    }
}

void printV(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

vector<int> merge(const vector<vector<int>>vec) {
    unordered_set<int> uniqueElements;
    vector<int> result;
    for (const auto& innerVec : vec) {
        for (int element : innerVec) {
            if (uniqueElements.insert(element).second) {
                result.push_back(element);
            }
        }
    }
    return result;
}

void sort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

vector<vector<vector<int>>> generate_combinations(const vector<vector<int>>& matrix) {
    std::vector<std::vector<std::vector<int>>> result;
    int n = matrix.size();

    for (int i = 1; i < (1 << n); ++i) {
        std::vector<std::vector<int>> subset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset.push_back(matrix[j]);
            }
        }
        result.push_back(subset);
    }

    return result;
}

bool vectorEquivalent(vector<int> vec1, vector<int> vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }
    sort(vec1);
    sort(vec2);

    for (size_t i = 0; i < vec1.size(); ++i) {
        if (vec1[i] != vec2[i]) {
            return false;
        }
    }

    return true;
}
int main() {
    int n, k;
    cout << "Введите количество элементов в массиве universe: ";
    cin >> k;
    vector<int>universe(k);
    cout << "Введите элементы массива: ";
    for (int j = 0; j < k; ++j) {
        std::cin >> universe[j];
    }
    cout << "Введите количество подмассивов: ";
    cin >> n;
    vector<vector<int>>matrix;
    inputV(n, matrix);
    vector<vector<vector<int>>> combinations = generate_combinations(matrix);
    int s = size(combinations);
    for (int i = 0; i<s; i++){
        vector<int>mergeVec = merge(combinations[i]);
        if (vectorEquivalent(mergeVec, universe)){
            cout << "Ответ: ";
             for (const auto& subVec : combinations[i]) {
                cout << "{ ";
                for (int val : subVec) {
                    cout << val << " ";
                }
                cout << "} ";
             }
        }
    }
    return 0;
}