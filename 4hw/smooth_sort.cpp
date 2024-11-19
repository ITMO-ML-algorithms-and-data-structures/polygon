#include "smooth_sort.h"

std::vector<size_t> leonarde_numbers(size_t n) {
    std::vector<size_t> res(n + 1, 0);
    res[0] = 1;
    for (size_t i = 1; i <= n; ++i) res[i] = res[i - 1] * 2 + 1;
    return res;
}