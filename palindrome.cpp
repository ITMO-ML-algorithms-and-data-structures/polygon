// Найти индекс, с которого начинается последовательность, являющаяся палиндромом
// Input: plip
// Output: 3

#include <iostream>


using namespace std;

bool palindrome(string subsequence, int left, int right) {
    while (left < right) {
        if (subsequence[left] != subsequence[right]) {
            return false;
        }
        left++;
        right--;


    }
    return true;
}

int findindex(const string &subsequence) {
    int N = subsequence.length();


    for (int i = 0; i < N; ++i) {
        if (palindrome(subsequence, i, N - 1)) {
            return i;
        }
    }

    return -1;
}

int main() {

    string subsequence;

    cin >> subsequence;

    int index = findindex(subsequence);

    cout << index << '\n';

    return 0;
}