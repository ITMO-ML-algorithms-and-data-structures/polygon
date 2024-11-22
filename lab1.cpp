#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int num[100];
    for (int i = 1; i < 101; i++) {
        num[i - 1] = i;
    }
    int S = 52;
    vector<pair <int, int>> pairs;
    for (int i = 0; i < 100; i++) {
        for (int j = i+1; j < 100; j++) {
            if (num[i] + num[j] == S) pairs.push_back(make_pair(num[i],num[j]));
        }
    }
    return 0;
}

