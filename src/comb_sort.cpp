#include <vector>
#include <algorithm>

void comb_sort(int* arr, int n) {
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap > 1) ? (gap * 10) / 13 : 1;
        swapped = false;
        for (int i = 0; i < n - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}
