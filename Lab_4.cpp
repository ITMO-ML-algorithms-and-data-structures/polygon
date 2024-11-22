#include <iostream>
#include <vector>
#include <limits>
#include <cassert>

// Функция для вычисления метрики
double metric(const std::vector<double>& cluster) {
    double mean = 0.0;
    for (int i = 0; i < cluster.size(); i++) {
        mean += cluster[i];
    }
    mean /= cluster.size();

    double metric = 0.0;
    for (int i = 0; i < cluster.size(); i++) {
        metric += std::abs(cluster[i] - mean);
    }
    return metric;
}

// Рекурсивная функция для генерации всех разбиений и подсчета минимальной метрики
void findOptimalPartition(const std::vector<double>& arr, int k, int start,
                          std::vector<std::vector<double>>& currentPartition,
                          double& minMetric, std::vector<std::vector<double>>& bestPartition) {
    // Базовый случай рекурсии: достигли нужного числа кластеров (k == 1)
    if (k == 1) {
        // Добавляем остаток массива в последний кластер
        std::vector<double> cluster(arr.begin() + start, arr.end());
        currentPartition.push_back(cluster);

        // Считаем метрику для текущего разбиения
        double currentMetric = 0.0;
        for (int i = 0; i < currentPartition.size(); i++) {
            // calculateMetric имеет сложность O(M) M - размер кластера
            currentMetric += metric(currentPartition[i]);
        }

        // Обновляем минимальную метрику и лучшее разбиение
        if (currentMetric < minMetric) {
            minMetric = currentMetric;
            bestPartition = currentPartition;
        }

        // Удаляем последний добавленный кластер
        currentPartition.pop_back();
        return;
    }

    // Пробуем разбиение, добавляя элементы в текущий кластер
    // O(n - start - k)
    for (int i = start; i <= arr.size() - k; ++i) {
        std::vector<double> cluster(arr.begin() + start, arr.begin() + i + 1);
        currentPartition.push_back(cluster);

        // Рекурсивно разбиваем оставшуюся часть массива
        // O(2^n) - вызов рекурсивной функции
        findOptimalPartition(arr, k - 1, i + 1, currentPartition, minMetric, bestPartition);

        // Удаляем текущий кластер из текущего разбиения
        currentPartition.pop_back();
    }
}

void Test() {
    std::vector<double> arr_1 = { 1, 2, 3, 4, 5, 6 };
    int k_1 = 2;
    std::vector<std::vector<double>> ans_1 = { {1, 2, 3}, {4, 5, 6} };
    double minMetric = std::numeric_limits<double>::max();
    std::vector<std::vector<double>> bestPartition;
    std::vector<std::vector<double>> currentPartition;
    findOptimalPartition(arr_1, k_1, 0, currentPartition, minMetric, bestPartition);
    assert(bestPartition == ans_1);
    std::cout << "первый тест прошел"<< std::endl;
    bestPartition.clear();
    currentPartition.clear();

    std::vector<double> arr_2 = { 1, 2, 3, 4, 5, 6, 7 };
    int k_2 = 7;
    std::vector<std::vector<double>> ans_2 = { {1}, {2}, {3}, {4}, {5}, {6}, {7}};
    minMetric = std::numeric_limits<double>::max();
    findOptimalPartition(arr_2, k_2, 0, currentPartition, minMetric, bestPartition);
    assert(bestPartition == ans_2);
    std::cout << "второй тест прошел"<< std::endl;
    bestPartition.clear();
    currentPartition.clear();

    std::vector<double> arr_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int k_3 = 7;
    std::vector<std::vector<double>> ans_3 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    minMetric = std::numeric_limits<double>::max();
    findOptimalPartition(arr_3, k_3, 0, currentPartition, minMetric, bestPartition);
    assert(bestPartition == ans_3);
    std::cout << "третий тест прошел"<< std::endl;
}


int main() {
    Test();
    std::vector<double> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}; // Массив значений
    int K = 7; // Количество кластеров

    // Замер времени
    auto start = std::chrono::high_resolution_clock::now();

    // Инициализация переменных для хранения результата
    double minMetric = std::numeric_limits<double>::max();
    std::vector<std::vector<double>> bestPartition;
    std::vector<std::vector<double>> currentPartition;

    // Поиск оптимального разбиения
    findOptimalPartition(arr, K, 0, currentPartition, minMetric, bestPartition);

    // Вывод
    for (int i = 0; i < bestPartition.size(); i++) {
        std::cout << "[ ";
        for (int j = 0; j < bestPartition[i].size(); j++) {
            std::cout <<  bestPartition[i][j] << " ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    // Замер времени выполнения
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << elapsed.count() << " секунд";

    return 0;
}
