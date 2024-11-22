#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("numbers.txt"); // O(1)

    long long sum = 0; // O(1) + O(1) выделение памяти и присвоение
    long long count = 0; // O(1) + O(1)

    std::string num_str; // O(1)
    while (std::getline(file, num_str, ',')) { // для гетлайна наихудший случай O(n), в среднем O(1) если длина значений +- фиксирована 
        int num = std::stoi(num_str); // O(1)
        if (num != -1) {
            sum += num; // O(1)
            count++; // O(1)
        }
        // Итого O(n) на цикл
    }

    file.close(); // O(1)

    int avg = 0; // O(1)
    if (count > 0) {
        avg = sum / count; // O(1) + O(1)
        std::cout << "Среднее значение: " << avg << std::endl;
    } else {
        std::cout << "Нет чисел для вычисления среднего" << std::endl;
        return 1;
    }

    std::ifstream inputFile("numbers.txt"); // O(1)
    std::ofstream outputFile("output.txt"); // O(1)

    bool first = true; // O(1) + O(1)
    while (std::getline(inputFile, num_str, ',')) {
        int num = std::stoi(num_str); // O(1)

        if (!first) {
            outputFile << ","; // O(1)
        }
        first = false; // O(1)

        if (num == -1) {
            outputFile << avg; // O(1)
        } else {
            outputFile << num; // O(1)
        }

        // Цикл выполняется n раз поэтому O(n)
    }

    inputFile.close(); // O(1)
    outputFile.close(); // O(1)

    /*
    За первое чтение файла и подсчет значений O(n) + O(1) за вычисление среднего + O(n) за вывода и замену нуллов на среднее 
    Итого O(N)
    */

    return 0;
}