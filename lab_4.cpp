#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>


bool isCover(const std::set<int>& targetCover,
    const std::vector<std::set<int>>& inputSets, int mask){

    std::set<int> covered;

    for (int i = 0; i < inputSets.size(); i++){
        if (mask & (1 << i)){
            covered.insert(inputSets[i].begin(), inputSets[i].end());
        }
    }

    if (std::includes(covered.begin(), covered.end(),
        targetCover.begin(), targetCover.end())){
        return true;
    }
    return false;
}

std::vector<std::set<int>> isLeastCover(
    const std::vector<std::set<int>>& leastCover,
    const std::vector<std::set<int>>& currCover){
    
    if (leastCover.size() < currCover.size()){
        return leastCover;
    }
    return currCover;
}

std::vector<std::set<int>> findCover(
    const std::vector<std::set<int>>& inputSets,
    const std::set<int>& targetCover){
    
    short int n = inputSets.size();
    bool found = false;

    std::vector<std::set<int>> leastCover(inputSets.size() + 1);

    for (int mask = 0; mask < (1 << n); mask++){

        if (isCover(targetCover, inputSets, mask)){
            std::vector<std::set<int>> currentCover;

            for (int i = 0; i < n; ++i){
                if (mask & (1 << i)){
                    currentCover.push_back(inputSets[i]);
                }
            }

            leastCover = isLeastCover(leastCover, currentCover);

            found = true;
        }
    }
    if (!found){
        std::cout << "Something went wrong! Probably, targetCover can't be covered with given data";
        std::cout << "\n";
        return {};
    }
    return leastCover;
}


void test(const std::vector<std::set<int>>& currCover, 
    const std::set<int>& targetCover){
    
    std::set<int> mergedCover;
    for (int i = 0; i < currCover.size(); i++){
        mergedCover.insert(currCover[i].begin(), currCover[i].end());
    }
    
    if (std::includes(mergedCover.begin(), mergedCover.end(),
        targetCover.begin(), targetCover.end())){
        std::cout << "You're cool!";
    } else {
        std::cout << "Wrong answer!";
    }
}


std::vector<std::set<int>> read_array_from_file(const char filename[]) {
    std::vector<std::set<int>> sets;
  
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open the file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::set<int> current_set;
        std::istringstream stream(line);
        int value;

        while (stream >> value) {
            current_set.insert(value);
        }

        sets.push_back(current_set);
    }

    return sets;
}


int main(){

    std::vector<std::set<int>> inputSets = read_array_from_file("inputFile10.txt");  
    std::set<int> targetCover10 = {3, 45, 10, 12, 67, 19, 55, 88, 30, 2};
    std::vector<std::set<int>> resultCover = findCover(inputSets, targetCover10);

    test(resultCover, targetCover10);
    
    return 0;
}