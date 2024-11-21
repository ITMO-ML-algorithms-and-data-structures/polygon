#include "counting sort.h"

void countSort(std::vector<long long> &input_vector) {
    size_t vector_size = input_vector.size();
    long long max_element = input_vector[0];

    for (size_t i = 0; i < vector_size; ++i)
        max_element = std::max(max_element, input_vector[i]);
    // O(n) - время

    std::vector<size_t> count_vector(max_element + 1, 0);
    // O(максимальный элемент) - время и память

    for (size_t i = 0; i < vector_size; ++i)
        count_vector[input_vector[i]]++;
    // O(n) - время

    for (size_t i = 1; i <= max_element; ++i)
        count_vector[i] += count_vector[i - 1];
    // O(максимальный элемент) - время

    std::vector<long long> output_vector(vector_size);
    // O(n) - время и память

    for (size_t i = vector_size - 1; i >= 0; --i) {
        output_vector[count_vector[input_vector[i]] - 1] = input_vector[i];

        count_vector[input_vector[i]]--;
    }
    // O(n) - время

    input_vector = output_vector;

    // O(n + максимальный элемент) - время
    // O(n + максимальный элемент) - память
}
