#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

#include "sample.cpp"

#define LOG(X) std::cout<<X<<"\n";

// лайфхак как достаточно просто посчитать затраты на память, спасибо костянчик
size_t GLOB_MEM_USED = 0;
void* operator new(size_t size) {
    GLOB_MEM_USED += size;
    return malloc(size);
}

int main() {
    std::cout << "size=? >";
    size_t size;
    std::cin >> size;
    std::cin.ignore();

    std::cout << "arr >";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> input((std::istream_iterator<int>(iss)), std::istream_iterator<int>()); // cpp refference one love

    if (input.size() != size) {
        std::cout << "num of ​​entered values doesnt match with entered size\n";
        return 1;
    }

    std::vector<int> output = sample(size, input);
    std::cout << "sampled: ";
    for (auto outputIter = output.rbegin(); outputIter != output.rend(); ++outputIter) {
        std::cout << *outputIter << " ";
    }
    std::cout << "\n";

    LOG("mem by overloaded `operator new`: " << GLOB_MEM_USED << "\n");

    return 0;
}