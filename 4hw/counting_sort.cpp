#include "counting_sort.h"


void counting_sort(std::vector<long long> &input_vector) {
    size_t vector_size = input_vector.size();
    long long max_element = input_vector[0];
    long long min_element = input_vector[0];

    for (size_t i = 0; i < vector_size; ++i) {
        max_element = std::max(max_element, input_vector[i]);
        min_element = std::min(min_element, input_vector[i]);
    }
    // O(n) - время

    std::vector<size_t> count_vector(max_element - min_element + 1, 0);
    // O(максимальный элемент - минимальный элемент) - время и память

    for (size_t i = 0; i < vector_size; ++i)
        count_vector[input_vector[i] - min_element]++;
    // O(n) - время

    for (size_t i = 1; i <= max_element - min_element; ++i)
        count_vector[i] += count_vector[i - 1];
    // O(максимальный элемент) - время

    std::vector<long long> output_vector(vector_size);
    // O(n) - время и память

    for (size_t i = vector_size - 1; i >= 0; --i) {
        output_vector[count_vector[input_vector[i] - min_element] - 1] = input_vector[i];

        count_vector[input_vector[i] - min_element]--;
        if (i == 0)
            break;
    }
    // O(n) - время

    input_vector = output_vector;

    // O(n + максимальный элемент) - время
    // O(n + максимальный элемент) - память
}


std::pair<std::string, double> execute_counting_sort(const std::string &input) {
    std::vector<long long> v;

    std::istringstream input_ss(input);
    long long tmp;
    while (input_ss >> tmp)
        v.push_back(tmp);

    const size_t start = clock();
    counting_sort(v);
    const size_t end = clock();

    std::ostringstream output_ss;
    for (const long long &e: v)
        output_ss << e << ' ';

    return {output_ss.str(), (double) (end - start) / CLOCKS_PER_SEC};
}
