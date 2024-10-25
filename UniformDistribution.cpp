#include "UniformDistribution.h"

template <typename GeneratorType>
unsigned int UniformDistribution::operator() (GeneratorType& gen) { // O(1)
    return min + (gen() % (max - min + 1));
}

UniformDistribution::UniformDistribution(const int min_value, const int max_value) { // O(1)
    set_min_max_values(min_value, max_value);
}

void UniformDistribution::set_min_max_values(const int min_value, const int max_value) { // O(1)
    min = min_value;
    max = max_value;
}