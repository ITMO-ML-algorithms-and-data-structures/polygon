#include <iostream>

using namespace std;

int main() {
    int n, S;
    cin >> S;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int l = 0, cur_sum = 0;
    for (int r = 0; r < n; r++) {
        cur_sum += arr[r];
        while (cur_sum > S) {
            cur_sum -= arr[l];
            l += 1;
        }
        if (cur_sum == S) {
            for (int i = l; i <= r; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
