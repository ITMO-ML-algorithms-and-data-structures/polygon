#include <iostream>
#include <vector>


using namespace std;

int main() 
{
    int n, count = 1, max_count = 1, i;
    cin >> n;
    vector <int> a(n);

    for (i=0; i<n; i++){
        cin >> a[i];
    }

    vector <int> digits;
    vector <int> max_digits;
    digits.push_back(a[0]);

    for (i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            count = count + 1;
            digits.push_back(a[i]);
        }
        else {
            if (max_count < count) {
                max_count = count;
                count = 1;
                max_digits = digits;
                digits.clear();
                digits.push_back(a[i]);
            }
            else {
                count = 1;
                digits.clear();
                digits.push_back(a[i]);
            }
        }

    }
    for (i=0; i < max_digits.size(); i++){
        cout << max_digits[i] << " ";
    }

    return 0;
}