#include <vector>
#include <cstddef>
#include <random>

std::vector<long long> generate_integer_dataset(const size_t dataset_size) {
    std::vector<long long> dataset;
    dataset.reserve(dataset_size);
    for (size_t i = 0; i < dataset_size; ++i)
        dataset.push_back(rand());
    return dataset;
}
