#include <vector>
#include <iostream>

using std::vector, std::min;

long long maximum_value_sum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size(); 
        long long ans = 0; 
        int xor_d = 1e9;
        int nxor_d = 1e9;
        int cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            int xor_val = nums[i]^k;
            if (xor_val > nums[i]) {
                cnt++;
                ans += xor_val; 
                xor_d = min(xor_d , xor_val - nums[i]);
            } else {
                ans += nums[i];
                nxor_d = min(nxor_d , nums[i]-xor_val); 
            }
        }
        if (cnt%2 == 0) 
            return ans;

        return ans - min(xor_d, nxor_d);
    }

int main() {
    vector<int> nums = {24,78,1,97,44};
    vector<vector<int>> edges = {{0,2}, {1,2}, {4,2}, {3,4}};
    int k = 6;

    std::cout << maximum_value_sum(nums, k, edges);
    }