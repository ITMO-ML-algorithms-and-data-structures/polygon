#include <iostream>
#include <vector>
#include "sample.cpp"

std::vector<int> generateRandomVector(size_t size) {
    std::vector<int> output;

    for (size_t i = 0; i < size; ++i) {
        int x = std::rand() % (1 << 16); // максимальное число 
        output.push_back(x);
    }

    return output;
}

double mae(const std::vector<int>& source, const std::vector<int>& sampled) {
    double err = 0.0;
    for (size_t i = 0; i < source.size(); ++i) {
        err += std::abs(source[i] - sampled[i]);
    }
    return err / source.size();
}

int main() {
    std::vector<size_t> sizes = {1, 10, 100, 1000, 10000, 100000};

    for (size_t size : sizes) {
        std::vector<int> input = generateRandomVector(size);
        std::vector<int> sampled = sample(size, input);
        std::cout << "size: " << size << " \tmae: " << mae(input, sampled) << "\n"; 
    }

    return 0;
}
