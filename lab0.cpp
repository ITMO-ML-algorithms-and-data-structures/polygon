#include <iostream>
#include <vector>

using namespace std;

int main() {
    //int n = 8;
    //vector<int> a = {1, 3, -5, 4, -8, 5, 6, -1};
    int length;
    cin >> length;
    vector<int> arr(length);
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    int idx = 0, sum = 0, ans = arr[0];
    while (idx < length) {
        sum += arr[idx];

        if (sum < 0) {
            sum = 0;
        } else {
            ans = max(ans, sum);
        }
        r++;
    }

    cout << ans;
    return 0;
}