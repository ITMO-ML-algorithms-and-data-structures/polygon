#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> sampleArray(const std::vector<int>& input, int K) {
    if (K > input.size()) {
        throw std::invalid_argument("K > input. Change!!!!!!!");
    }

    std::vector<int> copy = input;
    // O(N) - копирование вектора
    // вектор состоит (4*10) 40 байт

    std::random_device rd;
    // 32 байта
    std::mt19937 gen(rd());
    // 64 байта
    // в сумме 96 байт

    std::shuffle(copy.begin(), copy.end(), gen);
    // O(N) - асимптотика

    return std::vector<int>(copy.begin(), copy.begin() + K);
    // 20 байт, так как K = 5
    // О(K) - первые K элем 
    // общая память 40+40+96+20=196 байт

} // O(N) - асимптотика

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int K = 5;
    // здесь лучше обрабатывать 
    // лучше обрабатыавать битовой маской 
    std::vector<int> sampled = sampleArray(input, K);
    for (int num : sampled) {
        std::cout << num << " ";
    }

    return 0;
}
