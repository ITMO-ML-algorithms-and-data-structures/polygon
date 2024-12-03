//Pancake sort (Реализует переворот массива для перемещения максимального элемента в конец)
#include <iostream>
#include <vector>
#include <algorithm> // Для reverse
using namespace std;

void flip(vector<int>& arr, int k) {
    // Переворачивает подмассив от начала до индекса k
    reverse(arr.begin(), arr.begin() + k + 1);
}

void pancakeSort(vector<int>& arr) {
    int n = arr.size();
    for (int size = n; size > 1; --size) {
        // Находим индекс максимального элемента в подмассиве
        int maxIdx = max_element(arr.begin(), arr.begin() + size) - arr.begin();

        // Если максимальный элемент уже на месте, пропускаем шаг
        if (maxIdx != size - 1) {
            flip(arr, maxIdx);    // Перемещаем максимальный элемент в начало
            flip(arr, size - 1); // Перемещаем его в конец текущего подмассива
        }
    }
}
