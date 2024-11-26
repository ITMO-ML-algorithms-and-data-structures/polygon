#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

int heapify(vector<int>& arr, int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
    return 1;
}
  

int heap_sort(vector<int>& arr, int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
      
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
    return 1;
}

int count1() {
    ifstream fin("data.txt");
    ofstream fout("heap_time.txt");

    for (int n = 1000; n <= 1000000; n += 1000) {

        vector<int> arr(n, 0);

        for (int i = 0; i < n; i++ ) {
            fin >> arr[i];
        }
    
        clock_t start = clock();
        heap_sort(arr, n);
        clock_t end = clock();

        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        fout << n << " " << seconds << "\n";
    }
    fin.close();
    fout.close();
    cout << 1;
    return 0;
}

int count2() {
  ifstream fin("data.txt");
    ofstream fout("heap_1e4.txt");
    int j;
    int n = 10000;
    vector<int> vec(1000000,0);

    for (int i = 0; i < 1000000; i++) {
            fin >> vec[i];
        }

    for (int k = 0; k < 1000000; k += 10000) {

        vector<int> arr(n, 0);

        for (int i = k; i < n + k; i++) {
            fin >> arr[i];
        }


        clock_t start = clock();
        heap_sort(arr, n);
        clock_t end = clock();

        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        fout << seconds << "\n";
    }
    fin.close();
    fout.close();
    cout << 1;
    return 0;
}
  

int main() {
  count2();
      
}