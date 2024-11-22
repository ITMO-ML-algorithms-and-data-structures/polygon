// Найти все уникальные подмассивы, сумма которых равна заданному числу S, вывести индексы подмассивов
// tests
// 3 {1, 2, 3, 0} -> {0, 1}, {0, 2}
// 3 {1, 2, 3, 0, 0} -> {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}

#include <iostream>
#include <unordered_map>
#include <vector>



int main() {
    // std::vector<int> vec = {1, 2, 3, 0};
    // int k = 3;

    int k = 0;
    std::cin >> k;

    std::vector<int> vec;
    int num = 0;
    while (std::cin >> num) {
        vec.push_back(num);
    }

    std::unordered_map<int, int> mp;
    mp[0] = 1;

    std::unordered_map<int, int> output;

    int counter = 0;
    for (const auto& num : vec) {
        counter += num;
        if (mp.find(counter - k) != mp.end()) {
            output[counter - k] = k;
        }
        mp[counter]++;
    }

    for (const auto& [key, value] : output) {
        std::cout << key << " " << value << '\n';
    }
    
   
}
