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

void generate_integer_dataset_to_file(const size_t dataset_size, const std::string &file_name) {
    std::ofstream dataset_file(file_name);
    std::vector<long long> v = generate_integer_dataset(dataset_size);
    for (const long long &j : v) {
        dataset_file << j << " ";
    }
    dataset_file.close();
}
