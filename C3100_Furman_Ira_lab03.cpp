#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> fillMissingWithAverage(const std::vector<int>& arr) {               //задаем функцию для заполнения пропущенных значений (ноль) средним значением остальных элементов
    std::vector<int> result = arr;                                       //O(N)      //создаём копию входного вектора 
    int sum = 0, count = 0;                                             //O(1)       //создаем переменные для хранения суммы ненулевых эл-тов, для подсчета количества ненулевых эл-тов

    for (int i : arr) {                                                 //O(N)       //проходим по каждому элементу входного вектора
        if (i != 0) {                                                   //O(1)
            sum += i;
            count++;
        }
    }

    int average = count > 0 ? sum / count : 0;                          //O(1)       //вычисление среднего значения, если есть не нулевые элементы

    for (int i = 0; i < result.size(); i++) {                           //O(N)       //замена нулевых значений в результирующем векторе на среднее значение
        if (result[i] == 0) {                                           //O(1)
            result[i] = average;
        }
    }

    return result;                                                      //O(1) возврат результата
}

int main() {                        
    std::vector<std::vector<int>> testCases = {                         //O(1)       //вектор тестовых случаев с различными входными данными
        {1, 0, 10, 4},
        {0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0},
        {2, 2, 3, 0, 5, 0, 7}
    };

    for (const auto& testCase : testCases) {                                        //цикл для тестирования
        std::vector<int> result = fillMissingWithAverage(testCase);                 //O(N)
        
        std::cout << "Input: ";
        for (int i : testCase) {
            std::cout << i << " ";
        }

        std::cout << "Output: ";
        for (int i : result) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    //O(N)+O(N)=O(N) для каждого теста
    return 0;
}
//Cредняя сложность алгоритма составляет:
//O(N)- в худшем случае
//O(1)- в лучшем случае
//O(K)- в среднем случае, который равномерно распределен от 1 до N