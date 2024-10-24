#include "src/lib/lab3.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"


TEST(CPPLibTest, count_words_list_smth) {
  CPPLib cpplib;
  std::vector<std::string> inputs = {"orange", "apple", "orange", "sht", "sht", "sht"};
  std::vector<int> actual = cpplib.output_vector(inputs);
  std::vector<int> expected = {2, 1, 2, 3, 3, 3};
  EXPECT_EQ(expected, actual);
}

TEST(CPPLibTest, count_words_split_words) {
  CPPLib cpplib;
  std::vector<std::string> inputs = {"orange", "orange", "orange", "sht", "sht", "sht"};
  std::vector<int> actual = cpplib.output_vector(inputs);
  std::vector<int> expected = {3, 3, 3, 3, 3, 3};
  EXPECT_EQ(expected, actual);
}

TEST(CPPLibTest, count_words_large_input_data) {
  CPPLib cpplib;
  std::vector<std::string> inputs = {"if", "i", "were", "in", "the", "same", "situation", "i", "would", "do", "it", "as", "soon", "as", "possible" };
  std::vector<int> actual = cpplib.output_vector(inputs);
  std::vector<int> expected = {1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1};
  EXPECT_EQ(expected, actual);
}

TEST(CPPLibTest, count_words_list) {
  CPPLib cpplib;
  std::vector<std::string> inputs = {"dont", "know", "what", "tests", "to", "add"};
  std::vector<int> actual = cpplib.output_vector(inputs);
  std::vector<int> expected = {1, 1, 1, 1, 1, 1};
  EXPECT_EQ(expected, actual);
}

TEST(CPPLibTest, count_words_same_words) {
  CPPLib cpplib;
  std::vector<std::string> inputs = {"i", "i", "i", "i", "i", "i"};
  std::vector<int> actual = cpplib.output_vector(inputs);
  std::vector<int> expected = {6, 6, 6, 6, 6, 6};
  EXPECT_EQ(expected, actual);
}
