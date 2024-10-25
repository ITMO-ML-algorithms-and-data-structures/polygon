#include "MersenneTwister.h"

MersenneTwister::MersenneTwister(const int seed) { // O(1)
    MT[0] = seed;

    for (auto i = 1; i < n; i++) {
        MT[i] = (f * (MT[i - 1] ^ (MT[i - 1] >> (w - 2)))) + i;
    }

    index = 0;
}

unsigned int MersenneTwister::operator()() { // O(1)
    unsigned int x = (MT[index] & upper_mask) | (MT[(index + 1) % n] & lower_mask);

    unsigned int xA = x >> 1;

    if (x & 1UL)
        xA ^= a;

    x = MT[(index + m) % n] ^ xA;
    MT[index++] = x;

    if (index >= n)
        index = 0;

    unsigned int y = x ^ (x >> u);
    y = y ^ ((y << s) & b);
    y = y ^ ((y << t) & c);

    return y ^ (y >> l);
}

void MersenneTwister::seed(int seed) { // O(1)
    MT[0] = seed;

    for (auto i = 1; i < n; i++) {
        MT[i] = (f * (MT[i - 1] ^ (MT[i - 1] >> (w - 2)))) + i;
    }

    index = 0;
}

unsigned int MersenneTwister::get_max_value() {
    return 4294967295;
}
