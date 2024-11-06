#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <chrono>

//Тесты
int test_passed = 0;
int test_failed = 0;

void assertEqual(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << "[PASSED]" << testName << "\n";
        test_passed++;
    }
    else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}

void report() {
    std::cout << "\nTests passed total: " << test_passed << "\n";
    std::cout << "\nTests not passed total: " << test_failed << "\n";
}


void test(std::vector<double>& arr) {
    assertEqual(arr.empty(), "Test empty array");
    assertEqual((arr.size() >= 9), "test input data by condition");
    assertEqual((arr.size() <= 25), "test input data by condition");
    for (double value : arr) {
        assertEqual(std::isfinite(value), "Test if all values are finite (not NaN or infinity)");
    }
    report();
}
//Функция считывающая датасет
std::vector<double> load_data() {//О(n) так первый вайл идет по одной строке ,в файле всего одна строка.
    std::vector<double> data;
    std::ifstream file("C:\\Users\\R1300-W-1-Stud\\Documents\\dataset.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string item;
        while (std::getline(ss, item, '\t')) {
            double item1 = std::stod(item);
            data.push_back(item1);
        }
    }
    return data;
}

double calculateMetric(const std::vector<double>& cluster) {//O("<n"*2) , тк для отдельного кластера
    double sum = 0;
    double mean = 0;
    for (double num : cluster) {
        mean += num;
    }
    mean /= cluster.size();

    for (double num : cluster) {
        sum += std::abs(num - mean);
    }

    return sum;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<double> arr = load_data();   // n*8 байт
    //{ 1,2,3,4,55,11,14,233,-6,11111,-0.00099999,0.999999999,12,34,109,1,1.11,1.9999999,1,2,6,67,21,3.09865734521}; //load_data();-Масссив по которому считал время
    int n = arr.size();
    std::unordered_map<double, std::vector<std::vector<double>>> metrics_splittingClasters;

    // читаем все возможные разбиения на 9 кластеров (выбираем координаты их концов) O(n**8)
    for (int q = 0; q <= n; ++q) {
        for (int w = q + 1; w <= n; ++w) {
            for (int e = w + 1; e <= n; ++e) {
                for (int r = e + 1; r <= n; ++r) {
                    for (int t = r + 1; t <= n; ++t) {
                        for (int y = t + 1; y <= n; ++y) {
                            for (int u = y + 1; u <= n; ++u) {
                                for (int i = u + 1; i < n; ++i) {
                                    // Координаты концов кластеров
                                    std::vector<int> сordinates_cluster_ends = { 0, q, w, e, r, t, y, u, i, n };//10*4байта

                                    std::vector<std::vector<double>> double_arr;
                                    double total_metric = 0;

                                    // Разбиение на кластеры по координатам концов
                                    for (int j = 0; j < сordinates_cluster_ends.size() - 1; ++j) {//O(n**8*"<n")<O(n**9)
                                        std::vector<double> cluster(arr.begin() + сordinates_cluster_ends[j], arr.begin() + сordinates_cluster_ends[j + 1]);//О(k)
                                        double s_Phi = calculateMetric(cluster);
                                        double_arr.push_back(cluster);
                                        total_metric += s_Phi;
                                    }

                                    // Сохраняем метрики для каждого разбиения
                                    metrics_splittingClasters[total_metric] = double_arr;// 8байт*O(n**9) + n*O(n**9)*8 байт
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Теперь находим минимальную метрику среди всех разбиений
    auto it = metrics_splittingClasters.begin();
    std::vector<std::vector<double>> optimal_clustering;
    double min_metric = std::numeric_limits<double>::infinity();

    while (it != metrics_splittingClasters.end()) {//О(n**9) тк асимптотика то понятное дело берем явно больше
        if (it->first < min_metric) {
            min_metric = it->first;
            optimal_clustering = it->second;  // Запоминаем кластеризацию с минимальной метрикой
        }
        ++it;
    }
    test(arr);
    // Выводим результат
    std::cout << "Optimal Clustering: \n";
    for (const auto& cluster : optimal_clustering) {//О(9) тк кластеров 9 по условию
        std::cout << '{';
        for (size_t i = 0; i < cluster.size(); ++i) {//О(n) 
            std::cout << cluster[i];
            if (i < cluster.size() - 1) std::cout << ", ";
        }
        std::cout << "} ";
    }
    std::cout << "\nMinimal Metric: " << min_metric << std::endl;

    //Выводим время выполнения программы
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "Time execution: " << diff.count() << " seconds";
}