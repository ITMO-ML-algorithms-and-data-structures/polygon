#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr, int k) {
    //Создаем массив для подсчета (счётчики)
    std::vector<int> count(k + 1, 0); // Для чисел от 0 до k
    //Сложность:O(k); 4*k + 4 байта

    //Подсчитываем количество вхождений каждого числа
    for (int num : arr) {
        count[num]++;
    }
    //Сложность:O(N)

    //Заполняем отсортированный массив
    int index = 0;
    for (int i = 0; i <= k; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
    //Сложность: O(N+k)
}

int main() {
    //Массив для сортировки
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1, 5, 7, 6};
    //Сложность: O(N); 4*N байт
    int k = 8; // Максимальное значение в массиве (можно настроить в зависимости от задачи)
    //4 байта

    countingSort(arr, k); //Сложность: O(N+k); 4*N + 12 байт

    //Вывод отсортированного массива
    for (int num : arr) { //4 байта
        std::cout << num << " ";
    }
    //Сложность: O(N)
    std::cout << std::endl;

    return 0;
    //Общая сложность: O(N+k); 4*N + 4*(k+1) + 12 байт
}

