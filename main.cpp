#include <iostream>
#include <vector>

void findZeroSum(const std::vector<int>& arr, int K) {
    int n = arr.size();

    
    bool found = false; // Флаг для проверки, были ли найдены подмассивы
    for (int i = 0; i <= n - K; ++i) {
        int sum = 0;
        for (int j = 0; j < K; ++j) {
            sum += arr[i + j]; 
        }

        if (sum == 0) { // Проверяем, равна ли сумма нулю
            found = true;
            std::cout << "Индексы: [";
            for (int j = 0; j < K; ++j) {
                std::cout << (i + j);
                if (j < K - 1) std::cout << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }

    if (!found) {
        std::cout << "Подмассивы длиной " << K << " с нулевой суммой не найдены." << std::endl;
    }
}

int main() {
    int N;
    std::cout << "Введите размер массива: ";
    std::cin >> N;

    std::vector<int> arr(N);
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    const int K = 6; 
    findZeroSum(arr, K);

    return 0;
}
