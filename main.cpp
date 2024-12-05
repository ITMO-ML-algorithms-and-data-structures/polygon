#include <iostream>

int main() {
    int arr[] = {185, -1, -74, -200, -100, 14, 5, 8, -3, -6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            count++;
        }
    }
    std::cout << "В массиве найдено следующее количество положительных чисел: " << count << std::endl;
    return 0;
}
