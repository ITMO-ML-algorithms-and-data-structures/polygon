#include <iostream>
#include <cassert>

void quickSort(int a[], int left, int right)
{
    if (left > right) return; // O(1)
    int p = a[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) // O(n)
    {
        while (a[i] < p) i++; // O(n)
        while (a[j] > p) j--; // O(n)
        if (i <= j) // O(1)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    quickSort(a, left, j);
    quickSort(a, i, right);
}

void test() {
    //Лучший случай
    int array[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    quickSort(array, 0, 9);
    int result[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < 10; i++)
    {
        assert(array[i] == result[i]);
    }
    // Средний случай
    int array_1[10]{ 3,4,7,5,1,9,66,45,0,23 };
    quickSort(array_1, 0, 9);
    int result_1[10]{ 0, 1, 3, 4, 5, 7, 9, 23, 45, 66 };
    for (int i = 0; i < 10; i++)
    {
        assert(array_1[i] == result_1[i]);
    }
    //Худший случай
    int array_2[10]{ 99, 88, 77, 66 , 55, 44 , 33 , 22 , 11, 0 };
    quickSort(array_2, 0, 9);
    int result_2[10]{ 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    for (int i = 0; i < 10; i++)
    {
        assert(array_2[i] == result_2[i]);
    }
}

int main()
{
    test();
    setlocale(LC_ALL, "Russian");
    int arr[7] = { 6,3,9,5,2,8,7 }; // 28 байт 
    int n = 7; // 4 байт
    std::cout << "Начальный массив" << "\n";
    for (int i = 0; i < n; i++) // O(n)
    {
        std::cout << arr[i];
    }
    std::cout << "\n";
    quickSort(arr, 0, n - 1);
    std::cout << "Отсортированный массив";
    std::cout << "\n";
    for (int i = 0; i < n; i++) // O(n)
    {
        std::cout << arr[i]; // O(1)
    }
    return 0;
}