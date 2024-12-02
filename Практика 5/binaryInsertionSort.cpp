#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binSearch(vector<int>& array, int item, int right) {
    int left = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == item)
            return mid + 1;
        else if (array[mid] < item)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

void binaryInsertionSort(vector<int>& array) {
    int size = array.size();
    for (int i = 1; i < size; i++) {
        int key = array[i];

        int swap_pos = binSearch(array, key, i - 1);

        for (int j = i - 1; j >= swap_pos; j--) {
            array[j + 1] = array[j];
        }

        array[swap_pos] = key;
    }
}

int main() {
    
    return 0;
}