#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm> 

using namespace std;

void heapify(int arr[], int n, int i) {
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
}

void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0);   
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void testHeapSort() {
    // Лучший случай (уже отсортированный массив)
    int bestCase[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int bestCaseSize = sizeof(bestCase) / sizeof(bestCase[0]);
    heapSort(bestCase, bestCaseSize);
    assert(is_sorted(bestCase, bestCase + bestCaseSize));

    // Средний случай (случайный порядок)
    int averageCase[] = {3, 1, 4, 9, 6, 7, 8, 2, 5, 10};
    int averageCaseSize = sizeof(averageCase) / sizeof(averageCase[0]);
    heapSort(averageCase, averageCaseSize);
    assert(is_sorted(averageCase, averageCase + averageCaseSize));

    // Худший случай (обратный порядок)
    int worstCase[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int worstCaseSize = sizeof(worstCase) / sizeof(worstCase[0]);
    heapSort(worstCase, worstCaseSize);
    assert(is_sorted(worstCase, worstCase + worstCaseSize));

    cout << "All tests passed!" << endl;
}

int main() {
    testHeapSort();
    return 0;
}