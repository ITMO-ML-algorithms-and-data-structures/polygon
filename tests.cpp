#include <gtest/gtest.h>
#include <fstream>
#include <vector>
#include <string>
#include "label_encoder.h"


void create_test_file(const std::string& filename, const std::string& content) {
    std::ofstream testFile(filename);
    testFile << content;
    testFile.close();
}

// Тест для базового случая
TEST(PolygonLabelEncoderTests, BasicEncoding) {
    create_test_file("test_input_basic.txt", "apple\nbanana\napple\norange\nbanana\n");

    std::ifstream inputFile("test_input_basic.txt");
    std::vector<int> expected = {1, 2, 1, 3, 2};

    EXPECT_EQ(label_encode(inputFile), expected);
}

// Тест для уникальных строк
TEST(PolygonLabelEncoderTests, UniqueStrings) {
    create_test_file("test_input_unique.txt", "cat\ndog\nfish\n");

    std::ifstream inputFile("test_input_unique.txt");
    std::vector<int> expected = {1, 2, 3};

    EXPECT_EQ(label_encode(inputFile), expected);
}

// Тест для пустого ввода
TEST(PolygonLabelEncoderTests, EmptyInput) {
    create_test_file("test_input_empty.txt", "");

    std::ifstream inputFile("test_input_empty.txt");
    std::vector<int> expected = {};

    EXPECT_EQ(label_encode(inputFile), expected);
}

// Тест для одной строки
TEST(PolygonLabelEncoderTests, SingleInput) {
    create_test_file("test_input_single.txt", "hello\n");

    std::ifstream inputFile("test_input_single.txt");
    std::vector<int> expected = {1};

    EXPECT_EQ(label_encode(inputFile), expected);
}

// Тест для одинаковых строк
TEST(PolygonLabelEncoderTests, RepeatedStrings) {
    create_test_file("test_input_repeated.txt", "hello\nhello\nhello\nhello\n");

    std::ifstream inputFile("test_input_repeated.txt");
    std::vector<int> expected = {1, 1, 1, 1};

    EXPECT_EQ(label_encode(inputFile), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
