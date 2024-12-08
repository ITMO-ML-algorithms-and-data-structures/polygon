#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> minCoins(amount + 1, amount + 1); // (amount + 1) * 4 byte + 24 byte vector
    minCoins[0] = 0;

    for (int i = 1; i <= amount; i++) { // 4 byte for i; O(amount)
        for (int j = 0; j < coins.size(); j++) { //4 byte for j; O(num_coins)
            // O(num_coins*amount)
            if (i - coins[j] >= 0) {
                minCoins[i] = min(minCoins[i], 1 + minCoins[i - coins[j]]);
            }
        }
    }
    return minCoins[amount] != amount + 1 ? minCoins[amount] : -1;
}


int maxSubArray(vector<int>& nums) {
    int res = nums[0]; // int = 4 byte
    int maxEnding = nums[0]; // int = 4 byte
    for (int i = 1; i < nums.size(); i++) { //O(N)
        maxEnding = max(maxEnding + nums[i], nums[i]);
        res = max(res, maxEnding);
    }
    return res;
}


int main() {
    int amount = 11251;
    vector<int> coins = {10, 2, 3, 20, 1, 5, 100};
    int mincoins = coinChange(coins, amount);
    cout << mincoins << endl;
    vector<int> array = {1, -2, 3, 2, 1, -5, 1};
    int maxSum = maxSubArray(array);
    cout << maxSum << endl;
}