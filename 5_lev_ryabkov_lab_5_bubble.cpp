#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void bubbleSort(vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n = 1000;

    ifstream infile("/Users/levr/всякое/pythonProject/dataset_1.txt");
    vector<int> arr(n);

    for (int u = 0; u < n; ++u)
    {
        infile >> arr[u];
        arr[u] = (arr[u] % 1000);
    }

    infile.close();
    bubbleSort(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << '\n';

    return 0;
}