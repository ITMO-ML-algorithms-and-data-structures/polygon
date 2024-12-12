#include <iostream>
#include <chrono>
#include <vector>

std::vector<std::vector<int>> findSublists( const std::vector<int>& nums, int target, int& coun ) {
	std::vector<std::vector<int>> array;
	for (size_t i_1 = 0; i_1 < nums.size() - 4; i_1++) {
		int sum_so_far = 0;
		for (size_t i_2 = i_1 + 1; i_2 < nums.size() - 3; i_2++) {
			for (size_t i_3 = i_2 + 1; i_3 < nums.size() - 2; i_3++) {
				for (size_t i_4 = i_3 + 1; i_4 < nums.size() - 1; i_4++) {
					for (size_t i_5 = i_4 + 1; i_5 < nums.size(); i_5++) {
						sum_so_far = nums[i_1] + nums[i_2] + nums[i_3] + nums[i_4] + nums[i_5];
						if (sum_so_far == target) {
							array.push_back({ static_cast<int>(i_1), static_cast<int>(i_2), static_cast<int>(i_3), static_cast<int>(i_4), static_cast<int>(i_5) });
						}
					}
				}
			}
		}
	}

	coun += sizeof(array);

	std::cout << coun << "bt\n";
	return array;
}

bool checkout(std::vector<std::vector<int>> mn_array, std::vector<int> nums, int& coun) {
	bool flag = true;
	coun += sizeof(flag);

	for (const auto& indices : mn_array) {
		// std::cout << "[";
		int sum_on = 0;
		for (size_t i = 0; i < indices.size(); ++i) {
			sum_on += nums[indices[i]];
			// std::cout << indices[i];
			if (i < indices.size() - 1) {
				// std::cout << ", ";
			}
		}
		// std::cout << "]" << std::endl;

		if (sum_on != 0)
			flag = false;
	}

	return flag;
}

void test1(int coun) {
	int target = 0;
	auto start = std::chrono::steady_clock::now();

	std::vector<int> nums = { -2, 3, 4, -7, 1, 2, 3, 3, 1, 4, 0, 1, 2, 7, -3, 0 };              
	auto mn_array = findSublists(nums, target, coun);
	//struct tm *now = localtime(&mytime);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Time: " << elapsed.count() << "\n";

	if (checkout(mn_array, nums, coun))
		std::cout << "Test passed\n";
	else
		std::cout << "Test not passed\n";

	coun += sizeof(nums) + sizeof(mn_array) + sizeof(target) + sizeof(coun);
	std::cout << coun << "bt\n";
}

void test2(int coun) {
	int target = 0;
	std::vector<int> nums = { 1, -1, 2, -2, 0, 3, -3, 2, -3, 2, 3, -5 };             
	auto mn_array = findSublists(nums, target, coun);

	if (checkout(mn_array, nums, coun))
		std::cout << "Test passed\n";
	else
		std::cout << "Test not passed\n";

	coun += sizeof(nums) + sizeof(mn_array) + sizeof(target) + sizeof(coun);
	std::cout << coun << "bt\n";
}

int main() {
	int coun = 0;
	// std::vector<int> nums = { 3, 4, -7, 1, 3, 3, 1, 4, 3, 1 };
	// int target = 0;

	//std::cout << "Input array: ";
	//for (const auto& num : nums) {
	//	std::cout << num << " ";
	//}
	test1(coun);
	test2(coun);

	// std::cout << coun << "bt";

	return 0;
}