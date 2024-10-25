#ifndef POLYGON_MERSENNETWISTER_H
#define POLYGON_MERSENNETWISTER_H

class MersenneTwister {
private:
    static const int n = 624;
    static const int w = 32;
    static const int r = 31;
    static const int m = 397;
    static const int u = 11;
    static const int s = 7;
    static const int t = 15;
    static const int l = 18;

    static const unsigned int a = 0x9908B09F;
    static const unsigned int b = 0x9D2C5680;
    static const unsigned int c = 0xEFC60000;
    static const unsigned int f = 0x6C078965;

    static const unsigned int lower_mask = (1u << r) - 1;
    static const unsigned int upper_mask = ~lower_mask;

    unsigned int MT[n]{};
    int index = 0;

public:
    explicit MersenneTwister(int seed);

    void seed(int s);

    unsigned int operator() ();

    static unsigned int get_max_value();
};

#include "MersenneTwister.cpp"

#endif //POLYGON_MERSENNETWISTER_H
