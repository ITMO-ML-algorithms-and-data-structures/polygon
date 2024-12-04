//53. maximum subarray
#include <vector>
#include <iostream>
#include <algorithm>

int maxSubArray(std::vector<int>& nums) {
    int res = nums[0];
    int total = 0;

    for (int n : nums) {
        if (total < 0) {
            total = 0;
        }

        total += n;
        res = std::max(res, total);
    }

    return res;        
}

// Тесты
void runTests() {
    std::vector<int> test1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "test 1 result: " << maxSubArray(test1) << std::endl;

    std::vector<int> test2 = {1};
    std::cout << "test 2 result: " << maxSubArray(test2) << std::endl;

    std::vector<int> test3 = {5, 4, -1, 7, 8};
    std::cout << "test 3 result: " << maxSubArray(test3) << std::endl;

    std::vector<int> test4 = {-1, -2, -3, -4};
    std::cout << "test 4 result: " << maxSubArray(test4) << std::endl;
}

int main() {
    runTests();
    return 0;
}


 