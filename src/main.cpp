#include <iostream>
#include <vector>
#include <string>
#include <unordered_set> 
#include <sstream>
#include <array>

#define LOG(X) std::cout<<X<<"\n";

size_t GLOB_MEM_USED = 0;
void* operator new(size_t size) {
    GLOB_MEM_USED += size;
    return malloc(size);
}

size_t RAND_SEED = 2634885343;
int rand() {
    RAND_SEED = RAND_SEED * 9823489423 + 8234234;
    return (RAND_SEED / 65536);
}

std::vector<int> sample(const int& size, const std::vector<int>& input) {
    std::unordered_set<size_t> idxs;
    std::vector<int> output(size);
    for (auto inputIter = input.rbegin(); inputIter != input.rend(); ++inputIter) {
        size_t idx;
        do {
            idx = rand();
            idx = idx % size;
        } while (idxs.find(idx) != idxs.end());
        idxs.insert(idx); output[idx] = *inputIter;
    }
    return output;
}


int main() {
    std::cout << "size=? >";
    size_t size;
    std::cin >> size;
    std::cin.ignore();

    std::vector<int> input;
    std::string line;
    std::cout << "arr>";

    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string snum;
    while (std::getline(iss, snum, ' ' )) {
        input.push_back(std::stoi(snum));
    }

    if (input.size() != (size)) {
        std::cout << "num of ​​entered values doesnt match with entered size";
        return 1;
    }

    std::vector<int> output = sample(size, input);
    std::cout << "sampled: ";
    for (auto outputIter = output.rbegin(); outputIter != output.rend(); ++outputIter) {
        std::cout << *outputIter << " ";
    }
    std::cout << "\n";
   
    LOG("mem by overloaded `operator new`:" << GLOB_MEM_USED << "\n");

    return 0;
}