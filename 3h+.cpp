// Найти все уникальные пары чисел в массиве, сумма которых равна заданному числу S
// tests 
// 6 {1, 2, 3, 4, 5, 6} -> {1, 5}, {2, 4}
// 3 {1, 2, 3} -> {1, 2}
// 4 {1, 2, 3, 4} -> {1, 3}

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>

int main() {
    std::vector<int> vec;
    int s = 0;
    std::cin >> s;

    int num = 0;
    while (std::cin >> num) {
        vec.push_back(num);
    }

    std::unordered_set<int> seen;
    std::vector<std::pair<int, int>> result;

    for (const int& num : vec) {
        int complement = s - num;
        if (seen.find(complement) != seen.end()) {
            result.push_back({std::min(num, complement), std::max(num, complement)});
        }
        seen.insert(num);
    }

    for (const auto& pair : result) {
        std::cout << pair.first << " " << pair.second << '\n';
    }
}
