#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime> 


std::vector<int> generateDataset(size_t size) {
    std::vector<int> dataset(size);

    // Устанавливаем случайное начальное значение для rand()
    std::srand(std::time(0));

    // Заполняем вектор случайными числами
    for (size_t i = 0; i < size; ++i) {
        dataset[i] = std::rand();  // Генерация случайного числа
    }

    return dataset;
}


void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

