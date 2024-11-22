#include <iostream>

using namespace std;

int main() {
    int arr[] = {1, 2, 4, 5, 6, 10, 67, 186};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << ':';
    for (int i=0; i<n; i++) {
      if (arr[i]%2==0) {
        cout << arr[i] << " ";
      }
    }
    return 0;
}