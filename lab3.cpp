#include <iostream>
#include <string>

std::string compress_string(const std::string& str) {
    std::string compressed_str;
    int length = str.length();
    compressed_str.reserve(length);
    int count = 1;
    
    for (int i = 1; i <= length; ++i) {
        if (i < length && str[i] == str[i - 1]) {
            ++count;
        } else {
            compressed_str += str[i - 1];
            if (count > 1) {
                compressed_str += std::to_string(count);
            }
            count = 1;
        }
    }
    
    return compressed_str;
}

int main() {
    std::string input = "aaabbccdsccssaa";
    std::string output = compress_string(input);
    std::cout << output;
}
