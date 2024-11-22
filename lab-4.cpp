#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept> 
#include <chrono> 

const int MAX_ITEMS = 25; // Максимальное количество предметов
const int MAX_WEIGHT = 100; // Максимальный вес предмета

std::pair<int, std::vector<int>> Schoolbag(const std::vector<std::pair<int, int>>& items, int weight_limit) {
    size_t n = items.size(); // Количество предметов

    // Проверка на количество предметов
    if (n > MAX_ITEMS) {
        throw std::invalid_argument("The number of items must not exceed 25.");
    }

    // Проверка ограничения по весу на предметы
    for (const auto& item : items) {
        if (item.first > MAX_WEIGHT) {
            throw std::invalid_argument("Weight must not exceed 100.");
        }
    }

    int max_value = 0; // Максимальная стоимость
    std::vector<int> best_combination; // Вектор для лучшей комбинации предметов

    // Перебираем все возможные подмножества (2^n)
    for (int i = 0; i < (1 << n); ++i) {
        int total_weight = 0; // Общий вес для текущей комбинации
        int total_value = 0; // Общая стоимость для текущей комбинации
        std::vector<int> total_combination; // Вектор для текущей комбинации

        // Проверка каждого предмета, включен он в набор или нет
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                total_weight += items[j].first;  // текущий вес
                total_value += items[j].second;   // текущая стоимость
                total_combination.push_back(items[j].first); // Добавляем вес предмета в комбинацию
            }
        }

        // Проверяем, укладывается ли общий вес в лимит
        if (total_weight <= weight_limit) {
            // Если текущая стоимость выше максимальной, обновляем значения
            if (total_value > max_value) {
                max_value = total_value; // Обновляем максимальную стоимость
                best_combination = total_combination; // Обновляем лучшую комбинацию
            }
        }
    }

    return { max_value, best_combination };
}

int main() {
    std::vector<std::pair<int, int>> items = { {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6},
                                                {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11},
                                                {11, 12}, {12, 13}, {13, 14}, {14, 15}, {15, 16},
                                                {16, 17}, {17, 18}, {18, 19}, {19, 20}, {20, 21},
                                                {21, 22}, {22, 23}, {23, 24}, {24, 25}, {25,26} };

    int weight_limit = 100;

    try {
        auto start_time = std::chrono::high_resolution_clock::now();

        std::pair<int, std::vector<int>> result = Schoolbag(items, weight_limit);
        int max_value = result.first;
        std::vector<int> best_combination = result.second;

        std::cout << "Max value: " << max_value << std::endl;
        std::cout << "Items: [";
        for (size_t i = 0; i < best_combination.size(); ++i) {
            std::cout << best_combination[i];
            if (i < best_combination.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;

        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time; 

        std::cout << "Time elapsed: " << duration.count() << " seconds." << std::endl;
        std::cout << "All done" << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}