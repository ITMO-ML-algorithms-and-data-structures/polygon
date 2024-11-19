#include <iostream>
#include <vector>

#include "ArrayProcessor.cpp"

int main() {
    ArrayProcessor processor;
    std::vector<int> array = processor.read_array();
    processor.fillna_mean(array);

    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}