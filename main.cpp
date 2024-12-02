#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int totalCount = 0;
        vector<unordered_map<long long, int>> dp(nums.size());
        for (int i = 0; i < size(nums); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                long long diff = static_cast<long long>(nums[i]) - nums[j];
                int countAtJ = dp[j][diff];
                dp[i][diff] += countAtJ + 1;
                totalCount += countAtJ;
            }
        }
        return totalCount;
    }
};