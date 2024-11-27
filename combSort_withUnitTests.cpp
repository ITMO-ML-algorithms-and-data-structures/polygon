#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


std::vector<int> combSort(std::vector<int>& arr) {
    int n = arr.size();
    int gap = n;
    const double factor = 1.247;
    bool swaped = true;

    while (gap > 1 || swaped) {
        gap = int (gap / factor);
        if (gap < 1) {
            gap = 1;
        }

        swaped = false;

        for (int i = 0; i + gap < n; ++i) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
                swaped = true;
            }
        }
    }

    return arr;
}


bool areEqual(const std::vector<int>& a, const std::vector<int>& b) {
    return a == b;
}


void testCombSort() {
    // Лучший случай (уже отсортированный массив)
    std::vector<int> bestCase = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> sortedBestCase = bestCase;
    assert(areEqual(combSort(bestCase), sortedBestCase));

    // Средний случай (случайный порядок)
    std::vector<int> averageCase = {3, 1, 4, 9, 6, 7, 8, 2, 5, 10};
    std::vector<int> sortedAverageCase = averageCase;
    std::sort(sortedAverageCase.begin(), sortedAverageCase.end());
    assert(areEqual(combSort(averageCase), sortedAverageCase));

    // Худший случай (обратный порядок)
    std::vector<int> worstCase = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> sortedWorstCase = worstCase;
    std::sort(sortedWorstCase.begin(), sortedWorstCase.end());
    assert(areEqual(combSort(worstCase), sortedWorstCase));

    std::cout << "All tests passed for combSort!" << std::endl;
}

int main() {
    testCombSort();
    return 0;
}
