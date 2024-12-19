#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Функция постороения мксимальной подпоследовтельности длины k
vector<int> getMaxSubsequence(vector<int>& nums, int k) {
    vector<int> result;
    int drop = nums.size() - k;
    for (int num : nums) {
        while (!result.empty() && drop > 0 && result.back() < num) {
            result.pop_back();
            drop--;
        }
        if (result.size() < k) {
            result.push_back(num);
        } else {
            drop--;
        }
    }
    return result;
}

// Функция объединения массивов
vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    auto it1 = nums1.begin(), it2 = nums2.begin();
    while (it1 != nums1.end() || it2 != nums2.end()) {
        if (lexicographical_compare(it1, nums1.end(), it2, nums2.end())) {
            result.push_back(*it2);
            it2++;
        } else {
            result.push_back(*it1);
            it1++;
        }
    }
    return result;
}

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;

        // Полный перебор возможных разбиений числа k на две части: nums1, nums2
        for (int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size()); i++) {
            vector<int> subseq1 = getMaxSubsequence(nums1, i);
            vector<int> subseq2 = getMaxSubsequence(nums2, k - i);
            vector<int> candidate = merge(subseq1, subseq2);
            if (lexicographical_compare(best.begin(), best.end(), candidate.begin(), candidate.end())) {
                best = candidate;
            }
        }
        return best;
    }
};