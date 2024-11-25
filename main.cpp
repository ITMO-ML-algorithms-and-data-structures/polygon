#include <iostream>
#include <vector>
#include <cmath>     // Для использования abs (абсолютное значение)
#include <limits>    // Для использования numeric_limits
#include <tuple>     // Для использования tuple

using namespace std;

// Функция для вычисления среднего значения кластера
// Принимает вектор чисел и возвращает среднее значение
int average_val(const vector<int>& cluster) {
    int sum = 0;  // Накопление суммы элементов в кластере

    // Перебираем элементы вектора и прибавляем их
    for (int val: cluster){
        sum += val;  // Добавляем каждый элемент к общей сумме
    }

    // Если кластер пустой, возвращаем 0
    if (cluster.empty()){
        return 0;
    }
    else {
        // Возвращаем целое среднее
        return sum / cluster.size();
    }
}

// Функция для вычисления суммы расстояний всех элементов от среднего значения
// Расстояние - это сумма отклонений от среднего значения
int len_average(const vector<int>& cluster) {
    int mean = average_val(cluster); // Среднее значение для текущего кластера
    int sum = 0;  // Накопление суммы отклонений

    // Перебираем элементы и находим их отклонение от среднего
    for (int val: cluster){
        sum += abs(val - mean);  // Добавляем отклонение от среднего
    }
    return sum;  // Возвращаем сумму отклонений
}

// Разбиение массива на 3 кластера
// Метрика - это сумма отклонений от среднего в каждом из кластеров
tuple<vector<int>, vector<int>, vector<int>> klast(const vector<int>& arr) {
    int n = arr.size();  // Количество элементов массива
    int minMetric = numeric_limits<int>::max();  // Изначально ставим минимальную метрику на максимальное возможное значение
    tuple<vector<int>, vector<int>, vector<int>> bestClusters;  // Хранение лучших кластеров

    // Перебираем все возможные разбиения массива на 3 кластера
    // Используем 3 побитовые маски для 3 кластеров
    for (int mask1 = 1; mask1 < (1 << n) - 1; ++mask1) {
        for (int mask2 = mask1 + 1; mask2 < (1 << n); ++mask2) {
            if ((mask1 & mask2) == 0) {  // Убедимся, что кластеры не перекрываются
                vector<int> cluster1, cluster2, cluster3;  // 3 кластера для разбиения массива

                // Распределение элементов по кластерам с учетом двух масок
                for (int i = 0; i < n; ++i) {
                    if (mask1 & (1 << i)) {  // Если соответствующий бит в первой маске равен 1
                        cluster1.push_back(arr[i]);  // Добавляем в первый кластер
                    }
                    else if (mask2 & (1 << i)) {  // Если соответствующий бит во второй маске равен 1
                        cluster2.push_back(arr[i]);  // Добавляем во второй кластер
                    }
                    else {
                        cluster3.push_back(arr[i]);  // Все остальные элементы идут в третий кластер
                    }
                }

                // Вычисляем метрику (сумму расстояний до среднего) для всех трех кластеров
                int totalMetric = len_average(cluster1) + len_average(cluster2) + len_average(cluster3);

                // Если текущая метрика < минимальной, обновляем minMetric и bestClusters
                if (totalMetric < minMetric) {
                    minMetric = totalMetric;
                    bestClusters = make_tuple(cluster1, cluster2, cluster3);  // Сохраняем текущее разбиение как лучшее
                }
            }
        }
    }

    return bestClusters;  // Возвращаем лучшее разбиение
}

// Вывод кластеров
void prClusters(const tuple<vector<int>, vector<int>, vector<int>>& clusters) {
    // Выводим первый кластер
    cout << "[";
    for (int i = 0; i < get<0>(clusters).size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << get<0>(clusters)[i];  // Выводим элемент первого кластера
    }
    cout << "], [";

    // Выводим второй кластер
    for (int i = 0; i < get<1>(clusters).size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << get<1>(clusters)[i];  // Выводим элемент второго кластера
    }
    cout << "], [";

    // Выводим третий кластер
    for (int i = 0; i < get<2>(clusters).size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << get<2>(clusters)[i];  // Выводим элемент третьего кластера
    }
    cout << "]" << endl;
}

int main() {
    // Пример тестовых случаев для разбиения на три кластера
    vector<vector<int>> testCases = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
        {1, 10, 9, 2, 3, 8, 11, 15, 9, 99, 1, 4, 8, 8, 14, 88, 1488, 1405, 1404, 2202, 2337, 2330, 413, 424, 2201}
    };

    // Обрабатываем каждый тестовый случай
    for (const auto& testCase: testCases) {
        cout << "Input: ";
        for (int val: testCase){
            cout << val << " ";  // Печатаем каждый элемент массива
        }
        cout << endl;

        // Получаем результат разбиения массива на три кластера
        auto clusters = klast(testCase);

        cout << "Clusters: ";
        prClusters(clusters);  // Выводим кластеры
        cout << endl;
    }

    return 0;  // Завершаем выполнение программы
}
