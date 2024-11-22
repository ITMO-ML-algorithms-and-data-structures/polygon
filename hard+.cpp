#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int n;
    int max_1 = numeric_limits<int>::min(), max_2 = 0;
    int min_1 = numeric_limits<int>::max(), min_2 = 0;

    cout << "Введите длину массива: ";
    cin >> n;
    vector<int> mas(n);
    cout << "Введите числа: ";

    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    if (n > 1) {
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
            cout << min_1 * min_2 << endl;
        }
        else {
            cout << max_1 * max_2 << endl;
        }
    }

    else {
        cout << mas[0] << endl;
    }
    return 0;
}
