// Задание: Дан массив чисел, требуется найти пару чисел, произведение которых максимально

#include <iostream>
#include <vector>

int main() {
    short size_arr = 0;
    std::cout << "Количество элементво (размер > 1): ";
    while (size_arr <= 1){
        std::cin >> size_arr;
    }
    std::vector<float> arr(size_arr);
    for (int i = 0; i < size_arr; i++)
    {
        std::cout << "a[" << i << "] = ";
        std::cin >> arr[i];
    }

    short max1 = arr[0];
    short max2 = arr[1];
    if (size_arr > 2)
    {
        for (int i = 2; i < size_arr; i++)
        {
            if (max1 < arr[i]){
                max1 = arr[i];
                continue;
            }
            if (max2 < arr[i]) {
                max2 = arr[i];
                continue;
            }
        }
    }   
    std::cout << "Max mult = " << max1 * max2;


    return 0;
}
