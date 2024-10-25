#include <vector>
#include <iostream>
#include "lab.cpp"
#include "UniformDistribution.h"
#include "MersenneTwister.h"
#include <string>
#include <cmath>

typedef long long ll;

typedef long long ll;

int main() {
    MersenneTwister gen(42);
    UniformDistribution dis(1, 100);

    std::vector<unsigned int> counter(100, 0);

    for(int i=0; i<10000; i++)
        counter[dis(gen) - 1]++;

    unsigned int a = 5;

    std::cout << std::pow(97 - 100, 2) * 1.0 / 100;
}