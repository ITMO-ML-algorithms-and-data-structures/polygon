#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

void rand_shuffle(int n, vector <short int> &numbers){

    mt19937 mt(time(nullptr)); // settings for random generate

    //generate a random index and swap the element with that index with the last available for swapping element
    //O(n)

    for (int i = 0; i != n - 1; i++){

        int index4swap = mt() % (n - i); // O(1) 4 bytes
        swap(numbers[n - i - 1], numbers[index4swap]); // O(1)

    }

}


#include <gtest/gtest.h>

TEST(Tests, UniqueElements){

    vector <short int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector <short int> pred =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    rand_shuffle(10, pred);

    sort(pred.begin(), pred.end());

    ASSERT_EQ(res, pred);

}

TEST(Tests, ThereAreIdenticalElements){

    vector <short int> res = {1, 2, 3, 4, 4, 6, 7, 8, 9, 9};
    vector <short int> pred = {1, 2, 3, 4, 4, 6, 7, 8, 9, 9};

    rand_shuffle(10, pred);

    sort(pred.begin(), pred.end());

    ASSERT_EQ(res, pred);

}

TEST(Tests, BigArray){

    vector <short int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
                            21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 
                            40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
                            60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 
                            80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};

    vector <short int> pred = res;

    rand_shuffle(100, pred);

    sort(pred.begin(), pred.end());

    ASSERT_EQ(res, pred);

}

TEST(Tests, Empty){

    vector <short int> res = {};
    vector <short int> pred = {};

    rand_shuffle(0, pred);

    ASSERT_EQ(res, pred);
}

TEST(Tests, OneElement){

    vector <short int> res = {10000};
    vector <short int> pred = {10000};

    rand_shuffle(1, pred);

    ASSERT_EQ(res, pred);

}

int main(int argc, char **argv)
{
    
    int n; //4bytes
    cin >> n;
    vector <short int> numbers(n); //O(n) 2n bytes

    //O(n)
    for (int i = 0; i != n; i++){

        cin >> numbers[i]; //O(1)

    }
    
    rand_shuffle(n, numbers); //O(n)

    //O(n)
    for (int i = 0; i != n; i++){

        cout << numbers[i] << ' '; //O(1)
    }

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
