#include <bits/stdc++.h> 
#include <vector>
#include <time.h> 
#include <algorithm>

using namespace std;

vector <short int> rand_shuffle(int n, vector <short int> numbers){

    srand(time(0)); // settings for random generate
    
    //generate a random index and swap the element with that index with the last available for swapping element
    //the element was swapped, so it won't be available for swapping in the future (n - i - 1 is the max index that available for swapping)

    for (int i = 0; i != n - 1; i++){

        int index4swap = rand() % (n - i + 1); // O(1) 4 bytes
        swap(numbers[n - i - 1], numbers[index4swap]); // O(1)

    }

    return numbers;

}
//time O(n)
//memory 4 + 2 * array_size (short int = 2 bytes) 

#include <gtest/gtest.h>

TEST(Tests, UniqueElements){

    vector <short int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector <short int> pred = rand_shuffle(10, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    sort(pred.begin(), pred.end());

    ASSERT_EQ(res, pred);

}

TEST(Tests, ThereAreIdenticalElements){

    vector <short int> res = {1, 2, 3, 4, 4, 6, 7, 8, 9, 9};
    vector <short int> pred = rand_shuffle(10, {1, 2, 3, 4, 4, 6, 7, 8, 9, 9});
    sort(pred.begin(), pred.end());

    ASSERT_EQ(res, pred);

}

TEST(Tests, BigArray){

    vector <short int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
                            21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 
                            40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
                            60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 
                            80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};

    vector <short int> pred = rand_shuffle(100, res);
    sort(pred.begin(), pred.end());

    ASSERT_EQ(res, pred);

}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
