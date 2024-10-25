#include "../lab.cpp"
#include <gtest/gtest.h>
#include <vector>
#include <unordered_set>

TEST(DeathKTest, FunctionCall) {
    EXPECT_THROW(sample<int>({1, 2, 3, 4, 5}, 7), std::runtime_error);
}

TEST(CheckAllValuesTest, FunctionCall) {
    std::vector<int> result = sample<int>({1, 2, 3, 4, 5}, 5);
    std::set<int> expected = {1, 2, 3, 4, 5};
    ASSERT_EQ(std::set<int>(result.begin(), result.end()), expected);
}

TEST(CheckLengthOfResultTest, FunctionCall) {
    ASSERT_EQ(sample<int>({1, 2, 3, 4, 5}, 4).size(), 4);
}

TEST(ShuffleTest, FunctionCall) {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> prev_array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    shuffle(array);
    std::set<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_EQ(std::set<int>(array.begin(), array.end()), expected);
    ASSERT_NE(array, prev_array);
}
