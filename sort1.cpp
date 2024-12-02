#include <iostream>
#include <vector>

void cocktailShakerSort(std::vector<int>& arr) {
    int n = arr.size(); //4 байта
    bool swapped = true; //1 байт
    int start = 0; //4 байта
    int end = n - 1; //4 байта
    
    //Сложность: O(1); 13 байт

    while (swapped) {
        swapped = false;
        //Сложность: O(N) или O(N^2) в худшем случае; O(1)

        // Проходим слева направо
        for (int i = start; i < end; i++) { //4 байта
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        //Сложность:O(N) в худшем случае; 4 байта

        // Если не было перестановок, то массив отсортирован
        if (!swapped) break; //Сложность: O(1)

        swapped = false;

        // Идем справа налево
        end--;

        for (int i = end - 1; i >= start; i--) { //4 байта
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        //Сложность: O(N); 4 байта

        start++;
    }
}

int main() {
    // Пример: Массив для сортировки
    std::vector<int> arr = {5, 1, 4, 2, 8, 7, 6, 3}; // 4*N байт

    cocktailShakerSort(arr);

    // Вывод отсортированного массива
    for (int i = 0; i < arr.size(); i++) { //4 байта
        std::cout << arr[i] << " ";
    }

    return 0;
    //Сложность: O(N^2); 4*N + 4 байт
}

