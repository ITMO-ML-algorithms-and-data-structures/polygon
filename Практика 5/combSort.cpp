#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void combSort(vector<int>& array) {
    int n = array.size();
    int gap = n;
    bool flag = true;

    while (gap > 1 || flag) {
        gap = max(1, gap * 10 / 13);
        flag = false;
        for (int i = 0; i < n - gap; i++) {
            if (array[i] > array[i + gap]) {
                swap(array[i], array[i + gap]);
                flag = true;
            }
        }
    }
}

int main() {

    return 0;
}