#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <vector>
#include <algorithm> // For std::shuffle

std::vector<int> get_array_sample(int* array_to_sample, int array_size, int sample_size) {
    // int sample[sample_size];
    // std::vector<int> available_index;
    // int tmp_index_num = array_size;

    // for(int i = 0; i < array_size; i ++) {
    //     available_index.push_back(i);
    // }

    // for (int i = 0; i < sample_size; i ++) {
    //     int random_index = std::rand() % tmp_index_num;
        
    //     sample[i] = array_to_sample[available_index[random_index]];

    //     available_index.erase(available_index.begin() + random_index);
    //     tmp_index_num --;
    // }

    std::vector<int> sample(3); // This will store 3 sampled elements

    // Create a vector of indices
    std::vector<int> available_index(array_size);
    for (int i = 0; i < array_size; ++i) {
        available_index[i] = i; // Fill with available indices
    }

    // Shuffle the indices
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed for randomness
    std::random_shuffle(available_index.begin(), available_index.end());

    // Populate the sample
    for (int i = 0; i < sample_size; ++i) {
        int random_index = i; // Make sure this is within bounds
        sample[i] = array_to_sample[available_index[random_index]];
    }

    return sample;
}

int main() {
    int size = 4;
    int arr[size]= {1, 100, 10, 2};
    int k = 3;

    std::vector<int> result_sample = get_array_sample(arr, size, k);

    for(auto elem : result_sample) {
        std::cout << elem << " ";
    }
}