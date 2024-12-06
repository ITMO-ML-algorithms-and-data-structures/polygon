#include <iostream>
#include <vector>
#include <chrono>

void cycleSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Перебор каждого элемента в массиве
    for (int start = 0; start < n - 1; ++start) {
        int item = arr[start];
        int pos = start;

        // поиск правильной позиции (индекса) элемента
        for (int i = start + 1; i < n; ++i) {
            if (arr[i] < item) {
                pos++;
            }
        }

        // если элемент уже на нужном месте то продолжаем
        if (pos == start) continue;

        // Пропуск дубликатов
        while (item == arr[pos]) {
            pos++;
        }

        // Ставим элемент на его нужную позиция
        std::swap(item, arr[pos]);

        // Завершение цикла для данного элемента
        while (pos != start) {
            pos = start;
            //находим правильное положение
            for (int i = start + 1; i < n; ++i) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            // пропускаем одинаковые элементы
            while (item == arr[pos]) {
                pos++;
            }
            std::swap(item, arr[pos]);
        }
    }
}

// тест и замер времени
int main() {
    std::vector<int> arr = {20, 40, 50, 10, 30, 550, 67,3000, 70000,43,76868676,89497878,579845873,84959845,4543,57948378,45037,376907,734673, 2, 1, 6, 7546455, 3365, 66, 8989405, 53089367, 396083908, 896093809, 3820683, 238082309};
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
 
    cycleSort(arr);

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Sorted array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}

