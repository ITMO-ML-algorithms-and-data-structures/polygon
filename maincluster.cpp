#include <iostream>
#include <vector>
#include "testcluster.h"

/*
Общая временная сложность алгоритма:
   - В худшем случае, общая временная сложность будет O(K^n * m), где n — количество элементов в массиве, K — количество кластеров,
     и m — размер кластера. Для каждого разбиения (K) мы вычисляем метрику для каждого кластера.
*/

int main() {
    runTests(); // Запускаем тесты

    int K;
    std::cout << "Enter the number of clusters (K):\n";
    std::cin >> K;

    int n;
    std::cout << "Enter the number of elements in the array (>=K):\n ";
    std::cin >> n;

    std::vector<double> array(n);
    std::cout << "Enter the elements of the array:\n ";
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    findOptimalClusters(array, K);

    return 0;
}
