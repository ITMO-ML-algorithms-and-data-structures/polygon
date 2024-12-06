//сортировка подсчетом
#include <iostream>
#include <vector>
#include <algorithm> 

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    // Находим максимальное значение в массиве
    int maxVal = *std::max_element(arr.begin(), arr.end()); 
  
    // Создаем массив для подсчета количества появления каждого значения
    std::vector<int> count(maxVal + 1, 0);

    // Подсчитываем количество появлений каждого числа
    for (int num : arr) {
        count[num]++;
    }

    // Заполняем исходный массив отсортированными значениями
    int index = 0;
    for (int i = 0; i <= maxVal; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    // Тестовые случаи
    // Измерение времени выполнения
    std::vector<int> test1 = {4, 2, 2, 8, 3, 3, 1};
    clock_t start = clock();
    std::cout << "test 1:\n";
    countingSort(test1);
    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    std::vector<int> test2 = {1, 0, 2, 1, 3, 2, 0};
    start = clock();
    std::cout << "test 2:\n";
    countingSort(test2);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";
    
    std::vector<int> test3 = {5, 5, 5, 5};
    start = clock();
    std::cout << "test 3:\n";
    countingSort(test3);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    std::vector<int> test4 = {};
    start = clock();
    std::cout << "test 4:\n";
    countingSort(test4);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    std::vector<int> test5 = {2, 1, 3, 0, 5};
    start = clock();
    std::cout << "test 5:\n";
    countingSort(test5);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    return 0;
}