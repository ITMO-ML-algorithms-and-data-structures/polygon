#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <numeric> 
#include <functional>
#include <chrono>
#include <iomanip>

class Clusterizer {
private:
    size_t memory_usage = 0;

    void update_memory_usage(const std::vector<int>& arr, const std::vector<std::vector<int>>& clusters) {
        memory_usage = 0;

        // Подсчёт памяти для массива arr
        memory_usage += arr.capacity() * sizeof(int);

        // Подсчёт памяти для кластеров
        for (const auto& cluster : clusters) {
            memory_usage += cluster.capacity() * sizeof(int);
        }
    }

    double calculateClusterCost(const std::vector<int>& cluster) {
        if (cluster.empty()) return std::numeric_limits<double>::max(); // Изменено для избежания пустых кластеров
        double mean = std::accumulate(cluster.begin(), cluster.end(), 0.0) / cluster.size();
        double cost = 0;
        for (int val : cluster) {
            cost += std::abs(val - mean);
        }
        return cost;
    }


public:
    std::vector<std::vector<int>> bruteForceClustering(const std::vector<int>& arr, int K) {
        if (static_cast<int>(arr.size()) < K) {
            throw std::invalid_argument("Количество элементов должно быть не меньше K");
        }

        int n = arr.size();
        double min_cost = std::numeric_limits<double>::max();
        std::vector<std::vector<int>> best_clusters;

        auto backtrack = [&](auto&& self, int start, int remaining_clusters, 
                           std::vector<std::vector<int>> current_clusters) -> void {
            // Проверяем, можем ли мы создать оставшиеся кластеры с минимум 1 элементом
            int remaining_elements = n - start;
            if (remaining_elements < remaining_clusters) {
                return;
            }

            if (remaining_clusters == 0) {
                if (start < n) return; // Остались необработанные элементы
                
                double total_cost = 0;
                for (const auto& cluster : current_clusters) {
                    if (cluster.empty()) return; // Пропускаем решения с пустыми кластерами
                    total_cost += calculateClusterCost(cluster);
                }
                
                if (total_cost < min_cost) {
                    min_cost = total_cost;
                    best_clusters = current_clusters;
                }
                return;
            }

            // Оставляем элементы для остальных кластеров
            int max_elements = n - remaining_clusters + 1 - start;
            
            for (int end = start; end < start + max_elements; ++end) {
                std::vector<int> new_cluster(arr.begin() + start, arr.begin() + end + 1);
                current_clusters.push_back(new_cluster);
                self(self, end + 1, remaining_clusters - 1, current_clusters);
                current_clusters.pop_back();
            }
        };

        backtrack(backtrack, 0, K, {});
        update_memory_usage(arr, best_clusters);
        return best_clusters;
    }

    [[nodiscard]]
    size_t get_memory_usage() const {
        return memory_usage;
    }

    static void performanceTest() {
        const std::vector<int> sizes = {10, 15, 20, 25, 30};
        const int K = 7; // Фиксированное количество кластеров для тестов
        
        std::cout << "Размер массива\tВремя (с)\tO(2^N) (теор.)\n";
        
        for (const int size : sizes) {
            // Генерируем тестовый массив
            std::vector<int> test_arr(size);
            std::iota(test_arr.begin(), test_arr.end(), 1); // Заполняем числами от 1 до size
            
            // Замеряем время выполнения
            auto start = std::chrono::high_resolution_clock::now();
            
            Clusterizer clusterizer;
            clusterizer.bruteForceClustering(test_arr, K);
            
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            
            // Теоретическое время O(2^N), нормализованное к первому измерению
            const double theoretical = 0.5 * std::pow(2, size - 5);
            
            std::cout << size << "\t\t" 
                     << std::fixed << std::setprecision(1) << duration.count() << "\t\t"
                     << theoretical << "\n";
        }
    }
};

// тестовая функция main для проверки времени работы
int main() {
    Clusterizer::performanceTest();
    return 0;
}

// // тестовая функция main
// int main() {
//     std::vector<int> arr = {1,2,3,4,5, 6, 10, 20, 30, 40, 50, 110, 230, 340, 450, 560, 670, 780, 890, 900};  // Тест с разными числами
//     int K = 7;  

//     Clusterizer clusterizer;
//     try {
//         std::vector<std::vector<int>> clusters = clusterizer.bruteForceClustering(arr, K);

//         std::cout << "Clusters:" << std::endl;
//         for (const auto& cluster : clusters) {
//             std::cout << "[ ";
//             for (int val : cluster) {
//                 std::cout << val << " ";
//             }
//             std::cout << "] ";
//         }
//         std::cout << std::endl;

//         std::cout << "Memory usage: " << clusterizer.get_memory_usage() << " bytes" << std::endl;
//         // 344 bytes
//     } catch (const std::exception& e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }

//     return 0;
// }