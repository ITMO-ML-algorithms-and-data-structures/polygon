#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

std::vector<long long> removeDuplicates(std::vector<long long> input) {// 24 bytes
    std::unordered_set<long long> uniqueValues; // 8 bytes * n
    std::vector<long long> result; // 24 bytes

    for (long long value : input) {
        if (uniqueValues.find(value)==uniqueValues.end()) {
            uniqueValues.insert(value);
            result.push_back(value);
        }
    }
    return result;
}
int main() {
    std::ifstream file("input.txt");
    std::vector<long long> input;// 24 bytes
    long long value;

    while (file>>value) {
        input.push_back(value);
    }
    file.close();

    std::vector<long long> uniqueValues=removeDuplicates(input);// 24 bytes

    for (long long value : uniqueValues) {
        std::cout<<value<<" ";
    }
    return 0;
}