#include <gtest/gtest.h>
#include <vector>




extern void brickSort(std::vector<int>& arr);
extern void shellSort(std::vector<int>& arr);
extern void countingSort(std::vector<int>& arr);


// Тесты для brickSort
TEST(BrickSortTest, EmptyVector) {
    std::vector<int> emptyVec;
    brickSort(emptyVec);
    EXPECT_EQ(emptyVec.size(), 0);
}


TEST(BrickSortTest, SingleElement) {
    std::vector<int> singleVec{42};
    brickSort(singleVec);
    EXPECT_EQ(singleVec.size(), 1);
    EXPECT_EQ(singleVec[0], 42);
}


TEST(BrickSortTest, SortedVector) {
    std::vector<int> sortedVec{1, 2, 3, 4, 5};
    brickSort(sortedVec);
    EXPECT_EQ(sortedVec, (std::vector<int>{1, 2, 3, 4, 5}));
}


TEST(BrickSortTest, ReverseSortedVector) {
    std::vector<int> reverseSortedVec{5, 4, 3, 2, 1};
    brickSort(reverseSortedVec);
    EXPECT_EQ(reverseSortedVec, (std::vector<int>{1, 2, 3, 4, 5}));
}


TEST(BrickSortTest, RandomVector) {
    std::vector<int> randomVec{34, 2, 78, 1, 56, 99, 23, 12};
    brickSort(randomVec);
    EXPECT_EQ(randomVec, (std::vector<int>{1, 2, 12, 23, 34, 56, 78, 99}));
}


// Тесты для shellSort
TEST(ShellSortTest, EmptyVector) {
    std::vector<int> emptyVec;
    shellSort(emptyVec);
    EXPECT_EQ(emptyVec.size(), 0);
}


TEST(ShellSortTest, SingleElement) {
    std::vector<int> singleVec{42};
    shellSort(singleVec);
    EXPECT_EQ(singleVec.size(), 1);
    EXPECT_EQ(singleVec[0], 42);
}


TEST(ShellSortTest, SortedVector) {
    std::vector<int> sortedVec{1, 2, 3, 4, 5};
    shellSort(sortedVec);
    EXPECT_EQ(sortedVec, (std::vector<int>{1, 2, 3, 4, 5}));
}


TEST(ShellSortTest, ReverseSortedVector) {
    std::vector<int> reverseSortedVec{5, 4, 3, 2, 1};
    shellSort(reverseSortedVec);
    EXPECT_EQ(reverseSortedVec, (std::vector<int>{1, 2, 3, 4, 5}));
}


TEST(ShellSortTest, RandomVector) {
    std::vector<int> randomVec{34, 2, 78, 1, 56, 99, 23, 12};
    shellSort(randomVec);
    EXPECT_EQ(randomVec, (std::vector<int>{1, 2, 12, 23, 34, 56, 78, 99}));
}


// Тесты для countingSort
TEST(CountingSortTest, EmptyVector) {
    std::vector<int> emptyVec;
    countingSort(emptyVec);
    EXPECT_EQ(emptyVec.size(), 0);
}


TEST(CountingSortTest, SingleElement) {
    std::vector<int> singleVec{42};
    countingSort(singleVec);
    EXPECT_EQ(singleVec.size(), 1);
    EXPECT_EQ(singleVec[0], 42);
}


TEST(CountingSortTest, SortedVector) {
    std::vector<int> sortedVec{1, 2, 3, 4, 5};
    countingSort(sortedVec);
    EXPECT_EQ(sortedVec, (std::vector<int>{1, 2, 3, 4, 5}));
}


TEST(CountingSortTest, ReverseSortedVector) {
    std::vector<int> reverseSortedVec{5, 4, 3, 2, 1};
    countingSort(reverseSortedVec);
    EXPECT_EQ(reverseSortedVec, (std::vector<int>{1, 2, 3, 4, 5}));
}


TEST(CountingSortTest, RandomVector) {
    std::vector<int> randomVec{34, 2, 78, 1, 56, 99, 23, 12};
    countingSort(randomVec);
    EXPECT_EQ(randomVec, (std::vector<int>{1, 2, 12, 23, 34, 56, 78, 99}));
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
