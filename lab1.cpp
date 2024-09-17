#include <iostream>

//Найти сумму всех чисел массива, которые кратны 3 (Hard -)

int arr[]{1, 2, 3, 6, 12, 69, 5};

int main() {
    int sum_3;
    std::cout << sum_3 << std::endl;
    for (int i = 0; i < std::size(arr); i++) {
        if (arr[i] % 3 == 0) {
            sum_3 += arr[i];
        }
    }
    std::cout <<"Sum of numbers that are multiples of 3: " << sum_3;
}