#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "sort_algs.cpp"

void testSortingAlgorithms() {
    {
        std::vector<int> original = {10, 7, -8, 9, -1, 5};
        std::vector<int> expected = original;
        std::sort(expected.begin(), expected.end());

        std::vector<int> combSorted = original;
        combSort(combSorted);
        assert(combSorted == expected);

        std::vector<int> quickSorted = original;
        quickSort(quickSorted, 0, quickSorted.size() - 1);
        assert(quickSorted == expected);

        std::vector<int> timSorted = original;
        timSort(timSorted);
        assert(timSorted == expected);
    }
    {
        std::vector<int> original = {};
        std::vector<int> expected = original;

        std::vector<int> combSorted = original;
        combSort(combSorted);
        assert(combSorted == expected);

        std::vector<int> quickSorted = original;
        quickSort(quickSorted, 0, quickSorted.size() - 1);
        assert(quickSorted == expected);

        std::vector<int> timSorted = original;
        timSort(timSorted);
        assert(timSorted == expected);
    }
    {
        std::vector<int> original = {42};
        std::vector<int> expected = original;

        std::vector<int> combSorted = original;
        combSort(combSorted);
        assert(combSorted == expected);

        std::vector<int> quickSorted = original;
        quickSort(quickSorted, 0, quickSorted.size() - 1);
        assert(quickSorted == expected);

        std::vector<int> timSorted = original;
        timSort(timSorted);
        assert(timSorted == expected);
    }
    {
        std::vector<int> original = {5, 3, 8, 3, 9, 5, 3};
        std::vector<int> expected = original;
        std::sort(expected.begin(), expected.end());

        std::vector<int> combSorted = original;
        combSort(combSorted);
        assert(combSorted == expected);

        std::vector<int> quickSorted = original;
        quickSort(quickSorted, 0, quickSorted.size() - 1);
        assert(quickSorted == expected);

        std::vector<int> timSorted = original;
        timSort(timSorted);
        assert(timSorted == expected);
    }
    {
        std::vector<int> original = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> expected = original;

        std::vector<int> combSorted = original;
        combSort(combSorted);
        assert(combSorted == expected);

        std::vector<int> quickSorted = original;
        quickSort(quickSorted, 0, quickSorted.size() - 1);
        assert(quickSorted == expected);

        std::vector<int> timSorted = original;
        timSort(timSorted);
        assert(timSorted == expected);
    }
}

int main() { testSortingAlgorithms(); }
