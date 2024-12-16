#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>

template <typename T> 
std::vector<T> Sample(const int& k, std::vector<T> vector) {
    int length = static_cast<int> (vector.size());

    for (int i = 0; i < k; i++) {
        int idx = std::rand() % length;
        std::swap(vector[i], vector[idx]);
    }

    std::vector<T> sample(vector.begin(), vector.end() - length + k);
    return sample;
}

int main()
{
    std::vector<int> test1 = { 1, 100, 10, 2, 4, 3 };
    std::vector<int> result1 = Sample(5, test1);
    if (result1.size() == 5) std::cout << "Test 1 passed \n";
    else std::cout << "Test 1 fail \n";

    std::vector<int> test2 = { 5, 6, 7, 8 };
    std::vector<int> result2 = Sample(3, test2);
    if (result2.size() == 3) std::cout << "Test 2 passed \n";
    else std::cout << "Test 2 fail \n";

    std::vector<int> test3 = { 9 };
    std::vector<int> result3 = Sample(1, test3);
    if (result3.size() == 1) std::cout << "Test 3 passed \n";
    else std::cout << "Test 3 fail \n";

    std::vector<int> test4 = { 9, 3, 4, 5 };
    std::set<int> set;
    for (int i = 0; i < 10; i++) {
        set.insert(Sample(1, test4)[0]);
    }
    if (set.size() == 4) std::cout << "Test 4 passed \n";
    else std::cout << "Test 4 fail \n";
}
