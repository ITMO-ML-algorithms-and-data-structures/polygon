#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <iomanip> // Для std::setprecision и std::fixed

using namespace std;

// Функция для вычисления расстояния между элементами кластера и средним значением кластера
double calculate_distance(const vector<double>& cluster)
{
    double mean = 0;  // Память: O(1)

    for (double x : cluster) // Сложность: O(M), где M — количество элементов в текущем кластере
    {
        mean += x;
    }

    mean /= cluster.size(); // Память: cluster.size() - O(1)

    double distance = 0; // Память: O(1)

    for (double x : cluster) // Сложность: O(M), где M — количество элементов в текущем кластере
    {
        distance += abs(x - mean); // Память: O(1)
    }

    distance = sqrt(distance * distance); // Память: O(1)
    return distance; // Память: O(1)
}

// Функция для кластеризации массива на k кластеров
vector<vector<double>> cluster_array(const vector<double>& arr, int k)
{
    int n = arr.size(); // Память: O(1) - получение размера массива
    double best_distance = 1e18; // Память: O(1) - инициализация переменной
    vector<vector<double>> best_clusters; // Память: O(1) - создание вектора для хранения лучших кластеров

    for (int mask = 0; mask < (1 << (n - 1)); ++mask) // Сложность: O(2^(n-1)) - перебираем все возможные маски разбиений массива
    {
        vector<vector<double>> clusters(1); // Память: O(1) - инициализация первого кластера
        int cluster_count = 1; // Память: O(1) - счетчик кластеров

        for (int i = 0; i < n; ++i) // Сложность: O(n) - проходим по всем элементам массива
        {
            clusters.back().push_back(arr[i]); // Память: O(1) - добавление элемента в текущий кластер

            if (i < n - 1 && (mask & (1 << i))) // Если установлен бит, создаем новый кластер
            {
                clusters.push_back({}); // Память: O(1) - создание нового пустого кластера
                ++cluster_count; // Память: O(1) - увеличение счетчика кластеров
            }
        }

        if (cluster_count == k) // Проверяем, соответствует ли количество кластеров k
        {
            double total_distance = 0; // Память: O(1)

            for (const auto& cluster : clusters) // Сложность: O(k) - проходим по всем кластерам
            {
                total_distance += calculate_distance(cluster); // Суммируем расстояния для всех кластеров
                // Сложность: Вызов calculate_distance сложность O(M), где M — количество элементов в кластере.
            }

            // Если текущее расстояние меньше лучшего, обновляем его
            if (total_distance < best_distance)
            {
                best_distance = total_distance; // O(1)
                best_clusters = clusters; // Память: O(n * k) - копирование всех кластеров в лучший результат
            }
        }
    }

    return best_clusters; // Возвращаем лучшие кластеры
}
//Итого:
// Сложность: O(2^(N)*N+k*N) = O(2^(N)*N) в общем случае
// Память: O(N*k)

int main()
{
    const int k = 5; // Фиксированное количество кластеров

    vector<vector<double>> test_cases =
    {
        {1.0, 2.0, 3.0, 4.0, 5.0},
           {0,0,0,0,0},
              {-1,-2,-3,1,1,1,1,1,1,1,1,1,1,-9,-10},
               {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
            {5,-3,-2,-4,-1},
        {6,5,10,9,1,2,8,7,3,4},
        {1.0, 2.0, 3.0, 4.0, 5.0, 10.0, 9.0, 7.0,
         8.0, 6.0, 13.0, 12.0, 11.0,
         14.0, 15.0,
         17.0, 16.0,
         18.0,
         19.0,
         20.0,
         25.0,
         24.0,
         23.0,
         22.0,
         21.0}
    };

    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        cout << "Test case " << i + 1 << ":\n";
        cout << "Input array: ";

        for (double x : test_cases[i])
        {
            cout << fixed << setprecision(1) << x << " "; // Выводим числа с точностью до одного знака после запятой
        }

        cout << "\nk = " << k << "\n";

auto start = chrono::high_resolution_clock::now(); // Начало отсчета времени
        auto result = cluster_array(test_cases[i], k);
        auto end = chrono::high_resolution_clock::now(); // Конец отсчета времени

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Result: ";

        for (const auto& cluster : result)
        {
            cout << "[";

            for (size_t j = 0; j < cluster.size(); ++j)
            {
                cout << fixed << setprecision(1) << cluster[j]; // Выводим элементы кластера с точностью до одного знака после запятой

                if (j < cluster.size() - 1)
                {
                    cout << " ";
                }
            }

            cout << "] ";
        }

        // Вывод времени выполнения в секундах с семью знаками после запятой
        cout << "\nExecution time: "
             << fixed << setprecision(7)
             << duration.count() / 1e6 << " seconds\n\n";
    }

    return 0;
}