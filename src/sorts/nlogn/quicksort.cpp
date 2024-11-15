#include <vector>
#include "../../IComparator.hpp"

template <typename T>
void quicksort(std::vector<T> &v, IComparable<T> &comparator) {
    _quicksort(v, 0, v.size() - 1, comparator);
}

template <typename T>
void _quicksort(std::vector<T> &v, size_t low, size_t high, IComparable<T> &comparator) {
    if (low < high) {
        size_t partition_idx = _partition(v, low, high, comparator);
        _quicksort(v, low, partition_idx - 1, comparator);
        _quicksort(v, partition_idx + 1, high, comparator);
    }
}

template <typename T>
size_t _partition(std::vector<T> &v, size_t low, size_t high, IComparable<T> &comparator) {
    T pivot = v[high];
    size_t i = low - 1;

    for (size_t j = low; j < high; ++j) {
        if (comparator.compareTo(v[j], pivot) < 0) {
            ++i;
            std::swap(v[i], v[j]);
        }
    }  std::swap(v[i+1], v[high]);
    return i + 1;
}