#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Solution {

public:

    bool canCross(std::vector<int>& stones) {

        if (stones.size() == 2 && stones[1] == 1) return true;

        std::vector<std::vector<bool>> visited(stones.size(), std::vector<bool>(stones.size(), false)); 
        return func(0, 0, visited, stones);

    }

private:

    bool func(int cur_ind, int k, std::vector<std::vector<bool>>& visited, const std::vector<int>& stones) {


        if (cur_ind >= stones.size()) return false;
        if (visited[cur_ind][k]) return false;
        if (cur_ind == stones.size() - 1) return true;

        visited[cur_ind][k] = true;
        bool res = false;
        
        for (int i = k - 1; i <= k + 1; i++) {

            if (i <= 0) continue;

            if (std::binary_search(stones.begin() + cur_ind, stones.end(), stones[cur_ind] + i))
                res = res || func(std::lower_bound(stones.begin() + cur_ind, stones.end(), stones[cur_ind] + i) - stones.begin(), i, visited, stones);

        }
        return res;

    }
        
};