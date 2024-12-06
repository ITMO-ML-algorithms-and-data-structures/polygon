//гномья сортировка
#include <iostream>
#include <vector>
#include <ctime> 

void gnomeSort(std::vector<int>& arr) {
    int n = arr.size();
    int i = 0;

    while (i < n) {
        // Если первый элемент больше второго, меняем их местами и идем влево
        if (i > 0 && arr[i] < arr[i - 1]) {
            std::swap(arr[i], arr[i - 1]);
            i--; // Переход к предыдущему элементу
        } else {
            i++; // Переход к следующему элементу
        }
    }
}

int main() {
    // Тестовые случаи
    // Измерение времени выполнения
    std::vector<int> test1 = {4, 2, 2, 8, 3, 3, 1};
    clock_t start = clock();
    std::cout << "test 1:\n";
    gnomeSort(test1);
    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    std::vector<int> test2 = {10, 7, 12, 1, 2};
    start = clock();
    std::cout << "test 2:\n";
    gnomeSort(test2);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";
    
    std::vector<int> test3 = {5, 3, 6, 3, 2, 6, 1};
    start = clock();
    std::cout << "test 3:\n";
    gnomeSort(test3);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    std::vector<int> test4 = {};
    start = clock();
    std::cout << "test 4:\n";
    gnomeSort(test4);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    std::vector<int> test5 = {1, 1, 0, 0};
    start = clock();
    std::cout << "test 5:\n";
    gnomeSort(test5);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    return 0;
}
