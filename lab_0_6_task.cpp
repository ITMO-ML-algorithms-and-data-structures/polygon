#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

void findUnique(const vector<int> nums, int S) {
    unordered_set<string> uniqueSubarrays;

    int length = nums.size();
    for (int sa_start = 0; sa_start < length; ++sa_start) {
        int sum = 0;
        for (int sa_end = sa_start; sa_end < length; ++sa_end) {
            sum += nums[sa_end];
            if (sum == S) {
                string subarray = "[";
                for (int digit_index = sa_start; digit_index <= sa_end; ++digit_index) {
                    subarray += to_string(nums[digit_index]);
                    if (digit_index < sa_end) subarray += ", ";
                }
                subarray += "]";

                uniqueSubarrays.insert(subarray);
            }
        }
    }

    cout << "Unique subarrays with the sum of " << S << ":\n";
    for (const string subarray : uniqueSubarrays) {
        cout << subarray << "\n";
    }
}


int main() {
    vector<int> nums = { 3, 6, 9, 23, 7, 2, 53 };
    int S = 32;

    findUnique(nums, S);

    return 0;
}

