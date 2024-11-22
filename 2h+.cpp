// Найти количество пар скобок (открытая и закрытая), корректно расположенных в строке
// tests
// (()) -> 2
// (() -> 1
// ()) -> Not correct bracket sequence
// () -> 1
// ( -> Not correct bracket sequence
// ) -> Not correct bracket sequence

#include <iostream>
#include <vector>
#include <string>


int main() {
    std::string input;
    int count_p = 0;
    int count_s = 0;
    std::vector<char> vec;
    std::cin >> input;
    for (const char & c : input) {
        vec.push_back(c);
    }

    for (const auto & c : vec) {
        if (c == '(' || c == '[' || c == '{') {
            count_p++;
        } else if (c == ')' || c == ']' || c == '}') {
            count_s--;
        }
    } 


    if (count_p + count_s == 0) {
        std::cout << count_p << '\n';
    } else {
        std::cout << "Not correct bracket sequence" << '\n';
    }
}