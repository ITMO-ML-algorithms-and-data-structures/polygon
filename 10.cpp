#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

class Sampler {
private:
    size_t memory_usage = 0;

    void update_memory_usage(const std::vector<int>& arr, const std::unordered_set<int>& selected_set) {
        memory_usage = 0;
        memory_usage += arr.capacity() * sizeof(int);
        memory_usage += selected_set.bucket_count() * sizeof(void*);
        for ([[maybe_unused]] const int value : selected_set) {
            memory_usage += sizeof(int);
        }
    }

public:
    std::vector<int> sample(const std::vector<int>& arr, int K) {
        std::vector<int> result;
        std::unordered_set<int> selected_set;
        int n = arr.size();

        if (K > static_cast<int>(n)) {
            throw std::invalid_argument("K cannot be larger than the array size.");
        }

        // Инициализируем генератор случайных чисел
        std::srand(static_cast<unsigned>(std::time(nullptr)));

        // Сэмплируем элементы, пока не наберём K уникальных значений
        while ( static_cast<int>(result.size()) < K) {
            int index = std::rand() % n;
            int value = arr[index];
            if (selected_set.find(value) == selected_set.end()) {
                selected_set.insert(value);
                result.push_back(value);
            }
        }

        // Обновляем подсчёт используемой памяти
        update_memory_usage(arr, selected_set);
        
        return result;
    }

    [[nodiscard]]
    size_t get_memory_usage() const {
        return memory_usage;
    }
};

// // Тестовая функция main
// int main() {
//     std::vector<int> arr = {1, 100, 10, 2};
//     int K = 3;

//     Sampler sampler;
//     try {
//         std::vector<int> result = sampler.sample(arr, K);
        
//         std::cout << "Sampled array: ";
//         for (int value : result) {
//             std::cout << value << " ";
//         }
//         std::cout << std::endl;

//         std::cout << "Memory usage: " << sampler.get_memory_usage() << " bytes" << std::endl;
//         // 68 bytes
//     } catch (const std::invalid_argument& e) {
//         std::cerr << e.what() << std::endl;
//     }

//     return 0;
// }
