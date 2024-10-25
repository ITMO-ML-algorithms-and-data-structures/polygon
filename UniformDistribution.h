#ifndef POLYGON_UNIFORMDISTRIBUTION_H
#define POLYGON_UNIFORMDISTRIBUTION_H

class UniformDistribution {
private:
    int min;
    int max;
public:
    template<typename GeneratorType>
    unsigned int operator() (GeneratorType& gen);

    UniformDistribution(int min_value, int max_value);

    void set_min_max_values(int min_value, int max_value);
};

#include "UniformDistribution.cpp"

#endif //POLYGON_UNIFORMDISTRIBUTION_H
