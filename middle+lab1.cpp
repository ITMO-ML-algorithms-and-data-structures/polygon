#include <iostream>

using namespace std;

int Second_MAX (int arr[], int len) {
    int current_max = INT_MIN;
    int current_sec = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > current_max) {
            current_sec = current_max;
            current_max = arr[i];
        }
        if (arr[i] < current_max && arr[i] > current_sec) {
            current_sec = arr[i];
        }
    }
    return current_sec;
}