#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;

// функция для вычисления метрики по формуле из ТЗ
double metricCounter(const vector<double>& arr, int start, int end) {
    double sum = 0;
    for (int i = start; i <= end; i++) {
        sum += arr[i];
    }
    double mean = sum / (end - start + 1); // вычисляем среднее значение кластера
    double metric = 0;
    for (int i = start; i <= end; i++) {
        metric += abs(arr[i] - mean); // считаем метрику по формуле из ТЗ
    }
    return metric;
}

// основная функция, ищет оптимальное разбиение на кластеры для минимизации метрики
vector<vector<double>> findClusters(vector<double>& arr, int K) {
    // засекаем время, надо для отчета
    clock_t tStart = clock();

    // O(N*log(N))
    sort(arr.begin(), arr.end()); // сортируем, тогда для решения задачи нужно будет в отсортированном массиве только расставить границы кластеров, т.к. кластеры в таком случае точно не пересекутся
    
    int length = arr.size();
    // тут идея из ДП: создаем матрицу размера К*длина_входного_вектора, в которой будем хранить значения метрик
    // аналогично создаем матрицу dp_memory_split, в которой будем хранить индексы разделителей, при которых достигается минимальное значение метрики
    // вторая матрица нужна только для вывода оптимальных кластеров, если б надо было выводить только лучшую метрику, можно было бы без этой матрицы обойтись
    vector<vector<double>> dp_memory_metric(length + 1, vector<double>(K + 1, numeric_limits<double>::max())); // изначально все значения приравниваем к максимально возможным
    vector<vector<int>> dp_memory_split(length + 1, vector<int>(K + 1, -1)); 

    dp_memory_metric[0][0] = 0; // метрика для одного кластера только с одним элементом равна 0 (следует из формулы метрики)

    // O(K*(N^3))
    for (int k = 1; k <= K; k++) { // пробегаемся по каждому разделителю 
        for (int i = 1; i <= length; i++) { // пробегаемся по каждому элементу
            for (int j = 0; j < i; j++) { // пробегаемся по всем подмассивам от начала массива до элемента с индексом i
                double current_metric = metricCounter(arr, j, i - 1); // считаем метрику (ТОЛЬКО в одном этом подмассиве)
                if (dp_memory_metric[j][k - 1] + current_metric < dp_memory_metric[i][k]) { // кладем в матрицу с метриками минимальную метрику на соответствующую позицию и запоминаем лучшее разбиение
                    dp_memory_metric[i][k] = dp_memory_metric[j][k - 1] + current_metric;
                    dp_memory_split[i][k] = j;
                }
            }
        }
    }

    // восстановливаем кластеры
    vector<vector<double>> clusters(K); // тут создаем массив массивов (не матрицу), каждой строке соответсвует подмассив из оптимального разбиения
    int idx = length;

    // O(K*N)
    for (int k = K; k > 0; k--) {
        int j = dp_memory_split[idx][k];
        for (int i = j; i < idx; i++) {
            clusters[k - 1].push_back(arr[i]); // заполняем этот массив подмассивами
        }
        idx = j;
    }

    // выводим кластеры
    // O(K*N)
    for (int k = 0; k < K; k++) {
        cout << "Cluster " << k + 1 << ": ";
        for (auto num : clusters[k]) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "Time taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << " sec" << endl;

    return clusters;
}

void test_metricCounter() {
    vector<double> input_arr_1 = { 1, 3, -2, 5, 8, 10 };
    int input_start_1 = 1;
    int input_end_1 = 4;
    double output_1 = metricCounter(input_arr_1, input_start_1, input_end_1);
    double excepted_1 = 0.5 + 5.5 + 1.5 + 4.5; // mean = 3.5
    assert(output_1 == excepted_1);
    cout << "metricCounter Test 1 - success" << endl;

    vector<double> input_arr_2 = { 52, 52, 52, 52, 52, 52, 52, 52 };
    int input_start_2 = 3;
    int input_end_2 = 6;
    double output_2 = metricCounter(input_arr_2, input_start_2, input_end_2);
    double excepted_2 = 0; // крайний случай, когда все элементы равны между собой
    assert(output_2 == excepted_2);
    cout << "metricCounter Test 2 - success" << endl;

    vector<double> input_arr_3 = { 1, 3.25, 2.5, -8.4, -10.6, 7, -6.25, 5 }; // случай, когда mean = 0
    int input_start_3 = 1;
    int input_end_3 = 6;
    double output_3 = metricCounter(input_arr_3, input_start_3, input_end_3);
    double excepted_3 = 3.25 + 2.5 + 8.4 + 10.6 + 7 + 6.25;
    assert(output_3 == excepted_3);
    cout << "metricCounter Test 3 - success" << endl;
}

void test_findClusters() {
    vector<double> input_arr_1 = { 1, 2, 3, 4, 5, 6 };
    int input_k_1 = 2;
    vector<vector<double>> output_1 = findClusters(input_arr_1, input_k_1);
    vector<vector<double>> excepted_1 = { {1, 2, 3}, {4, 5, 6} };
    assert(output_1 == excepted_1);
    cout << "findClusters Test 1 - success" << endl;
    
    vector<double> input_arr_2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    int input_k_2 = 10;
    vector<vector<double>> output_2 = findClusters(input_arr_2, input_k_2);
    vector<vector<double>> excepted_2 = { {1}, {2}, {3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13}, {14, 15, 16}, {17, 18, 19}, {20, 21, 22}, {23, 24, 25} };
    assert(output_2 == excepted_2);
    cout << "findClusters Test 2 - success" << endl;
    
    vector<double> input_arr_3 = { -10.5, -90, 4, 0.123, -3, 100, 90, 95, -99.999, -13, -0.31, 0 };
    int input_k_3 = 6;
    vector<vector<double>> output_3 = findClusters(input_arr_3, input_k_3);
    vector<vector<double>> excepted_3 = { {-99.999}, {-90}, {-13, -10.5}, {-3, -0.31, 0, 0.123, 4}, {90}, {95, 100} };
    assert(output_3 == excepted_3);
    cout << "findClusters Test 3 - success" << endl;
    
    vector<double> input_arr_4 = { 1, 10, 9, 2, 3, 8 };
    int input_k_4 = 2;
    vector<vector<double>> output_4 = findClusters(input_arr_4, input_k_4);
    vector<vector<double>> excepted_4 = { {1, 2, 3}, {8, 9, 10} };
    assert(output_4 == excepted_4);
    cout << "findClusters Test 4 - success" << endl;
}

int main() {
    test_metricCounter();
    test_findClusters();

    int K;
    cout << "Enter the number of clusters (K): ";
    cin >> K;

    cout << "Enter the number of elements in the array (>=K): ";
    int length;
    cin >> length;

    vector<double> arr(length);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    findClusters(arr, K);

    return 0;
}