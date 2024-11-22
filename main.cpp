#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a_count;
    cin >> a_count;
    int a[a_count];
    for (int i=0; i<a_count; i++) {
        cin >> a[i];
    }
    float sr=0;
    int s=0;
    int count = 0;
    for (int i=0; i<a_count; i++) {
        s=s+a[i];
    }
    sr=float(s)/a_count;
    for (int i=0; i<a_count; i++) {
        if (a[i]<sr) {
            count = count + 1;
        }
    }
    cout << count;
    return 0;
}