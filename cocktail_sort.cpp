#include <iostream>
#include "cocktail_sort.h"

// Функция сортировки
void cocktail_sort(int arr[], int n) {
    int start = 0; // Точка начала сортировки 
    int end = n - 1; // Точка конца сотрировки 
    bool swap = true; // Переменная для определения, была ли перестановка

    while (swap) {
        swap = false; 

        // Делаем сортировку слева на правло 
        for (int i = start; i < end; i++){
            if (arr[i] > arr[i + 1]) { 
                std::swap(arr[i], arr[i+1]);
                swap = true;
            }
        }
        // Если ничего не поменялось местами, то сортировка прошла успешно
        if (!swap) {
            break;
        }

        swap = false;
        end--; // Сдвигаем правую границу

        // Делаем сортировку справа на лево
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i+1]);
                swap = true;
            }
        }

        // Если ничего не поменялось местами, то сортировка прошла успешно
        if (!swap) {
            break;
        }
        start++; // Сдвигаем левую границу
    }
}

