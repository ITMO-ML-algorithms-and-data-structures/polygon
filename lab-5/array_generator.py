#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>

int main() {
    int n = 10000;
    // Генерируем массив из натуральных чисел
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        numbers[i] = i + 1;  // Заполняем числами от 1 до n
    }

    for (int i = 11; i <= 50; i ++) {
        // Перемешиваем массив с использованием random_device и mt19937
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(numbers.begin(), numbers.end(), g);

        // Сохраняем массив в CSV файл
        std::string filename = std::to_string(n) + "_" + std::to_string(i) + ".csv";
        // std::cout << "Enter file name: ";
        // std::cin >> filename;

        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
            return 1;
        }

        // Записываем числа в CSV файл
        for (size_t i = 0; i < numbers.size(); ++i) {
            outFile << numbers[i];
            if (i < numbers.size() - 1) {
                outFile << ",";  // Добавляем запятую между числами
            }
        }

        outFile.close();  // Закрываем файл

        std::cout << "Array has been saved to " << filename << std::endl;
    }


    return 0;
}