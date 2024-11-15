#include <iostream>
#include <vector>

#include "IComparator.hpp"

#ifndef XORSHIFT
#define XORSHIFT
uint32_t RAND_SEED = 2342334332;

uint32_t xorshift32() { // src:wiki 
	RAND_SEED ^= RAND_SEED << 13;
	RAND_SEED ^= RAND_SEED >> 17;
	RAND_SEED ^= RAND_SEED << 5;
	return RAND_SEED;
}

#define RAND() xorshift32()
#endif


#include "sorts/shitsort/bogosort.cpp"
#include "sorts/shitsort/stalinsort.cpp"

#include "sorts/n^2/bublesort.cpp"
#include "sorts/n^2/exchangesort.cpp"
#include "sorts/n^2/lazysort.cpp"
#include "sorts/n^2/shakersort.cpp"

#include "sorts/nk/gravitysort.cpp"
#include "sorts/nk/radixsort.cpp"

#include "sorts/nlogn/quicksort.cpp"


template <typename T>
class Comparator : public IComparable<T> {
public:
    int compareTo(const T& v1, const T& v2) const override {
        if (v1 < v2) return -1;
        if (v1 > v2) return 1;
        return 0;
    }
};


std::vector<int> generateRandomVec(int n) {
    std::vector<int> vec(n);
    for (size_t i = 0; i < n; i++) {
        vec[i] = RAND() % n + 1;
    }
    return vec;
}

bool is_vec_sorted(const std::vector<int>& v, const IComparable<int>& comparator) {
    for (size_t i = 0; i < v.size() - 1; i++) {
        if (comparator.compareTo(v[i], v[i + 1]) > 0) {
            return false;
        }
    }
    return true;
}


int main() {
    std::vector<int> randVec;
    Comparator<int> comparator;


    /*
        ATTENTION !!! НЕ ЗАПУСКАТЬ С 4+ ЭЛЕМЕНТАМИ
    */
    // randVec = generateRandomVec(3);
    // bogosort(randVec, comparator);
    // std::cout << "bogosort\t: " << (is_vec_sorted(randVec, comparator) ? "OK" : "ERR") << " :\t";
    // for (auto& i : randVec) {
    //     std::cout << i << " ";
    // } std::cout << "\n";

    // по приказу сталина сортируется за O(n) но есть одно но...
    randVec = generateRandomVec(50);
    stalinsort(randVec, comparator);
    std::cout << "stalinsort\t: " << (is_vec_sorted(randVec, comparator) ? "OK" : "ERR") << " :\t";
    for (auto& i : randVec) {
        std::cout << i << " ";
    } std::cout << "\n";

    // баблик за n^2
    randVec = generateRandomVec(50);
    bubblesort(randVec, comparator);
    std::cout << "bubblesort\t: " << (is_vec_sorted(randVec, comparator) ? "OK" : "ERR") << " :\t";
    for (auto& i : randVec) {
        std::cout << i << " ";
    } std::cout << "\n";

    // типо баблик но не проверяет уже отсортированные элементы, < n^2
    randVec = generateRandomVec(50);
    exchangesort(randVec, comparator);
    std::cout << "exchangesort\t: " << (is_vec_sorted(randVec, comparator) ? "OK" : "ERR") << " :\t";
    for (auto& i : randVec) {
        std::cout << i << " ";
    } std::cout << "\n";

    // баблик++, O(n) в лучшем случае
    randVec = generateRandomVec(50);
    lazysort(randVec, comparator);
    std::cout << "lazysort\t: " << (is_vec_sorted(randVec, comparator) ? "OK" : "ERR") << " :\t";
    for (auto& i : randVec) {
        std::cout << i << " ";
    } std::cout << "\n";

    // гравик через мапу 
    randVec = generateRandomVec(50);
    gravitysort(randVec, comparator);
    std::cout << "gravitysort\t: " << (is_vec_sorted(randVec, comparator) ? "OK" : "ERR") << " :\t";
    for (auto& i : randVec) {
        std::cout << i << " ";
    } std::cout << "\n";

    // базированный радикс, базированные порядки. вроде как должен работать не с целыми числами
    randVec = generateRandomVec(50);
    radixsort(randVec, comparator);
    std::cout << "radixsort\t: " << (is_vec_sorted(randVec, comparator) ? "OK" : "ERR") << " :\t";
    for (auto& i : randVec) {
        std::cout << i << " ";
    } std::cout << "\n";

    // qs базированная
    randVec = generateRandomVec(50);
    quicksort(randVec, comparator);
    std::cout << "quicksort\t: " << (is_vec_sorted(randVec, comparator) ? "OK" : "ERR") << " :\t";
    for (auto& i : randVec) {
        std::cout << i << " ";
    } std::cout << "\n";

    // потом понял что надо было по одному алгоритму на одну таску = 3 алгоса. дальше мне стало лень чета писать    

    return 0;
}
