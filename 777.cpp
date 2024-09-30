#include <iostream>
#include <vector>
int main() {
    const int size = 10000;
    int inputArray[size];
    for (int i = 0; i < size; ++i) {
        inputArray[i] = rand() % 99 + 1;
    }
    bool seen[100] = {false}; 
    std::vector<int> outputArray;
 for (int i = 0; i < size; ++i) {
     if (!seen[inputArray[i]]) {
         seen[inputArray[i]] = true;
         outputArray.push_back(inputArray[i]);
     }
 }
 std::cout << "Массив без дубликатов: ";
 for (const auto &value : outputArray) {
     std::cout << value << " ";
 }
 return 0;
}