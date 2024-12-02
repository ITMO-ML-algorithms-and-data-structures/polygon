class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        if (k >= n / 2) {
            int maxPr = 0;
            for (int i=1; i<n; i++){
                if (prices[i] > prices[i-1])
                    maxPr += prices[i]-prices[i-1];
            }
            return maxPr;
        }

        std::vector<int> dp_buy(k+1, INT_MIN), dp_sell(k+1, 0);
        for (int price : prices){
            for (int j=1; j<=k; j++){
                dp_buy[j] = max(dp_buy[j], dp_sell[j-1] - price);
                dp_sell[j] = max(dp_sell[j], dp_buy[j] + price);
            }
        }
        return dp_sell[k];
    }
};