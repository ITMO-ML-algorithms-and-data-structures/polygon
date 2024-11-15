#include <vector>
#include <cmath>
#include "../../IComparator.hpp"

template <typename T>
void radixsort(std::vector<T>& v, IComparable<T>& comparator) {
    std::vector<T> output(v.size());
    
    T maxEl = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (comparator.compareTo(v[i], maxEl) > 0) {
            maxEl = v[i];
        }
    }

    size_t maxDigit = 0;
    T tmp = maxEl;
    while (tmp > 0) {
        maxDigit++; tmp /= 10;
    }
    
    for (size_t digit = 0; digit < maxDigit; digit++) {
        std::vector<uint8_t> count(10, 0);

        for (size_t i = 0; i < v.size(); i++) {
            size_t digitVal = (v[i] / static_cast<size_t>(std::pow(10, digit))) % 10;
            count[digitVal]++;
        }

        for (size_t i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = v.size() - 1; i >= 0; --i) {
            size_t digitVal = (v[i] / static_cast<size_t>(std::pow(10, digit))) % 10;
            output[count[digitVal] - 1] = v[i];
            count[digitVal]--;
        }

        v = output;
    }
}