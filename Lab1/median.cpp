#include <iostream>
#include <vector>
#include <algorithm>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../Source/doctest.h"

// Найти медиану массива (middle +)

using namespace doctest;

double median(std::vector<long long>& vec) {

    std::sort(vec.begin(), vec.end());    // Сортируем массив

    if (vec.size() % 2 == 0)
        return (double)(vec[vec.size() / 2] + vec[vec.size() / 2 - 1]) / 2;
    else
        return (double)(vec[vec.size() / 2]);

}

TEST_CASE("testing the median function") {
    std::vector<long long> 
        vec1{1, 2, 3, 4, 5},
        vec2{12, 8, -10, 20, 15, 41, -7, -18, 11},
        vec3{2},
        vec4{6, 5, 4, 3, 2, 1},
        vec5{1, 1, 1, 1, 1},
        vec6{-1, 1, -1, 1, -1, 1};
    CHECK(median(vec1) == 3.0);
    CHECK(median(vec2) == 11.0);
    CHECK(median(vec3) == 2.0);
    CHECK(median(vec4) == 3.5);
    CHECK(median(vec5) == 1.0);
    CHECK(median(vec6) == 0.0);
}
