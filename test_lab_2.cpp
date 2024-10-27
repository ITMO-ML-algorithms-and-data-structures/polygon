#include <gtest/gtest.h>

// Функция remove_Duplicates
int remove_Duplicates(int arr[], int n) {
    int new_Size = n; for (int i = 0; i < new_Size; ++i) {
        for (int j = i + 1; j < new_Size; ++j) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < new_Size - 1; ++k) {
                    arr[k] = arr[k + 1];
                }
                --new_Size;
                --j;
            }
        }
    }

    return new_Size;
}

// Тесты
TEST(RemoveDuplicatesTest, HandlesDuplicates) {
    int arr[] = { 1, 2, 3, 1, 2, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int new_Size = remove_Duplicates(arr, n);
    
    EXPECT_EQ(new_Size, 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}

TEST(RemoveDuplicatesTest, HandlesNoDuplicates) {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int new_Size = remove_Duplicates(arr, n);
    
    EXPECT_EQ(new_Size, 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}

TEST(RemoveDuplicatesTest, HandlesAllDuplicates) {
    int arr[] = { 1, 1, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int new_Size = remove_Duplicates(arr, n);
    
    EXPECT_EQ(new_Size, 1);
    EXPECT_EQ(arr[0], 1);
}

TEST(RemoveDuplicatesTest, HandlesEmptyArray) {
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);
    int new_Size = remove_Duplicates(arr, n);
    
    EXPECT_EQ(new_Size, 0);
}

TEST(RemoveDuplicatesTest, HandlesSingleElement) {
    int arr[] = { 42 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int new_Size = remove_Duplicates(arr, n);
 EXPECT_EQ(new_Size, 1);
    EXPECT_EQ(arr[0], 42);
}

// Запуск тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



g++ -o test_unique_values test_unique_values.cpp -lgtest -lpthread
./test_unique_values