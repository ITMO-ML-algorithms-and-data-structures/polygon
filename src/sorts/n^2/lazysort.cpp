#include <vector>
#include "../../IComparator.hpp"

template <typename T>
void lazysort(std::vector<T>& v, IComparable<T>& comparator) { // аля бабл сорт только с флагом для пропуска ненужных действий
    bool is_swapped;
    do {
        is_swapped = false;
        for (size_t i = 0; i < v.size() - 1; i++) {
            if (comparator.compareTo(v[i], v[i + 1]) > 0) {
                std::swap(v[i], v[i + 1]);
                is_swapped = true;
            }
        }
    } while (is_swapped); 
}
