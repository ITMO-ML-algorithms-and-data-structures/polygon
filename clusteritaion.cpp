#include "testcluster.h"
#include <iostream>
#include <limits>
#include <cassert>

// Функция для вычисления метрики кластера
double calculateMetric(const std::vector<double> &cluster) {
    double sum = 0;
    // Суммируем все значения в кластере
    for (double value: cluster) {
        sum += value;
    }
    // Вычисляем среднее значение
    double mean = sum / cluster.size();
    double metric = 0;
    // Считаем сумму абсолютных отклонений от среднего
    for (double value: cluster) {
        metric += std::abs(value - mean);
    }
    return metric; // Возвращаем вычисленную метрику
}
// Временная сложность: O(m), где m — количество элементов в кластере.
// Память: O(1), так как используем ссылку(передачу по адресу).


// Рекурсивная функция для нахождения всех возможных кластеров
void findClusters(const std::vector<double> &array, int index, int K,
                  std::vector<std::vector<std::vector<double>>> &allClusters,
                  std::vector<std::vector<double>> &currentClusters) {
    // Если достигнут конец массива
    if (index == array.size()) {
        // Если текущий набор кластеров содержит K кластеров, сохраняем его
        if (currentClusters.size() == K) {
            allClusters.push_back(currentClusters);
        }
        return;
    }

    // Рекурсивно добавляем элементы в существующие кластеры
    for (int i = 0; i < currentClusters.size(); ++i) {
        currentClusters[i].push_back(array[index]); // Добавляем элемент
        findClusters(array, index + 1, K, allClusters, currentClusters); // Рекурсивный вызов
        currentClusters[i].pop_back(); // Удаляем элемент для следующего вызова
    }

    // Добавляем новый кластер, если еще не достигли K
    if (currentClusters.size() < K) {
        currentClusters.push_back(std::vector<double>{array[index]}); // Создаем новый кластер
        findClusters(array, index + 1, K, allClusters, currentClusters); // Рекурсивный вызов
        currentClusters.pop_back(); // Удаляем новый кластер для следующего вызова
    }
}
// Временная сложность: O(K^n), где n — количество элементов в массиве и K — количество кластеров.
// Память: O(K^n), так как сохраняем все возможные комбинации кластеров в allClusters.


// Функция для нахождения оптимальных кластеров
std::vector<std::vector<double>> findOptimalClusters(const std::vector<double> &array, int K) {
    std::vector<std::vector<std::vector<double>>> allClusters;  // Для хранения всех кластеров
    std::vector<std::vector<double>> currentClusters;  // Для текущих кластеров

    findClusters(array, 0, K, allClusters, currentClusters);

    // Поиск кластера с минимальной метрикой
    double minMetric = std::numeric_limits<double>::max();  // Инициализируем минимальную метрику
    std::vector<std::vector<double>> bestClusters;  // Для хранения лучших кластеров

    // Проход по всем кластерам, чтобы найти минимальную метрику
    for (const auto &clusters: allClusters) {
        double totalMetric = 0;
        for (const auto &cluster: clusters) {
            totalMetric += calculateMetric(cluster);  // Суммируем метрики всех кластеров
        }
        if (totalMetric < minMetric) {  // Если найден новый минимум
            minMetric = totalMetric;
            bestClusters = clusters;  // Сохраняем лучшие кластеры
        }
    }

    return bestClusters;  // Возвращаем лучшие кластеры
}

// Временная сложность: O(K^n * m), где n — количество элементов в массиве, K — количество кластеров и m — размер кластера.
// Память: O(K^n), так как храним все возможные комбинации кластеров в allClusters и лучшие кластеры в bestClusters.

// Функция для печати кластеров
void printClusters(const std::vector<std::vector<double>> &clusters) {
    for (const auto &cluster: clusters) {
        std::cout << "[ ";
        for (double element: cluster) {
            std::cout << element << " ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;
}


void runTests() {
    // Тесты для calculateMetric
    // 1. Тест с положительными целыми числами
    std::vector<double> testCluster1 = {1, 2, 3, 4, 5};
    assert(calculateMetric(testCluster1) == 6.0); // Ожидаемое значение: 6.0 (отклонения от 3)

    // 2. Тест с равными значениями
    std::vector<double> testCluster2 = {5, 5, 5};
    assert(calculateMetric(testCluster2) == 0.0); // Ожидаемое значение: 0.0 (отклонения от 5)

    // 3. Тест с дробными числами
    std::vector<double> testCluster3 = {0.5, 1.5, 2.5};
    assert(calculateMetric(testCluster3) == 2.0); // Ожидаемое значение: 2.0 (отклонения от 1.5)

    // 4. Тест с отрицательными числами
    std::vector<double> testCluster4 = {-1, -2, -3};
    assert(calculateMetric(testCluster4) == 2.0); // Ожидаемое значение: 2.0 (отклонения от -2)

    // 5. Тест с отрицательными и положительными числами
    std::vector<double> testCluster5 = {-5.5, 0.0, 5.5};
    assert(calculateMetric(testCluster5) == 11.0); // Ожидаемое значение: 11.0 (отклонения от 0)

    // 6. Тест с пустым кластером
    std::vector<double> testCluster6 = {};
    assert(calculateMetric(testCluster6) == 0.0); // Ожидаемое значение: 0.0 (пустой кластер)

    // 7. Просто тест с большим отклонением
    std::vector<double> testCluster7 = {10, 20, 30, 40, 50};
    assert(calculateMetric(testCluster7) == 60.0); // Ожидаемое значение: 60.0 (отклонения от 30)

    std::cout << "All tests for calculateMetric passed!" << std::endl;

    // Тесты для findOptimalClusters
    // Тест 1: Проверка на правильное разбиение массива на два равных кластера
    std::vector<double> input1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<std::vector<double>> expected1 = {{1.0, 2.0, 3.0},
                                                  {4.0, 5.0, 6.0}};
    assert(findOptimalClusters(input1, 2) == expected1);

    // Тест 2: Проверка на разбиение массива на три кластера
    std::vector<double> input2 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
    std::vector<std::vector<double>> expected2 = {{1.0,  2.0,  3.0, 4.0, 5.0},
                                                  {6.0,  7.0,  8.0, 9.0},
                                                  {10.0, 11.0, 12.0}};
    assert(findOptimalClusters(input2, 3) == expected2);

    // Тест 3: Проверка на разбиение массива с дробными значениями
    std::vector<double> input3 = {0.5, 1.5, 2.5, 3.5, 4.5};
    std::vector<std::vector<double>> expected3 = {{0.5, 1.5, 2.5},
                                                  {3.5, 4.5}};
    assert(findOptimalClusters(input3, 2) == expected3);

    // Тест 4: Проверка на разбиение массива с отрицательными значениями
    std::vector<double> input4 = {-5.0, -4.0, -3.0, -2.0, -1.0, 0.0};
    std::vector<std::vector<double>> expected4 = {{-5.0, -4.0, -3.0},
                                                  {-2.0, -1.0},
                                                  {0.0}};
    assert(findOptimalClusters(input4, 3) == expected4);

    // Тест 5: Проверка на разбиение с разными диапазонами значений
    std::vector<double> input5 = {-10.5, -13.0, -90.0, -99.999, 4.0, 0.123, -3.0, -0.31, 0.0, 100.0, 90.0, 95.0};
    std::vector<std::vector<double>> expected5 = {{-10.5, -13.0},
                                                  {-90.0, -99.999},
                                                  {4.0,   0.123, -3.0, -0.31, 0.0},
                                                  {100.0, 90.0,  95.0}};
    assert(findOptimalClusters(input5, 4) == expected5);

    // Тест 6: Проверка на разбиение массива с одинаковыми элементами
    std::vector<double> input6 = {5.0, 5.0, 5.0, 5.0, 5.0};
    std::vector<std::vector<double>> expected6 = {{5.0, 5.0, 5.0, 5.0},
                                                  {5.0}};
    assert(findOptimalClusters(input6, 2) == expected6);

    // Тест 7: Проверка на разбиение массива с экстремальными значениями
    std::vector<double> input7 = {-1000.0, -500.0, 0.0, 500.0, 1000.0};
    std::vector<std::vector<double>> expected7 = {{-1000.0, -500.0, 0.0},
                                                  {500.0},
                                                  {1000.0}};
    assert(findOptimalClusters(input7, 3) == expected7);

    std::cout << "All tests for findOptimalClusters passed!" << std::endl;
}
