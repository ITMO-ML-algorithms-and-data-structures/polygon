#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"
//
TEST(CPPLibTest, classificate_smth) {
  CPPLib cpplib;
  std::vector<double> input_array = {1.0, 2.0, 10.0, 11.0, 20.0, 22.0, 45.0, 46.0, 15.5, 100.0, 101.0, 2000.0, 5000.0, 2.5};
  int clusters_quantity = 6;
  std::vector<std::vector<double>> actual = cpplib.cluster_array(input_array, clusters_quantity);
  std::vector<std::vector<double>> expected = {{1.0, 2.0, 2.5}, {10.0, 11.0, 20.0, 22.0, 15.5}, {45.0, 46.0}, {100.0, 101.0}, {2000.0}, {5000.0}};
  EXPECT_EQ(expected, actual);
}


TEST(CPPLibTest, classificate_smth2) {
  CPPLib cpplib;
  std::vector<double> input_array = 
  int clusters_quantity = 7;
  std::vector<std::vector<double>> actual = cpplib.cluster_array(input_array, clusters_quantity);
  std::vector<std::vector<double>> expected = {{1.0, 2.0, 2.5}, {10.0, 11.0, 20.0, 22.0, 15.5}, {45.0, 46.0}, {100.0, 101.0}, {2000.0}, {5000.0}, {}};
  EXPECT_EQ(expected, actual);


TEST(CPPLibTest, classificate_smth3) {
  CPPLib cpplib;
  std::vector<double> input_array = {1.5, 2.6, 72.0, 87.0, 56.0, 19.0, 20.0, 46.0, 45.0, 100.0, 101.0, 2.5, 3.5};
  int clusters_quantity = 7;
  std::vector<std::vector<double>> actual = cpplib.cluster_array(input_array, clusters_quantity);
  std::vector<std::vector<double>> expected = {{1.5, 2.6, 2.5, 3.5}, {72.0}, {87.0}, {56.0}, {19.0, 20.0}, {46.0, 45.0}, {100.0, 101.0}};
  EXPECT_EQ(expected, actual);





