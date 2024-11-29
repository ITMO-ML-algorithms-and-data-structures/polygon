#include <iostream>
#include <vector>

std::vector<std::vector<int>> findSublists( const std::vector<int>& nums, int target ) {
	std::vector<std::vector<int>> array;
	for (size_t i_1 = 0; i_1 < nums.size() - 4; ++i_1) {
		int sum_so_far = 0;
		for (size_t i_2 = i_1; i_2 < nums.size() - 3; ++i_2) {
			for (size_t i_3 = i_2 + 1; i_3 < nums.size() - 2; ++i_3) {
				for (size_t i_4 = i_3 + 1; i_4 < nums.size() - 1; ++i_4) {
					for (size_t i_5 = i_4 + 1; i_5 < nums.size(); ++i_5) {
						sum_so_far = nums[i_1] + nums[i_2] + nums[i_3] + nums[i_4] + nums[i_5];
						if (sum_so_far == target) {
							array.push_back({ static_cast<int>(i_1), static_cast<int>(i_2), static_cast<int>(i_3), static_cast<int>(i_4), static_cast<int>(i_5) });
						}
					}
				}
			}
		}
	}
	return array;
}

int main() {
	std::vector<int> nums = { 3, 4, -7, 1, 3, 3, 1, 4, 3, 1 };
	int target = 0;

	std::cout << "Input array: ";
	for (const auto& num : nums) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	auto mn_array = findSublists(nums, target);
	for (const auto& indices : mn_array) {
		std::cout << "[";
		for (size_t i = 0; i < indices.size(); ++i) {
			std::cout << indices[i];
			if (i < indices.size() - 1) {
				std::cout << ", ";
			}
		}
		std::cout << "]" << std::endl;
	}

	return 0;
}