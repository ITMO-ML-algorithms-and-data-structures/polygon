#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int max_income(int k, vector<int>& prices)
{
    int n = prices.size();
    if (n == 0 || k == 0) return 0;

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; ++i) {
        int maxDiff = -prices[0];

        for (int j = 1; j < n; ++j) {
            dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
        }
    }
    return dp[k][n - 1];
}

int main() //память - 84 байта, сложность - O(n * k)
{
    ifstream input_file("test_lab6.txt");
    vector<int> prices;
    int k = 2;

    int value;
    while (input_file >> value) {
        prices.push_back(value);
    }
    input_file.close();

    cout << max_income(k, prices) << endl;

    return 0;
}