#include <iostream>
#include <vector>

using namespace std;

/*
    vector<int> nums = { 3, 6, 9, 23, 7, 2, 53 };
    int S = 32;
*/

void findCombination(const vector<int> nums, int S, vector<int> combination, int co_start) {

    for (int i = co_start; i < nums.size(); ++i) {
        if (nums[i] > S) continue;

        combination.push_back(nums[i]);
        findCombination(nums, S - nums[i], combination, i + 1);
        combination.pop_back();
    }

    if (S == 0) {
        std::cout << "{ ";
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << "}\n";
        return;
    }
}


int main() {
    vector<int> nums = { 3, 6, 9, 23, 7, 2, 53 };
    int S = 32;

    std::vector<int> combination;
    std::cout << "Combinations with the sum of " << S << ":\n";
    findCombination(nums, S, combination, 0);

    return 0;
}

