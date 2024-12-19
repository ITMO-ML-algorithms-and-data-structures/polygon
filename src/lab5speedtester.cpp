#include <iostream>
#include <vector>
#include <chrono>
#include <functional>

#include "IComparator.hpp"

#ifndef XORSHIFT
#define XORSHIFT
uint32_t RAND_SEED = 2342334332;

uint32_t xorshift32()
{ // src:wiki
    RAND_SEED ^= RAND_SEED << 13;
    RAND_SEED ^= RAND_SEED >> 17;
    RAND_SEED ^= RAND_SEED << 5;
    return RAND_SEED;
}

#define RAND() xorshift32()
#endif

std::vector<int> generateRandomVec(int n) {
    std::vector<int> vec(n);
    for (size_t i = 0; i < n; i++) {
        vec[i] = RAND() % n + 1;
    }
    return vec;
}

template <typename T>
class Comparator : public IComparable<T> {
public:
    int compareTo(const T& v1, const T& v2) const override {
        if (v1 < v2) return -1;
        if (v1 > v2) return 1;
        return 0;
    }
};

// #include "sorts/shitsort/bogosort.cpp"
// #include "sorts/shitsort/stalinsort.cpp"

#include "sorts/n^2/bublesort.cpp"
#include "sorts/n^2/exchangesort.cpp"
#include "sorts/n^2/lazysort.cpp"
#include "sorts/n^2/shakersort.cpp"

#include "sorts/nk/gravitysort.cpp"
#include "sorts/nk/radixsort.cpp"

#include "sorts/nlogn/quicksort.cpp"

/*
    ./lab5speedtester -t [bublesort] -n [100]
*/
int main(int argc, char **args) {
    std::vector<int> randVec;
    Comparator<int> comparator;

    //thx codestral
    std::function<void(std::vector<int> &, IComparable<int> &)> sortptr;
    uint32_t n = 0;

    for (int i = 1; i < argc; i += 2) {
        std::string flag = args[i];
        if (flag == "-t") {
            std::string algorithm = args[i + 1];
            if (algorithm == "bublesort")    sortptr = bubblesort<int>;
            if (algorithm == "exchangesort") sortptr = exchangesort<int>;
            if (algorithm == "lazysort")     sortptr = lazysort<int>;
            if (algorithm == "shakersort")   sortptr = shakersort<int>;
            if (algorithm == "gravitysort")  sortptr = gravitysort<int>;
            if (algorithm == "radixsort")    sortptr = radixsort<int>;
            if (algorithm == "quicksort")    sortptr = quicksort<int>;
        }
        else if (flag == "-n") {
            n = std::stoi(args[i + 1]);
        }
    }


    randVec = generateRandomVec(n);

    auto start = std::chrono::high_resolution_clock::now();
    sortptr(randVec, comparator);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << elapsed.count() << "\n";
}
