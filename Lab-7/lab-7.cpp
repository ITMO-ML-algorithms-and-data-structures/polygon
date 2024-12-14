#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> maxnumber(vector<int>& nums1, vector<int>& nums2, int k, int& coun) {
		int m = nums1.size(), n = nums2.size();
		vector<int> nums;
		for (int i = max(0, k - n); i <= min(k, m); i++) {
			nums = max(nums, mergenums(maxnums(nums1, i, coun), maxnums(nums2, k - i, coun), coun));
		}

		coun += sizeof(m) + sizeof(n) + sizeof(nums);
		cout << coun << "bt\n";
		return nums;
	}

	vector<int> maxnums(vector<int>& nums, int k, int &coun) {
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

		coun += sizeof(i) + sizeof(end_nums);
		cout << coun << "bt\n";
		return end_nums;
	}

	vector<int> mergenums(vector<int> nums1, vector<int> nums2, int& coun) {
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

		coun += sizeof(nums);
		cout << coun << "bt\n";
		return nums;
	}
};

int main() {
	vector<int> nums1 = { 3, 4, 6, 5 };
	vector<int> nums2 = { 9, 1, 2, 5, 8, 3 };
	int k = 5;

	int coun = sizeof(nums1) + sizeof(nums2) + sizeof(k);
	cout << sizeof(nums1) + sizeof(nums2) << "\n";

	Solution x;
	vector<int> result = x.maxnumber(nums1, nums2, k, coun);

	coun += sizeof(result) + sizeof(x);


	for (int num : result) {
		cout << num << " ";
	} 

	cout << "\n" << coun + sizeof(coun) << "bt";
	return 0;
}