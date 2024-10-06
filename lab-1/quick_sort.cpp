#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

void quick_sort(int *sorting_array, int size){
    int left = 0;
    int right = size - 1;

    int middle = sorting_array[size / 2];

    do {
        while (sorting_array[left] < middle) {
            left ++;
        }

        while (sorting_array[right] > middle) {
            right --;
        }

        if (left <= right) {
            int tmp = sorting_array[left];
            sorting_array[left] = sorting_array[right];
            sorting_array[right] = tmp;

            left ++;
            right --;
        }
    } while (left <= right);

    if (right > 0) {
        quick_sort(sorting_array, right + 1);
    }

    if (left < size) {
        quick_sort(&sorting_array[left], size - left);
    }
}

void test_sort() {
    int test1[5] = {4, 2, 1, 5, 3};
    int test2[5] = {4, 4, 1, 5, 3};
    int test3[5] = {4, 4, 3, 4, 3};
    int test4[5] = {1, 2, 2, 2, 1};
    int test5[5] = {};

    int res1[5] = {1, 2, 3, 4, 5};
    int res2[5] = {1, 3, 4, 4, 5};
    int res3[5] = {3, 3, 4, 4, 4};
    int res4[5] = {1, 1, 2, 2, 2};
    int res5[5] = {};

    quick_sort(test1, 5);
    quick_sort(test2, 5);
    quick_sort(test3, 5);
    quick_sort(test4, 5);
    quick_sort(test5, 5);

    assert (equal(test1, test1 + 5, res1));
    assert (equal(test2, test2 + 5, res2));
    assert (equal(test3, test3 + 5, res3));
    assert (equal(test4, test4 + 5, res4));
    assert (equal(test5, test5 + 5, res5));

    cout << "Test sort OK" << endl;
}

int main() {
    // int shuffled_array[5] = {4, 4, 1, 5, 3};
    // int numbers_of_value = sizeof(shuffled_array) / sizeof(*shuffled_array);

    // quick_sort(shuffled_array, numbers_of_value);

    // for(int i = 0; i < numbers_of_value; i ++)
    //     cout << shuffled_array[i] << ' ';

    test_sort();
}