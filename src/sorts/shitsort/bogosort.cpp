#include <vector>
#include "../../IComparator.hpp"

#ifndef XORSHIFT
#define XORSHIFT
uint32_t RAND_SEED = 234233432;

uint32_t xorshift32() // src:wiki
{
	RAND_SEED ^= RAND_SEED << 13;
	RAND_SEED ^= RAND_SEED >> 17;
	RAND_SEED ^= RAND_SEED << 5;
	return RAND_SEED;
}

#define RAND() xorshift32()
#endif

// xdd
template <typename T>
void bogosort(std::vector<T>& v, IComparable<T>& comparator) {
    while (true) {
        bool is_sorted = true;
        for (size_t i = 1; i < v.size(); i++) {
            if (comparator.compareTo(v[i - 1], v[i]) <= 0) {
                is_sorted = false;
                break;
            }
        }
        if (is_sorted) {
            return;
        }

        for (size_t i = 0; i < v.size(); i++) {
            size_t j = RAND() % v.size();
            std::swap(v[i], v[j]);
        }
    }
}