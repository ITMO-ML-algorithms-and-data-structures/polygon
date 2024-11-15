#include <vector>
#include "../../IComparator.hpp"

template <typename T>
void bubblesort(std::vector<T>& v, IComparable<T>& comparator) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v.size() - 1 - i; j++) {
            if (comparator.compareTo(v[j], v[j + 1]) > 0) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}
