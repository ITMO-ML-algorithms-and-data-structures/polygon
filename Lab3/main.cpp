#include <iostream>
#include <array>
#include <set>
#include <random>
#include <vector>


int main() {
    int k = 4;
    std::array<int, 13> input_arr = {1, 2, 3, 7, 3, 2, 1, 1, 4, 8, 11, 10, 8};
    std::set<int> unique_values;
    for (int n : input_arr)
    {
        unique_values.insert(n);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> res;
    auto it = unique_values.begin();
    for (int i = 0; i < k; i++)
    {
        std::uniform_int_distribution<> distrib(0, unique_values.size()-1);
        int random_index = distrib(gen);
        auto it = unique_values.begin();
        std::advance(it, random_index);
        res.push_back(*it);
        unique_values.erase(*it);
    }
    for (int n : res)
    {
        std::cout << n << ' ';
    }
    return 0;
}
