#include <iostream>
#include <unordered_map>
#include <vector>

void test(std::vector<std::string> inputArray){

    std::unordered_map<std::string, int> frequancyMap;

    for (const std::string& word : inputArray){
        frequancyMap[word]++;
    }

    for (std::string& word : inputArray){
        word = std::to_string(frequancyMap[word]);
    }

    for (const std::string& count : inputArray){
        std::cout << count << " "; 
    }

}

int main(){
    std::unordered_map<std::string, int> frequancyMap;

    std::vector<std::string> inputArray = {"Orange", "Red", "Green", "Orange"}; 
    std::vector<std::string> inputArray2 = {"Orange", "Orange", "Orange", "Orange"}; 
    std::vector<std::string> inputArray3 = {" ", " ", " ", " "}; 
    std::vector<std::string> inputArray4 = {}; 
    
    test(inputArray);
    test(inputArray2);
    test(inputArray3);
    test(inputArray4);

    return 0;

}
