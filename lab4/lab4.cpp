#include <iostream>
#include <vector>
#include <chrono>


void generateCombinations(const std::vector<int>& arr, std::vector<int>& combination, int K) {
        if (combination.size() == K) {
            int sum = 0;
            for (int num : combination) {
                sum += num;
            }
            if (sum == 0) {
                std::ios::sync_with_stdio(0);
                std::cin.tie(0); // Для быстрого вывода

                std::cout << "[";
                for (size_t i = 0; i < combination.size(); ++i) {
                    std::cout << combination[i];
                    if (i < combination.size() - 1) {
                    std::cout << ", ";
                        }
                }
            std::cout << "]" << std::endl;
            }
            return;
        }

        for (int i = 0; i < arr.size(); ++i) {
            combination.push_back(arr[i]);
            generateCombinations(arr, combination, K); // Рекурсия
            combination.pop_back();
        }
    
}

int main() {
    std::vector<int> arr = {1, -1, 2, -2, 3, -3, 0, 4, -4, 5, -5, 6, -6, 7, -7, 8, -8, 9, -9, 10, -10, 11, -11, 12, -12};
    int K = 9; // Длина подмассива
    std::vector<int> combination;

    auto start_time = std::chrono::high_resolution_clock::now();

    generateCombinations(arr, combination, K);

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time; 

    std::cout << "Время выполнения: " << elapsed.count() << " секунд." << std::endl;

    return 0;
}
