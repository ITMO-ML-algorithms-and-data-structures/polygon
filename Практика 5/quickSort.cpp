#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sortPart(vector<int>& arr, int left, int right) {
    int sort_el = arr[right];
    
    int i = left - 1;
    for (int j = left; j <= right; j++){
        if (arr[j] < sort_el) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    i++;
    swap(arr[i], arr[right]);
    return i;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int int_sort_el = sortPart(arr, left, right);
        
        quickSort(arr, left, int_sort_el - 1);
        quickSort(arr, int_sort_el + 1, right);
    }
}

int main() {

    return 0;
}