#include <vector>
#include "../../IComparator.hpp"

template <typename T>
void stalinsort(std::vector<T>& v, IComparable<T>& comparator) {
    size_t current_pos = 0;

    for (size_t i = 1; i < v.size(); i++) {
        if (comparator.compareTo(v[current_pos], v[i]) <= 0) {
            v[++current_pos] = v[i];
        }
    }

    v.resize(current_pos + 1);
}
