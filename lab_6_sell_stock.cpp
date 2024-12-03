//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) {
            return 0;
        }
        if (k >= n / 2) {
            int max_profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int j = 1; j <= k; j++) {
            int max_profit_prev = INT_MIN;
            for (int i = 1; i < n; i++) {
                max_profit_prev = max(max_profit_prev, dp[j - 1][i - 1] - prices[i - 1]);
                dp[j][i] = max(dp[j][i - 1], max_profit_prev + prices[i]);
            }
        }

        return dp[k][n - 1];
    }
};
