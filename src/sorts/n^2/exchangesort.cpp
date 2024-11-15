#include <vector>
#include "../../IComparator.hpp"

template <typename T>
void exchangesort(std::vector<T>& v, IComparable<T>& comparator) {
    for (size_t i = 0; i < v.size() - 1; i++) {
        for (size_t j = i + 1; j < v.size(); j++) {
            if (comparator.compareTo(v[i], v[j]) > 0) {
                std::swap(v[i], v[j]);
            }
        }
    }
}
