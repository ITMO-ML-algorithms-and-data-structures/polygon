#include <iostream>
#include <string>

std::string compress_string(const std::string& str) {
    std::string compressed_str; //O(1) - выделение памяти
    int length = str.length(); //O(1) + O(1) - выделение памяти и присваивание
    compressed_str.reserve(length); //O(1)
    int count = 1; //O(1) + O(1) - выделение памяти и присваивание
    
    for (int i = 1; i <= length; ++i) { //проход по всем элементам, кроме первого, поэтому O(n-1)
        if (i < length && str[i] == str[i - 1]) {
            ++count; //O(1) - присваивание
        } else {
            compressed_str += str[i - 1]; //O(1) + O(1) - присваивание и выбор элемента
            if (count > 1) {
                compressed_str += std::to_string(count); //O(1) - присваивание, std::to_string() - O(log(count)), если значение count небольшое, то сложность можно считать за O(1)
            }
            count = 1; //O(1) - присваивание
        }
    }
    
    return compressed_str; //O(1) - возврат значения
}

int main() {
    std::string input = "aaabbccdsccssaa";
    std::string output = compress_string(input);
    std::cout << output;
}
