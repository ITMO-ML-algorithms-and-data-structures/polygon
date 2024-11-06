#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <random>
#include <cassert>
#include <limits>


// Средние значение элементов кластера
double meanCluster(const std::vector<double>& cluster) {
    double sum = std::accumulate(cluster.begin(), cluster.end(), 0.0);
    int sizeCluster = cluster.size();
    return sum / sizeCluster;
}


// Метрика для кластера
double metricCluster(const std::vector<double>& cluster) {
    int sizeCluster = cluster.size();
    double sum = 0.0;
    double mean = meanCluster(cluster);
    for (int i = 0; i < sizeCluster; ++i){
        sum += fabs(cluster[i] - mean);
    }
    return sum;
}


// Получение оптимального набора кластеров из массива по заданной метрике
// index - элемент, который мы рассматриваем
// array - заданный массив
// curClusters - кластер, который получился на данной итерации
// optimalClusters - ответ, самый оптимальный кластер на данной итерации
// minMetric - метрика для оптимального кластера на данный момент
void getOptimalClusters(int index, const std::vector<double>& array, std::vector<std::vector<double>> curClusters,
std::vector<std::vector<double>>& optimalClusters, double& minMetric) {
    int sizeArray = array.size(); // Кол-во эл-ов массива
    int numClusters = curClusters.size(); // Кол-во кластеров

    if (index == sizeArray) { // Если рассмотрели все эл-ы
        // Проверка, чтобы все кластеры были не пустые
        bool anyNoneEmpty = std::any_of(curClusters.begin(), curClusters.end(),
        [](std::vector<double> value) -> bool { // Лямбда-функция, чтоб весело было)
            return value.size() == 0;
        });

        if (anyNoneEmpty) { // Если хотя бы один пустой - не подходит
            return;
        }

        // Общая метрика для кластеров
        double metricSum = 0.0;
        for (int i = 0; i < numClusters; ++i) {
            metricSum += metricCluster(curClusters[i]);
        }

        // Замена на лучший кластер
        if (metricSum < minMetric){
            minMetric = metricSum;
            optimalClusters = curClusters;
        }
        return;
    }

    // Проверка на пустоту предыд кластера
    // Если он пустой - не имеет смысла
    // заполнять след, так как порядок
    // не имеет смысла
    bool previousClusterWasEmpty = false;
    for (int i = 0; i < numClusters; ++i){
        if (previousClusterWasEmpty) {
            break;
        }

        // Рекурсивно смотрим последующий варианты
        curClusters[i].push_back(array[index]);
        getOptimalClusters(index + 1, array, curClusters, optimalClusters, minMetric);
        curClusters[i].pop_back();

        // Для след сохраняем состояние кластера
        // Если он пустой - true, иначе - false
        previousClusterWasEmpty = curClusters[i].size() == 0;
    }
}


void test(int numClusters)
{
    std::random_device rd;
    std::mt19937 seed(rd());

    int sizeArray = 11;
    std::vector<double> array(sizeArray);

    for (int i = 0; i < sizeArray; ++i) array[i] = rd() % 999999;

    // Вывод массива
    for (int i : array) std::cout << i << " ";

    // Разбиения на кластеры
    std::vector<std::vector<double>> clusters(numClusters, std::vector<double>());
    // Метрика для кластеров
    double metricClusters = std::numeric_limits<double>::max();

    getOptimalClusters(0, array, clusters, clusters, metricClusters);

    // Вывод разбиения на кластеры
    std::cout << "\n| ";
    for (std::vector<double> i : clusters){
        for (double j : i){
            std::cout << j << " ";
        }
        std::cout << "| ";
    }

    // Вывод метрики
    std::cout << "\nМетрика: " << metricClusters;
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();

    test(5);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "\nВремя выполнения программы: " << duration.count() << " секунд" << "\n";
    return 0;
}