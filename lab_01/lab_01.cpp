// lab_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int find_index(int arr[], int size, int n)
{

    for (int i = 0; i < size; i++) 
        if (arr[i] == n) 
            return i;     
               
    
    return -1;
}

int main()
{
    int arr[]{ 3,141,592,6,33,58, 77 };
    int N;
    std::cout << "Input N: ";
    std::cin >> N;
    int size = sizeof(arr) / sizeof (arr[0]);
    int index = find_index(arr, size, N);

    std::cout << "index = " << index;
    return 0;

}

