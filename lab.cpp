#include <vector>
#include <iostream>
#include "UniformDistribution.h"
#include "MersenneTwister.h"
#include <ctime>
#include <optional>
#include <fstream>
#include <string>
#include <tuple>

typedef long long ll;

template<typename T>
void swap(T &a, T &b) {
    T tmp = a; // O(1)
    a = b; // O(1)
    b = tmp; // O(1)
}

template<typename T>
void shuffle(std::vector<T> &array, std::optional<int> seed = std::nullopt) {
    MersenneTwister gen(seed.has_value() ? seed.value() : std::time(nullptr)); // O(1) - 624 итерации цикла
    UniformDistribution dis(0, array.size() - 1); // O(1)

    for (unsigned int i = 0; i < array.size(); i++) {  // O(n)
        unsigned int j = dis(gen); // O(1)
        swap(array[i], array[j]); // O(1)
    }

    // Общая сложность функции - O(n)
}

template<typename T>
std::vector<T> sample(std::vector<T> array, const int k, std::optional<int> seed = std::nullopt) {
    if (k < 0 || k > array.size()) { // O(1) + O(1) + O(1)
        throw std::runtime_error("k should be 0 <= k <= size of array"); // O(1)
    }

    shuffle(array, seed); // O(n)

    return std::vector<T>(array.begin(), array.begin() + k); // O(k) + O(k) по памяти
}

template<typename T>
std::tuple<unsigned int, std::vector<T>, unsigned int> read_data_from_console() {
    unsigned int size, k; // O(1) + O(1)
    std::vector<T> array; // O(1)

    std::cin >> size;

    array.resize(size); // O(1)

    for (int i = 0; i < size; i++)
        std::cin >> array[i];

    std::cin >> k;

    return {size, array, k};
}

template<typename T>
std::tuple<unsigned int, std::vector<T>, unsigned int> read_data_from_txt_file(std::string input_file_path) {
    std::vector<T> array;
    std::ifstream input_file(input_file_path);

    if (!input_file.is_open()) {
        throw std::runtime_error("Failed to open input file");

    }

    T input_value;

    unsigned int size;
    input_file >> size;
    array.resize(size);

    for (unsigned int num_rows = 0; num_rows < size; num_rows++)
        input_file >> array[num_rows];

    unsigned int k = input_value;
    input_file >> k;

    input_file.close();
    return {size, array, k};
}

template<typename T>
void output_to_console(std::vector<T> array) {
    for (auto i: array)
        std::cout << i << " ";
    std::cout << std::endl;
}

template<typename T>
void output_to_file(std::vector<T> array, std::string output_file_path) {
    std::ofstream output_file(output_file_path);

    if (!output_file.is_open())
        throw std::runtime_error("Failed to open output file");

    for (auto i: array) {
        output_file << i << "\n";
    }

    output_file.close();
}

template<typename T>
void solve(
        bool is_from_file,
        bool is_to_file,
        std::optional<std::string> input_file_path = std::nullopt,
        std::optional<std::string> output_file_path = std::nullopt,
        std::optional<unsigned int> seed = std::nullopt
) {
    if (is_from_file && !input_file_path) // O(1)
        throw std::runtime_error("no input file name"); // O(1)

    if (is_to_file && !output_file_path) // O(1)
        throw std::runtime_error("no output file name"); // O(1)

    unsigned int size, k;
    std::vector<T> array;

    if (is_from_file)
        std::tie(size, array, k) = read_data_from_txt_file<T>(input_file_path.value());
    else
        std::tie(size, array, k) = read_data_from_console<T>();

    std::cout << "data is collected\n";

    std::vector<T> result = sample(array, k, seed); // O(n + k) = O(n)

    std::cout << "ready\n";

    if (is_to_file)
        output_to_file(result, output_file_path.value());
    else
        output_to_console(result);
};
