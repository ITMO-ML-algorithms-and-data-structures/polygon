#include <vector>
#include "../../IComparator.hpp"

template <typename T>
void shakersort(std::vector<T>& v, IComparable<T>& comparator) {
    size_t lprt = 0;
    size_t rptr = v.size() - 1;

    while (lprt < rptr) {
        for (size_t i = lprt; i < rptr; i++) {
            if (comparator.compareTo(v[i], v[i + 1]) > 0) {
                std::swap(v[i], v[i + 1]);
            }
        }
        rptr--;

        for (size_t i = rptr; i > lprt; i--) {
            if (comparator.compareTo(v[i - 1], v[i]) > 0) {
                std::swap(v[i - 1], v[i]);
            }
        }
        lprt++;
    }
}
