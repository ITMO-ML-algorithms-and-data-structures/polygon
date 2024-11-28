#include <vector>
#include "algorithms.h"
using namespace std;

// Проверка, что массив отсортирован
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

int main() {
    combSortTests();
    treeSortTests();
    iterativePermutationSortTests();
}
