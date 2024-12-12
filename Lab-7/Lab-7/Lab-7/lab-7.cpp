#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> maxnumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int m = nums1.size(), n = nums2.size();
		vector<int> nums;
		for (int i = max(0, k - n); i <= min(k, m); i++) {
			nums = max(nums, mergenums(maxnums(nums1, i), maxnums(nums2, k - i)));
		}
		return nums;
	}

	vector<int> maxnums(vector<int>& nums, int k) {
		int i = (int)nums.size() - k;
		vector<int> end_nums;
		for (int num : nums) {
			while (i > 0 && end_nums.size() > 0 && end_nums.back() < num) {
				end_nums.pop_back();
				i--;
			}
			end_nums.push_back(num);
		}
		end_nums.resize(k);
		return end_nums;
	}

	vector<int> mergenums(vector<int> nums1, vector<int> nums2) {
		vector<int> nums;
		while ( nums1.size() > 0 || nums2.size() > 0 ) {
			if (nums1 > nums2) {
				vector<int> &mas = nums1;
				nums.push_back(mas[0]);
				mas.erase(mas.begin());
			}
			else {
				vector<int> &mas = nums2;
				nums.push_back(mas[0]);
				mas.erase(mas.begin());
			}
			
		}
		return nums;
	}
};

int main() {
	vector<int> nums1 = { 3, 4, 6, 5 };
	vector<int> nums2 = { 9, 1, 2, 5, 8, 3 };
	int k = 5;
	Solution x;
	vector<int> result = x.maxnumber(nums1, nums2, k);
	for (int num : result) {
		cout << num << " ";
	}
	return 0;
}