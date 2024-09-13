#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    int max_1 = -999999;
    int max_2 = 0;
    int min_1 = 999999;
    int min_2 = 0;

    cin >> n;
    vector<int> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    for (int i = 0; i < n; i++) {
        if (mas[i] >= max_1) {
            max_2 = max_1;
            max_1 = mas[i];
        }
        else if (mas[i] >= max_2 && mas[i] <= max_1) {
            max_2 = mas[i];
        }
        if (mas[i] <= min_1) {
            min_2 = min_1;
            min_1 = mas[i];
        }
        else if (mas[i] <= min_2 && mas[i] >= min_1) {
            min_2 = mas[i];
        }
    }

    if ((min_1 * min_2) > (max_1 * max_2)) {
        cout<<min_1 * min_2<<endl;\
    }
    else {
        cout<<max_1 * max_2<<endl;
    }

    return 0;
}
