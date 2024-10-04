// да незнаю я как gtest пользоваться
#include <cassert>

#include "label_encoder.cpp"

void test_case_1() {
    LabelEncoder<int> encoder;
    std::vector<std::string> categories = {"Orange", "Red", "Green", "Orange"};
    encoder.fit(categories);

    std::vector<int> encoded = encoder.transform(categories);
    std::vector<std::string> decoded = encoder.inverse_transform(encoded);

    assert(categories == decoded);
    std::cout << "Test case 1 passed!" << std::endl;
}

void test_case_2() {
    LabelEncoder<int> encoder;
    std::vector<std::string> categories = {"dog", "cat", "dog", "bird"};
    encoder.fit(categories);

    std::vector<int> encoded = encoder.transform(categories);
    std::vector<std::string> decoded = encoder.inverse_transform(encoded);

    assert(categories == decoded);
    std::cout << "Test case 2 passed!" << std::endl;
}

void test_case_3() {
    LabelEncoder<int> encoder;
    std::vector<std::string> categories = {"red", "blue", "green", "red", "blue"};
    encoder.fit(categories);

    std::vector<int> encoded = encoder.transform(categories);
    std::vector<std::string> decoded = encoder.inverse_transform(encoded);

    assert(categories == decoded);
    std::cout << "Test case 3 passed!" << std::endl;
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();

    std::cout << "All test cases passed!" << std::endl;
    return 0;
}