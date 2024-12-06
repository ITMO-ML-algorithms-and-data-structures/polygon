#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, int> memo;
    
    bool canPartition(vector<int>& nums, int index, int totalElements, int targetSum, int remainingElements)
    {
        if(remainingElements == 0)
            return targetSum == 0;
        
        if(index == totalElements)
            return false;
        
        string state = to_string(index) + "#" + to_string(remainingElements) + "#" + to_string(targetSum);
        
        if(memo.count(state))
            return memo[state];
        
        if(nums[index] <= targetSum)
        {
            return memo[state] = canPartition(nums, index + 1, totalElements, targetSum - nums[index], remainingElements - 1) || canPartition(nums, index + 1, totalElements, targetSum, remainingElements);
        }
        else
            return memo[state] = canPartition(nums, index + 1, totalElements, targetSum, remainingElements);
    }
    
    bool splitArraySameAverage(vector<int>& nums) {
        int totalElements = nums.size();
        int totalSum = 0;
        
        for(int i = 0; i < totalElements; i++)
        {
            totalSum += nums[i];
        }
        
        for(int remainingElements = 1; remainingElements < totalElements; remainingElements++)
        {
            if((totalSum * remainingElements) % totalElements == 0)
            {
                int targetSum = (totalSum * remainingElements) / totalElements;
            
                if(canPartition(nums, 0, totalElements, targetSum, remainingElements))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Пример входных данных
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8}; // Пример массива
    
    bool result = solution.splitArraySameAverage(nums);

    if (result) {
        cout << "Можно разбить массив на подмножества с одинаковой средней величиной." << endl;
    } else {
        cout << "Невозможно разбить массив на подмножества с одинаковой средней величиной." << endl;
    }

    return 0;
}
