#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> removeDuplicates(std::vector<int>& numbers) {
    std::vector<int> result;

    for (int i = 0; i < numbers.size(); i++) {
        bool isDublicate = false;
        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                isDublicate = true;
                break;
            }
        }
        if (!isDublicate) {
            result.push_back(numbers[i]);
        }
    }
    return result;
}

void testRemoveDuplicates() {
    std::vector<int> test1 = { 1, 2, 3, 1 };
    std::vector<int> expected1 = { 1, 2, 3 };
    assert(removeDuplicates(test1) == expected1);

    std::vector<int> test2 = { 1, 1, 1, 1 };
    std::vector<int> expected2 = { 1 };
    assert(removeDuplicates(test2) == expected2);

    std::vector<int> test3 = { 5, 4, 3, 2, 1 };
    std::vector<int> expected3 = { 5, 4, 3, 2, 1 };
    assert(removeDuplicates(test3) == expected3);

    std::vector<int> test4 = { 1, 2, 3, 4, 5 };
    std::vector<int> expected4 = { 1, 2, 3, 4, 5 };
    assert(removeDuplicates(test4) == expected4);

    std::vector<int> test5 = { };
    std::vector<int> expected5 = { };
    assert(removeDuplicates(test5) == expected5);

    std::vector<int> test6 = { 10, 20, 10, 30, 20, 10 };
    std::vector<int> expected6 = { 10, 20, 30 };
    assert(removeDuplicates(test6) == expected6);

    std::vector<int> test7 = { 1, 2, 1, 3, 2, 4 };
    std::vector<int> expected7 = { 1, 2, 3, 4 };
    assert(removeDuplicates(test7) == expected7);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testRemoveDuplicates();
    return 0;
}
