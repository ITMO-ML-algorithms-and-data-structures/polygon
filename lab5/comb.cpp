#include "comb_sort.h"
#include <vector>

std::vector<int> combSort(std::vector<int> arr) {
    int n = arr.size();
    int step = n;
    bool sorted = false;
    const double shrinkFactor = 1.3;

    while (step > 1 or !sorted) {
        step = static_cast<int>(step / shrinkFactor);
        if (step < 1) step = 1;

        sorted = true;
        for (int i = 0; i + step < n; ++i) {
            if (arr[i] > arr[i + step]) {
                std::swap(arr[i], arr[i + step]);
                sorted = false;
            }
        }
    }
    return arr;
}



