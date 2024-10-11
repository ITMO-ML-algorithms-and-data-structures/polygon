#include <iostream>

int main()
{
    const int numbers = 5;
    int arr[numbers];
    std::cout << "input numbers of array: ";
    for (int i = 0; i < numbers; ++i) {
        std::cin >> arr[i];
    }

    int min = arr[0];

    for (int i = 1; i < numbers; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    std::cout << "min: " << min << std::endl;
}