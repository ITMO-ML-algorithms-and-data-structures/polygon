class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
       int n = nums.size();
        vector<pair<int, int>> maxPrefixSums(n), maxSuffixSums(n);
        int currentSum = 0;

        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
        }
        maxPrefixSums[k - 1] = {currentSum, k - 1};
        for (int i = k; i < n; ++i) {
            currentSum += nums[i];
            currentSum -= nums[i - k];
            if (currentSum > maxPrefixSums[i - 1].first) {
                maxPrefixSums[i] = {currentSum, i};
            } else {
                maxPrefixSums[i] = maxPrefixSums[i - 1];
            }
        }

        currentSum = 0;
        for (int i = n - 1; i >= n - k; --i) {
            currentSum += nums[i];
        }
        maxSuffixSums[n - k] = {currentSum, n - k};
        for (int i = n - k - 1; i >= 0; --i) {
            currentSum += nums[i];
            currentSum -= nums[i + k];
            if (currentSum >= maxSuffixSums[i + 1].first) {
                maxSuffixSums[i] = {currentSum, i};
            } else {
                maxSuffixSums[i] = maxSuffixSums[i + 1];
            }
        }

        vector<int> cumulativeSums(n, 0);
        cumulativeSums[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            cumulativeSums[i] = cumulativeSums[i - 1] + nums[i];
        }

        int maxSum = 0;
        vector<int> maxSumIndex;

        for (int mid = k; mid <= n - 2 * k; ++mid) {
            int leftSum = maxPrefixSums[mid - 1].first;
            int midSum = cumulativeSums[mid + k - 1] - cumulativeSums[mid - 1];
            int rightSum = maxSuffixSums[mid + k].first;

            int totalSum = leftSum + midSum + rightSum;

            if (totalSum > maxSum) {
                maxSum = totalSum;
                int leftIndex = maxPrefixSums[mid - 1].second - k + 1;
                int midIndex = mid;
                int rightIndex = maxSuffixSums[mid + k].second;

                maxSumIndex = {leftIndex, midIndex, rightIndex};
            }
        }

        return maxSumIndex;
    }
};
