#include <iostream>
#include <random>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <vector>
#include <algorithm> // For std::shuffle
#include <chrono>
#include <thread>

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

    std::vector<int> sample(sample_size); // This will store 3 sampled elements

    // Create a vector of indices
    std::vector<int> available_index(array_size);
    for (int i = 0; i < array_size; ++i) {
        available_index[i] = i; // Fill with available indices
    }

    // Generate a random number generator with a random seed
    // std::random_device rd;  // Obtain a random number from hardware
    // std::mt19937 gen(rd()); // Seed the generator

    // std::shuffle(available_index.begin(), available_index.end(), gen);

    // Shuffle the indices
    // std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed for randomness
    // std::random_shuffle(available_index.begin(), available_index.end());

    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::srand(static_cast<unsigned>(seed));

    std::random_shuffle(available_index.begin(), available_index.end());

    // Populate the sample
    for (int i = 0; i < sample_size; ++i) {
        int random_index = i; // Make sure this is within bounds
        sample[i] = array_to_sample[available_index[random_index]];
    }

    return sample;
}


void test() {
    int arr1[10000];

    for(int i = 0; i < 10000; i ++) {
        arr1[i] = i;
    }

    for(int k = 1; k <= 10; k ++) {
        std::vector<int> res_sample = get_array_sample(arr1, 10000, k);


        for(auto elem : res_sample) {
            std::cout << elem << " ";
        }

        std::cout << std::endl;

        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}


int main() {
    // int size = 4;
    // int arr[size]= {1, 100, 10, 2};
    // int k = 3;

    // std::vector<int> result_sample = get_array_sample(arr, size, k);

    test();

    return 0;
}