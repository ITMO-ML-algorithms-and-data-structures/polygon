#include <iostream>
#include <vector>
#include "testcluster.h"

/*
Общая временная сложность алгоритма:
   - В худшем случае, общая временная сложность будет O(K^n * m), где n — количество элементов в массиве, K — количество кластеров,
     и m — размер кластера. Для каждого разбиения (K) мы вычисляем метрику для каждого кластера.

Общая память:
   - В худшем случае, общая память будет O(K^n), так как мы храним все возможные комбинации кластеров в allClusters.
   - Дополнительно, в памяти будет O(n) для хранения входного массива, где n — количество элементов.
   - Общая память: O(K^n + n).
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
    printClusters(findOptimalClusters(array, K));
    return 0;
}
