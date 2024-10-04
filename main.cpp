#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> label_encoder(const std::vector<std::string> &arr) {
    std::unordered_map<std::string, int> dict;
    std::vector<int> answer;
    int current_number = 1;
    for (const std::string &word : arr) {
        if (dict.find(word) == dict.end()) {
            dict[word] = current_number++;
        }
        answer.push_back(dict[word]);
    }

    return answer;
}

void test() {
    // 1 test base
    std::vector<std::string> arr = {"Orange", "Red", "Green", "Orange"};
    std::vector<int> ans = label_encoder(arr);

    if (ans == std::vector<int>{1, 2, 3, 1}) {
        std::cout << "Test 1 passed!" << std::endl;
    } else {
        std::cout << "Test 1 failed!";
    }

    // 2 test similar words
    arr = {"Red", "Red", "Red", "Red"};
    ans = label_encoder(arr);

    if (ans == std::vector<int>{1, 1, 1, 1}) {
        std::cout << "Test 2 passed!" << std::endl;
    } else {
        std::cout << "Test 2 failed!";
    }

    // 2 test similar words
    arr = {"Red", "Red", "Green", "Hello", "Red"};
    ans = label_encoder(arr);

    if (ans == std::vector<int>{1, 1, 2, 3, 1}) {
        std::cout << "Test 3 passed!" << std::endl;
    } else {
        std::cout << "Test 3 failed!";
    }
}

int main() {
    test();
    return 0;
}