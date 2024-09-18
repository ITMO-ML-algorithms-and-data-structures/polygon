// Найти сумму всех чётных чисел в массиве

#include <iostream>
#include <vector>

int main() {
    std::vector<int> spis = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    for (int i = 0; i < std::size(spis); ++i)  {
        if (spis[i] % 2 == 0) {
            sum += spis[i];
        }
    }
    std::cout << sum;
}
