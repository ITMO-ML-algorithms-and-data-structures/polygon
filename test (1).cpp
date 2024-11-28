#include <iostream>
#include <vector>

using namespace std;

void removeDuplicates(vector<int>& arr) { // Сложность внешнего цикла O(n), где n — размер вектора.
    for (size_t i = 0; i < arr.size(); ++i) {  // O(n)
        
        for (size_t j = i + 1; j < arr.size(); ) {  // O(n - i) = O(n)

            if (arr[i] == arr[j]) {  // Сложность O(1) для каждого сравнения.
                arr.erase(arr.begin() + j);  // O(n) для операции erase, так как все элементы после j сдвигаются.

            } else {
                j++;  // Сложность O(1) для увеличения индекса.
            }
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 1};  // Сложность O(1) для создания вектора.

    removeDuplicates(arr);  // O(n^2)

    for (int val : arr) {  // O(n)
        cout << val << " ";  // O(1) для вывода одного элемента.
    }

    return 0;  // Возврат из функции main. Сложность O(1).
}

// Итоговая сложность алгоритма O(n^2)
