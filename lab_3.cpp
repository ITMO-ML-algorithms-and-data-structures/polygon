//Подсчет значений в массиве

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

int main() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::vector<std::string> arr(size);
    std::cout << "Введите значения массива: "; //O(1)
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i]; //O(N) - считываем N значений
    }

    //Хэш-таблица для подсчета уникальных значений
    std::unordered_map<std::string, int> countMap;
    //используем строки в качестве ключей

    //Подсчет количества вхождений каждого значения
    for (const auto& value : arr) {
        countMap[value]++; //O(1) - среднее время доступа к хэш-таблице, O(N) для N значений
    }

    //Вектор для хранения результата
    std::vector<int> result(size); //O(N) - выделение памяти для вектора

    //Замена значений на их количество
    for (int i = 0; i < size; ++i) {
        result[i] = countMap[arr[i]]; //O(1) - среднее время доступа к хэш-таблице, O(N) для N значений
    }

    //Вывод результата
    std::cout << "Результат: [";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i]; //O(1) - вывод одного значения
        if (i < result.size() - 1) {
            std::cout << ", "; //O(1) - вывод запятой
        }
    }
    std::cout << "]"; //O(1)

    return 0;
}

/* Общая сложность алгоритма составляет O(N), 
так как все основные операции выполняются линейно 
по отношению к количеству элементов в массиве */
