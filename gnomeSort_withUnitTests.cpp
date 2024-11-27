#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

std::vector<int> gnomeSort(std::vector<int>& arr) {
    int i = 1;
    int size = arr.size();

    while (i < size) {
        if (i == 0 || arr[i - 1] <= arr[i]) {
            i++;
        } else {
            std::swap(arr[i - 1], arr[i]);
            i--;
        }
    }

    return arr;
}

bool areEqual(const std::vector<int>& a, const std::vector<int>& b) {
    return a == b;
}

void testGnomeSort() {
    // лучший случай
    std::vector<int> bestCase = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> sortedBestCase = bestCase; 
    assert(areEqual(gnomeSort(bestCase), sortedBestCase));

    // средний случай (случайный порядок)
    std::vector<int> averageCase = {3, 1, 4, 9, 6, 7, 8, 2, 5, 10};
    std::vector<int> sortedAverageCase = averageCase;
    std::sort(sortedAverageCase.begin(), sortedAverageCase.end()); 
    assert(areEqual(gnomeSort(averageCase), sortedAverageCase));

    // худший случай (обратный порядок)
    std::vector<int> worstCase = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> sortedWorstCase = worstCase;
    std::sort(sortedWorstCase.begin(), sortedWorstCase.end()); 
    assert(areEqual(gnomeSort(worstCase), sortedWorstCase));

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testGnomeSort();
    return 0;
}