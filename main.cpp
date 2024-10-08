#include <iostream> // 0
#include <fstream> // 0
#include <vector> // 0
#include <string> // 0

std::vector<std::string> RemoveDuplicates(std::vector<std::string> input) { // n * m
    std::vector<std::string> output; // output 0
    for(const auto& str : input) { // n * (1 + m)
        std::string result; // 0
        for(char ch : str) { // 1
            if(result.find(ch) == std::string::npos) {
                result += ch;
            }
        }
        output.push_back(result);
    }
    return output; // 0
}

void Test(const std::vector<std::string>& input, const std::vector<std::string>& expected, int test_number) {
    std::vector<std::string> result = RemoveDuplicates(input);

    if(result == expected) {
        std::cout << "Тест " << test_number << " прошел!" << std::endl;
    } else {
        std::cout << "Тест " << test_number << " провален!" << std::endl;
        std::cout << "Expected: ";
        for(const auto& str : expected) {
            std::cout << str << " ";
        }
        std::cout << std::endl;

        std::cout << "Got: ";
        for(const auto& str : result) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ifstream file(R"(C:\Users\227ad\CLionProjects\LAB1\test_set.txt)");
    std::vector<std::string> input; // 24
    std::string line;
    while(std::getline(file, line)) { // m
        input.push_back(line); // n * m
    }
    file.close();
    std::vector<std::string> output = RemoveDuplicates(input); //
    std::cout << "Обработанные строки:" << std::endl; // 8
    for(const auto& str : output) { // m байт
        std::cout << str << std::endl; // 0
    }

    // Тест 1: простой случай
    Test({"112345", "12345"}, {"12345", "12345"}, 1);

    // Тест 2: все символы разные
    Test({"abcd", "efgh"}, {"abcd", "efgh"}, 2);

    // Тест 3: все символы одинаковые
    Test({"aaaa", "bbbb"}, {"a", "b"}, 3);

    // Тест 4: строка с пробелами
    Test({"a a a", "b b b"}, {"a ", "b "}, 4);

    // Тест 5: пустая строка
    Test({""}, {""}, 5);

    // Тест 6: строка с повторяющимися символами
    Test({"abcabcabc", "xyzxyz"}, {"abc", "xyz"}, 6);

}

