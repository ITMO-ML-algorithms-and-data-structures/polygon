// Найти все пары чисел в массиве, разность которых равна заданному числу
// tests
// 3 {1, 2, 3, 4, 5, 6} -> {1, 4}, {2, 5}, {3, 6}
// 1 {1, 2, 3, 4, 5, 6} -> {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

int main() {
    std::vector<std::pair<int, int>> out;
    // std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    int k = 0;
    std::cin >> k;

    std::vector<int> vec
    int n = 0;
    while (std::cin >> n) {
        vec.push_back(n);
    }

    std::unordered_map<int, int> mp;
    for (size_t i = 0; i < vec.size(); i++) {
        mp[vec[i]] = i;
    }

    for (const auto & c : vec) {
        if (mp.find(c - k) != mp.end()) {
            out.push_back({c, c - k});
        }
    }

    for (const auto& p : out) {
        std::cout << p.first << " " << p.second << '\n';
    }


}
