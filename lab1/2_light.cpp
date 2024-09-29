#include <iostream>

int findIndexN(int arr[], int size, int n)
{
    int result = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
        {
            result = i;
            break;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 3, 8, 100, -20, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n;
    std::cout << "Введите искомый элемент массива" << std::endl;
    std::cin >> n;
    int index = findIndexN(arr, size, n);
    if (index < 0)
    {
        std::cout << "Ошибка: искомый элемент отсутствует в данном массиве" << std::endl;
        return 1;
    }
    std::cout << index;
    return 0;
}