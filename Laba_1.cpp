// задача вариант: 7 уровень: light
// сумма положительных чисел
#include <iostream>

int main() {
    int arr[11] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum;
    sum = 0;
    for (int num : arr) {
        if (num > 0) {
            sum += num;
        }
    }
    std::cout << "Сумма положительных чисел: " << sum;
    return 0;
}
