#include <iostream>
using namespace std;

int main() {
    int n;
    int m;

    cout << "Enter array length\n";
    cin >> n;
    int arr[n];

    cout << "Enter array\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter compared number\n";
    cin >> m;
    cout << "Found pairs:\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                if (arr[i] - arr[j] == m) {
                    printf("(%d, %d) \n", arr[i], arr[j]);
                }
            } else {
                if (arr[j] - arr[i] == m) {
                    printf("(%d, %d) \n", arr[i], arr[j]);
                }
            }
        }
    }

    return 0;
}
