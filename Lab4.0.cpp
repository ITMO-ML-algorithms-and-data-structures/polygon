#include <iostream>
#include <vector>
#include <ctime> // Для измерения времени
#include <cassert> // Для assert

// Функция для поиска всех подмассивов размера K с суммой равной 0
void findSubarraysWithZeroSum(const std::vector<int>& arr, int K) {
    int N = arr.size();
    std::vector<int> indices(K);

    auto generateCombinations = [&](auto&& self, int start, int depth) -> void {
        if (depth == K) {
            int sum = 0;
            for (int idx : indices) {
                sum += arr[idx];
            }
            if (sum == 0) {
                // Выводим индексы текущего подмассива
                std::cout << "[";
                for (size_t i = 0; i < indices.size(); ++i) {
                    std::cout << indices[i] << (i < indices.size() - 1 ? ", " : "");
                }
                std::cout << "]\n";
            }
            return;
        }
        for (int i = start; i < N; ++i) {
            indices[depth] = i;
            self(self, i + 1, depth + 1);
        }
    };

    generateCombinations(generateCombinations, 0, 0);
}

// Тестирующая функция
void runTests() {
    // Тест 1: Простая проверка
    {
        std::vector<int> arr = {1, -1, 2, -2};
        int K = 2;
        std::cout << "Test 1: \n";
        findSubarraysWithZeroSum(arr, K);
        std::cout << "\nExpected: [0, 1] [2, 3]\n\n";
    }

    // Тест 2: Больше значений
    {
        std::vector<int> arr = {1, -1, 2, -3};
        int K = 3;
        std::cout << "Test 2: \n";
        findSubarraysWithZeroSum(arr, K);
        std::cout << "\nExpected: [0, 2, 3]\n\n";
    }

    // Тест 3: Повторяющиеся элементы
    {
        std::vector<int> arr = {1, 1, -1, -1};
        int K = 2;
        std::cout << "Test 3: \n";
        findSubarraysWithZeroSum(arr, K);
        std::cout << "\nExpected: [0, 2] [0, 3] [1, 2] [1, 3]\n\n";
    }

    // Тест 4: Нет решений
    {
        std::vector<int> arr = {1, 2, 3, 4};
        int K = 2;
        std::cout << "Test 4: \n";
        findSubarraysWithZeroSum(arr, K);
        std::cout << "\nExpected: (no output)\n\n";
    }

    // Тест 5: Все элементы 0
    {
        std::vector<int> arr = {0, 0, 0, 0};
        int K = 3;
        std::cout << "Test 5: \n";
        findSubarraysWithZeroSum(arr, K);
        std::cout << "\nExpected: [0, 1, 2] [0, 1, 3] [0, 2, 3] [1, 2, 3]\n\n";
    }
}

// Функция для измерения производительности
void measurePerformance() {
    int K = 5; // Фиксированный размер подмассива
    std::cout << "N, Time (ms)\n";
    for (int N = 5; N <= 25; ++N) {
        std::vector<int> arr(N, 1); // Создаем массив из N единиц
        clock_t start = clock();
        findSubarraysWithZeroSum(arr, K);
        clock_t end = clock();
        double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        std::cout << N << ", " << duration << "\n";
    }
}

int main() {
    std::cout << "Running tests...\n";
    runTests();

    std::cout << "\nMeasuring performance...\n";
    measurePerformance();

    return 0;
}
