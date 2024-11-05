#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для расчета суммы отклонений от среднего значения в кластере
double calculateClusterCost(const vector<double>& cluster) {
    double mean = 0;
    // Вычисляем среднее значение элементов в кластере
    for (double val : cluster) {
        mean += val;
    }
    mean /= cluster.size();

    double cost = 0;
    // Вычисляем сумму отклонений каждого элемента от среднего значения
    for (double val : cluster) {
        cost += abs(val - mean);
    }
    return cost;
}

// Рекурсивная функция для поиска оптимального разбиения
void findOptimalPartition(const vector<double>& arr, int index, int k, vector<vector<double>>& сurrentPartition, double currentCost, double& minCost, vector<vector<double>>& bestPartition) {
    // Базовый случай: если достигли конца массива и создали K кластеров
    if (index == arr.size() && сurrentPartition.size() == k) {
        // Проверяем, является ли текущая стоимость лучше минимальной найденной
        if (currentCost < minCost) {
            minCost = currentCost;
            bestPartition = сurrentPartition;
        }
        return;
    }

    // Если количество кластеров больше, чем осталось элементов, то разбиение невозможно
    if (сurrentPartition.size() > k || index >= arr.size()) {
        return;
    }

    // Пробуем добавить текущий элемент в существующий кластер
    for (int i = 0; i < сurrentPartition.size(); ++i) {
        // Добавляем текущий элемент в кластер
        сurrentPartition[i].push_back(arr[index]);
        // Вычисляем новую стоимость для кластера с добавленным элементом
        double addedCost = calculateClusterCost(сurrentPartition[i]);
        // Рекурсивно вызываем функцию для следующего элемента
        findOptimalPartition(arr, index + 1, k, сurrentPartition, currentCost + addedCost, minCost, bestPartition);
        // Удаляем добавленный элемент (возврат к предыдущему состоянию)
        сurrentPartition[i].pop_back();
    }

    // Пробуем создать новый кластер с текущим элементом
    if (сurrentPartition.size() < k) {
        // Создаем новый кластер с текущим элементом
        сurrentPartition.push_back({arr[index]});
        // Рекурсивно вызываем функцию для следующего элемента
        findOptimalPartition(arr, index + 1, k, сurrentPartition, currentCost, minCost, bestPartition);
        // Удаляем созданный кластер (возврат к предыдущему состоянию)
        сurrentPartition.pop_back();
    }
}

int main() {
    // Входной массив
    vector<double> arr = {1, 10, 9, 2, 3, 8, 4, 24, 62, 34, 64, 12, 11, 54, 15, 87, 45, 32, 89, 32};
    int k = 6;  // Количество кластеров

    // Проверка на допустимость значений (количество кластеров не должно превышать количество элементов)
    if (k > arr.size()) {
        cout << "Error: k < values" << endl;
        return 1;
    }

    // Поиск оптимального разбиения
    vector<vector<double>> сurrentPartition; // Текущий набор кластеров
    vector<vector<double>> bestPartition;    // Лучший найденный набор кластеров
    double minCost = numeric_limits<double>::max(); // Минимальная стоимость разбиения (инициализируется максимальным значением)

    // Запуск рекурсивной функции для поиска оптимального разбиения
    findOptimalPartition(arr, 0, k, сurrentPartition, 0, minCost, bestPartition);

     // Вывод результата
    for (int i = 0; i < bestPartition.size(); ++i) {
        cout << "[";
        // Вывод элементов каждого кластера
        for (int j = 0; j < bestPartition[i].size(); ++j) {
            cout << bestPartition[i][j];
            if (j != bestPartition[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != bestPartition.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}