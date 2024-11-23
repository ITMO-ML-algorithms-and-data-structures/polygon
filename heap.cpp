#include <iostream>

using namespace std;
void heapify(int *arr, int size, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int maxx = i;
    if (l<size && arr[l]>arr[maxx]){
        maxx = l;
    }
    if (r<size && arr[r]>arr[maxx]){
        maxx = r;
    }
    if (maxx != i){
        swap(arr[i], arr[maxx]);
        heapify(arr, size, maxx);
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = size/2-1; i >= 0; i--){
        heapify(arr, size, i);
    }
    for (int i = size-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    for (int i = 0; i < size; i++){
      cout << arr[i] << " ";
    }
}