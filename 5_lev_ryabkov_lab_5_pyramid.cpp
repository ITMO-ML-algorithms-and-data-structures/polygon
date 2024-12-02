#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Функция для просеивания элемента вниз по куче
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }


    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }


    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(std::vector<int>& arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }


    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n = 1000;

    ifstream infile("/Users/levr/всякое/pythonProject/dataset_1.txt");
    vector<int> arr(n);

    for (int u = 0; u < n; ++u)
    {
        infile >> arr[u];
        arr[u] = arr[u] % n;
    }

    infile.close();
    heapSort(arr);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}