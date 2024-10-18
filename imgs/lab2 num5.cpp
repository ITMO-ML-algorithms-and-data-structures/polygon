#include <iostream>
#include <vector>
#include <in>

using namespace std;

int removeRepeatingSymbols(int arr[], int n) {
    if (n == 0) { // возвращает 0 если список пустой
        return 0;
    }

    vector<int> unique = {};

    for (int i = 1; i < n; i++) {
        if (operator_in(arr[i], unique)) {
            unique.push_back(arr[i]);
        }
    }

    return unique;
}

int main()  {

    int n;
    cin >> n;

    int arr[n];

    cout << removeRepeatingSymbols(arr, n);

    return 0;
}