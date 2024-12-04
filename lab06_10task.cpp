#include <string>
#include <iostream>
#include <algorithm>

int expandAroundCenter(std::string s, int left, int right);

std::string longestPalindrome(std::string s) {
    if (s.empty()) {
        return "";
    }

    int start = 0;
    int end = 0;

    int n = s.length();
    for (int i = 0; i < n; i++) {
        int odd = expandAroundCenter(s, i, i);
        int even = expandAroundCenter(s, i, i + 1);
        int max_len = std::max(odd, even);

        if (max_len > end - start) {
            start = i - (max_len - 1) / 2;
            end = i + max_len / 2;
        }
    }

    return s.substr(start, end - start + 1);        
}

int expandAroundCenter(std::string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

void runTests() {
    std::cout << "test 1 result: " << longestPalindrome("babad") << std::endl;
    std::cout << "test 2 result: " << longestPalindrome("cbbd") << std::endl;
    std::cout << "test 3 result: " << longestPalindrome("a") << std::endl;
    std::cout << "test 4 result: " << longestPalindrome("ac") << std::endl;
}

int main() {
    runTests();
    return 0;
}
