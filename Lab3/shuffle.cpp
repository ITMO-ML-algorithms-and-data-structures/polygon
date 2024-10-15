#include <vector>
#include <iostream>
#include <fstream>
#include <random>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../Source/doctest.h"

std::vector<int> shuffle(const std::string& path) {

    std::ifstream file(path);
    size_t size; file >> size;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<int> array(size);
    for (size_t i = 0; i < size; i++)
        file >> array[i];

    for (int i = size - 1; i >= 0; i--) {

        std::uniform_int_distribution<> dist(0, i);
        size_t random_index = dist(gen);
        std::swap(array[i], array[random_index]);

    }

    return array;

}

TEST_CASE("Testing the shuffle function") {

    std::string 
        path1 = "../Tests/shuffle/test_shuffle_1.csv",
        path2 = "../Tests/shuffle/test_shuffle_2.csv",
        path3 = "../Tests/shuffle/test_shuffle_3.csv";
            
    CHECK(shuffle(path1) == std::vector<int> {});
    CHECK(shuffle(path2) != shuffle(path2));

}