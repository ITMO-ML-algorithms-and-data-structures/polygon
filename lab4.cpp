#include <iostream>
#include <vector>

std::vector<std::vector<int>> findArrayWithZeroSums(std::vector<int>& arr) {
    int n = arr.size(); // 4 байта; O(1)
    int k = 10; // 4 байта; O(1)
    std::vector<std::vector<int>> res; // 24*2 = 48 байта на инициализацию векторов + (4 * C(n, 10)), где С(n, 10) максимальное количество перестановок по биному Ньютона длины 10; O(C(n, 10))

    for (int i = 0; i < n - 9; i++) { // 4 байта
        for (int j = i + 1; j < n - 8; j++) { // 4 байта
            for (int k = j + 1; k < n - 7; k++) { // 4 байта
                for (int a = k + 1; a < n - 6; a++) { // 4 байта
                    for (int b = a + 1; b < n - 5; b++) { // 4 байта
                        for (int c = b + 1; c < n - 4; c++) { // 4 байта
                            for (int d = c + 1; d < n - 3; d++) { // 4 байта
                                for (int e = d + 1; e < n - 2; e++) { // 4 байта
                                    for (int f = e + 1; f < n - 1; f++) { // 4 байта
                                        for (int g = f + 1; g < n; g++) { // 4 байта
                                            if (arr[i] + arr[j] + arr[k] + arr[a] + arr[b] + arr[c] + arr[d] + arr[e] + arr[f] + arr[g] == 0) { // O(1) + O(1) + O(1) + O(1) + O(1) + O(1) + O(1) + O(1) + O(1) + O(1) = O(1)
                                                res.push_back({i, j, k, a, b, c, d, e, f, g}); // O(1)
                                                // Сложность цикла O(N^10)
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return res;
}


int main() {
    std::vector<int> arr = {3, -7, 4, 1, -1, 0, 5, -5, 6, -6}; // 25 * 4 = 100 байт максимум; O(1) // {3, -7, 4, 1, -1, 0, 5, -5, 6, -6, 2, -2, 0, 0, 3, -3, 7, -4, -1, 1, 8, -8, -3, 2, -2}

    std::vector<std::vector<int>> res = findArrayWithZeroSums(arr); // 24*2 = 48 байта на инициализацию векторов + (4 * C(n, 10)), где С(n, 10) максимальное количество перестановок по биному Ньютона длины 10; O(1) 

    for (const auto& indices : res) {
        std::cout << "[";
        for (size_t i = 0; i < indices.size(); ++i) {
            std::cout << indices[i];
            if (i < indices.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
    /*
    Итого по асимптотике: O(N^10)
    Итого по памяти: 4*12 + 48+(4*C(n, 10)) + 100 байт
    */
    return 0;
}
