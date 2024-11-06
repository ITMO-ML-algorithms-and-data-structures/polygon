

  #include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <iomanip>
#include <cassert>

using namespace std;

// Функция для расчета суммы отклонений от среднего значения в кластере
double Count_Rast(const vector<double>& cluster) {
    if (cluster.empty()) return 0;
    double mean = 0;

    for (double val : cluster) { // Сложность: O(N)
        mean += val;
    }
    mean /= cluster.size();
    double ves = 0;

    for (double val : cluster) { // Сложность: O(N)
        ves += abs(val - mean);
    }
    return ves; // Память: O(1)
}

// Поиск лучшего разбиения
void Itog_claster(const vector<double>& arr, int index, int k, vector<vector<double>>& now_set, double current_rast, double& min_rast, vector<vector<double>>& best_set) {
    //Если достигли конца массива и создали K кластеров
    if (index == arr.size() && now_set.size() == k) {
        if (current_rast < min_rast) {
            min_rast = current_rast;
            best_set = now_set;
        }
        return;
    }

    // Если количество кластеров превышает K или индекс выходит за размер массива
    if (now_set.size() > k || index >= arr.size()) return; // O(1)

    // Пробуем добавить текущий элемент в существующий кластер
    for (int i = 0; i < now_set.size(); i++) { // Сложность: O(K)
        now_set[i].push_back(arr[index]);
        double add_rast = Count_Rast(now_set[i]); // Сложность: O(N)

        Itog_claster(arr, index + 1, k, now_set, current_rast + add_rast, min_rast, best_set); // Сложность: O(2^N)
        now_set[i].pop_back();
    }

    // Пробуем создать новый кластер с текущим элементом
    if (now_set.size() < k) {
        now_set.push_back({ arr[index] });
        Itog_claster(arr, index + 1, k, now_set, current_rast, min_rast, best_set);
        now_set.pop_back();
    }
}

// Функция основного разбиения
vector<vector<double>> make_cluster(const vector<double>& arr, int k) {
    vector<vector<double>> best_set;
    vector<vector<double>> now_set;
    double min_rast = 1e20;

    Itog_claster(arr, 0, k, now_set, 0, min_rast, best_set);
    return best_set;
}

// Cложность: O(2^N)

// Функция вывода вектора
void print_vector(const vector<double>& vec) {
    cout << "[";
    for (size_t j = 0; j < vec.size(); j++) {
        cout << fixed << setprecision(1) << vec[j];
        if (j < vec.size() - 1) cout << " , ";
    }
    cout << "] ";
}

// Функция тестирования кластеризации
void test() {
    {
        std::vector<double> array1 = { 1.0, 2.0, 3.0, 7.0, 3.2, 4.1 };
        auto start = chrono::high_resolution_clock::now();
        std::vector<std::vector<double>> result1 = make_cluster(array1, 6);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        assert(result1.size() == 6);
        for (int i = 0; i < 6; ++i) {
            assert(result1[i].size() == 1); // Каждый кластер должен содержать ровно один элемент
        }
        std::cout << "Тест 1.\nКластеры: ";
        for (const auto& cluster : result1) {
            print_vector(cluster);
        }
        std::cout << "\n";
        std::cout << "Время: " << duration.count() / 1e6 << " секунд\n";
    }

    {
        std::vector<double> array2 = { 10.0, 20.0, 30.0, 40.0, 50.0, 90.5, 12.0, 32.9, 123.0, 35.8, 92.3,91.2 };
        auto start = chrono::high_resolution_clock::now();
        std::vector<std::vector<double>> result2 = make_cluster(array2, 6);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        assert(result2.size() == 6);
        std::cout << "Тест 2.\nКластеры: ";
        for (const auto& cluster : result2) {
            print_vector(cluster);
        }
        std::cout << "\n";
        std::cout << "Время: " << duration.count() / 1e6 << " секунд\n";
        }  {
        std::vector<double> array3 = { 1.0, 2.5, 3.5, 8.0, 20.0, 25.0, 30.0,1.0,-1.9, 12.3, 1.7 };
        auto start = chrono::high_resolution_clock::now();
        std::vector<std::vector<double>> result3 = make_cluster(array3, 6);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        assert(result3.size() == 6);
        for (const auto& cluster : result3) {
            assert(!cluster.empty()); // Каждый кластер должен иметь хотя бы один элемент
        }
        std::cout << "Тест 3. \nКластеры: ";
        for (const auto& cluster : result3) {
            print_vector(cluster);
        }
        std::cout << "\n";
        std::cout << "Время: " << duration.count() / 1e6 << " секунд\n";
    }

    {
        std::vector<double> array4 = { -1.5, 0.0, 1.7,0.6,0.9, 8.0, -1.0, 4.0, 5.0, 7.0, 99.0,-12.0 };
        auto start = chrono::high_resolution_clock::now();
        std::vector<std::vector<double>> result4 = make_cluster(array4, 6);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        assert(result4.size() == 6);
        std::cout << "Тест 4.\nКластеры: ";
        for (const auto& cluster : result4) {
            print_vector(cluster);
        }
        std::cout << "\n";
        std::cout << "Время: " << duration.count() / 1e6 << " секунд\n";
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    test();
}
