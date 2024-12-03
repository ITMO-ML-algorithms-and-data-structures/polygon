#include <iostream>
#include <string>


void print_vector(std::string prefix, std::vector<float> &vec) {
    std::cout << prefix;
    for (auto val : vec) {
        std::cout << " " << val;
    }
    std::cout << std::endl;
}