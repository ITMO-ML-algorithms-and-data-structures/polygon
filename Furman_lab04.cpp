#include <iostream>
#include <vector>
#include <ctime>  // Для использования clock()

void findSubarraysWithZeroSum(const std::vector<int>& arr, int K) {
    int N = arr.size();
    // Перебираем все возможные подмассивы размером K
    for (int i = 0; i <= N - K; ++i) {
        int sum = 0;
        std::vector<int> indices;
        
        // Считаем сумму подмассива и сохраняем индексы
        for (int j = 0; j < K; ++j) {
            sum += arr[i + j];
            indices.push_back(i + j);
        }
        
        // Если сумма равна 0, выводим индексы
        if (sum == 0) {
            for (size_t k = 0; k < indices.size(); ++k) {
                std::cout << indices[k];
                if (k < indices.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    // Тестовые случаи
    std::vector<int> testCase1 = {1,  -1}; 
    int K1 = 2;

    // Измерение времени выполнения
    clock_t start = clock();
    std::cout << "Test Case 1:\n";
    findSubarraysWithZeroSum(testCase1, K1);
    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << timeTaken << " seconds.\n";

    std::vector<int> testCase2 = {1, 2, -3, 3, -1}; 
    int K2 = 3;
    start = clock();
    std::cout << "Test Case 2:\n";
    findSubarraysWithZeroSum(testCase2, K2);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << timeTaken << " seconds.\n";

    std::vector<int> testCase3 = {0, 0, 0, 0}; 
    int K3 = 2;
    start = clock();
    std::cout << "Test Case 3:\n";
    findSubarraysWithZeroSum(testCase3, K3);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << timeTaken << " seconds.\n";

    std::vector<int> testCase4 = {5, -5, 10, -10, 1, -1, 6, -6, 8, -8}; 
    int K4 = 2;
    start = clock();
    std::cout << "Test Case 4:\n";
    findSubarraysWithZeroSum(testCase4, K4);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << timeTaken << " seconds.\n";

    std::vector<int> testCase5 = {5, -5, 10, -10, 1}; 
    int K5 = 2;
    start = clock();
    std::cout << "Test Case 5:\n";
    findSubarraysWithZeroSum(testCase5, K5);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << timeTaken << " seconds.\n";

    return 0;
}
