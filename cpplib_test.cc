#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"


TEST(CPPLibTest, isomorph) {
  CPPLib cpplib;
  std::string input1 = "foo";
  std::string input2 = "egg";
  bool actual = cpplib.is_isomorph(input1, input2);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}

TEST(CPPLibTest, isomorph_with_nums) {
  CPPLib cpplib;
  std::string input1 = "smth23";
  std::string input2 = "pior56";
  bool actual = cpplib.is_isomorph(input1, input2);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}

TEST(CPPLibTest, isomorph_same_words) {
  CPPLib cpplib;
  std::string input1 = "isomorph";
  std::string input2 = "isomorph";
  bool actual = cpplib.is_isomorph(input1, input2);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}

TEST(CPPLibTest, isomorph_wrong) {
  CPPLib cpplib;
  std::string input1 = "isomorph";
  std::string input2 = "isomirph";
  bool actual = cpplib.is_isomorph(input1, input2);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}

TEST(CPPLibTest, isomorph_wrong_nums) {
  CPPLib cpplib;
  std::string input1 = "isomorph23";
  std::string input2 = "isomirph33";
  bool actual = cpplib.is_isomorph(input1, input2);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}

TEST(CPPLibTest, isomorph_dif_len) {
  CPPLib cpplib;
  std::string input1 = "one";
  std::string input2 = "onee";
  bool actual = cpplib.is_isomorph(input1, input2);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}


