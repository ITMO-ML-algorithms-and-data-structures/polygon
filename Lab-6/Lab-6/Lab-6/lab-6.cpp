#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
public:
	int findRotateSteps(std::string ring, std::string key) {
		std::unordered_map<char, std::vector<int>> ltr_indexes; // 40 байт
		// std::cout << sizeof(ltr_indexes) << std::endl;
		ltr_indexes['#'].push_back(0);
		int ln = ring.size(); // 4 байта
		// std::cout << sizeof(ln) << std::endl;

		for (int idx = 0; idx < ln; idx++) {
			ltr_indexes[ring[idx]].push_back(idx);
		} // f(n)

		std::vector<int> l_lens(ln, 0); // 16 байт
		// std::cout << sizeof(l_lens) << std::endl;

		char prev_ltr = '#'; // 1 байт
		for (char ltr : key) {
			for (int pos : ltr_indexes[ltr]) {
				std::vector<int> all_variants; // 16 байт
				// std::cout << sizeof(all_variants) << std::endl;

				for (int prev_pos : ltr_indexes[prev_ltr]) {
					int clk_w = std::abs(prev_pos - pos); // 4 байта
					// std::cout << sizeof(clk_w) << std::endl;
					int a_clk = ln - clk_w; // 4 байта
					// std::cout << sizeof(a_clk) << std::endl;
					all_variants.push_back(std::min(clk_w, a_clk) + l_lens[prev_pos]);
				} // f(n^3)

				l_lens[pos] = *std::min_element(all_variants.begin(), all_variants.end());
			} 
			prev_ltr = ltr;
		}

		int min_len = 9 * 10000; // 4 байта
		// std::cout << sizeof(min_len) << std::endl;

		for (int pos : ltr_indexes[prev_ltr]) {
			std::vector<int> numbers{ min_len, l_lens[pos] };
			min_len = *std::min_element(numbers.begin(), numbers.end());
		} // f(n)

		std::cout << sizeof(min_len) + sizeof(l_lens) + sizeof(ltr_indexes) + sizeof(ln) + 1 << std::endl;

		return min_len + key.size();
	}
};

int main() {
	Solution x;
	std::cout << x.findRotateSteps("aedbcdgb", "abc") << std::endl;
	return 0;
}