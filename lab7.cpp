class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> indx(n);
        for (int i = 0; i < n; i++) {
            indx[i] = i;
        }

        sort(indx.begin(), indx.end(), [&](int i, int j) {
            return capital[i] < capital[j];
        });

        priority_queue<int> maxProfit;

        int curr = 0;

        for (int i = 0; i < k; i++) {
            while (curr < n && capital[indx[curr]] <= w) {
                maxProfit.push(profits[indx[curr]]);
                curr++;
            }
            if (maxProfit.empty()) {
                break;
            }
            w += maxProfit.top();
            maxProfit.pop();

        }
        return w;
    }
};