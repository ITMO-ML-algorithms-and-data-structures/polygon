#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <vector>
#include <algorithm> // For std::shuffle
#include <chrono>
#include <thread>

std::vector<int> get_array_sample(int* array_to_sample, int array_size, int sample_size) {
    // Сэмплирование массива
    std::vector<int> sample(sample_size); // O(K) для выделения памяти
    std::vector<int> available_index(array_size); // О(N) для выделения памяти

    for (int i = 0; i < array_size; i ++) {
        available_index[i] = i; // О(1) * N - присваивание по индексу
    }

    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); // O(1) - взятие текущего времени
    std::srand(static_cast<unsigned>(seed)); // О(1) - передача seed в генератор
    std::random_shuffle(available_index.begin(), available_index.end()); // О(N) - перемещивание значений в векторе

    for (int i = 0; i < sample_size; i ++) {
        int random_index = i; // О(1) * K - присваивание
        sample[i] = array_to_sample[available_index[random_index]]; // (О(1) + O(1) + O(1)) * K - два взятия по индексу и одно присваивание
    }

    // Сложность алгоритма составляет:
    // О(N) в любом случае

    return sample;
}


void test() {
    int arr1[10000];

    for(int i = 0; i < 10000; i ++) {
        arr1[i] = i;
    }

    for(int k = 1; k <= 10; k ++) {
        std::vector<int> res_sample = get_array_sample(arr1, 10000, k);


        for(auto elem : res_sample) {
            std::cout << elem << " ";
        }

        std::cout << std::endl;
    }

}


int main() {
    test();

    return 0;
}