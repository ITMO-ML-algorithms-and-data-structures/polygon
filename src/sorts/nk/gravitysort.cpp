#include <vector>
#include <map>
#include "../../IComparator.hpp"

template <typename T>
void gravitysort(std::vector<T>& v, IComparable<T>& comparator) {
    T minValue = v[0], maxValue = v[0];
    for (size_t i = 0; i < v.size(); i++) {

        if (comparator.compareTo(v[i], minValue) < 0) {
            minValue = v[i];
        }

        if (comparator.compareTo(v[i], maxValue) > 0) {
            maxValue = v[i];
        }

    }

    std::map<T, size_t> counts;
    for (size_t i = 0; i < size(v); i++) {
        counts[v[i]]++;
    }

    size_t idx = 0;
    for (const auto& [value, count] : counts) {
        for (int i = 0; i < count; ++i) {
            v[idx] = value;
            idx++;
        }
    }
}
