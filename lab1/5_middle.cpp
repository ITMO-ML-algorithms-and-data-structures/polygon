#include <iostream>

int findMax(int arr[], int size)
{
    int maximum = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }
    return maximum;
}
int main()
{
    int arr[] = {20, 4, 10, 0, -1};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << findMax(arr, size);
    return 0;
}