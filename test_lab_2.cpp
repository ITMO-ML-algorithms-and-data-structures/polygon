#include <gtest/gtest.h>
#include <vector>

TEST(GetUniqueValuesTest, HandlesUniqueValues) {
    std::vector<int> input = {1, 2, 3, 1};
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(getUniqueValues(input), expected);
}
//проверяет стандартный случай с несколькими уникальными значениями


TEST(GetUniqueValuesTest, HandlesAllDuplicates) {
    std::vector<int> input = {2, 2, 2, 2};
    std::vector<int> expected = {2};
    EXPECT_EQ(getUniqueValues(input), expected);
}
//проверяет случай, когда все элементы одинаковые


TEST(GetUniqueValuesTest, HandlesEmptyInput) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    EXPECT_EQ(getUniqueValues(input), expected);
}
//проверяет функцию на пустом векторе


TEST(GetUniqueValuesTest, HandlesAlreadyUnique) {
    std::vector<int> input = {5, 6, 7};
    std::vector<int> expected = {5, 6, 7};
    EXPECT_EQ(getUniqueValues(input), expected);
}
//проверяет случай, когда все элементы уже уникальны


TEST(GetUniqueValuesTest, HandlesMixedInput) {
    std::vector<int> input = {3, 1, 2, 3, 1};
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(getUniqueValues(input), expected);
}
//проверяет случай с перемешанными значениями и дубликатами



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


g++ -o test_unique_values test_unique_values.cpp -lgtest -lpthread
./test_unique_values