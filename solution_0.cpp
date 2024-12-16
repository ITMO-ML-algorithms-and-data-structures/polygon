#include <iostream>
using namespace std;

int main() {
    const int size_of_array = 10000;
    const bool printing = true;
    int real_length;


    cin >> real_length;

    if (real_length > size_of_array) {
        cout << "Length of your array is more than available. You can resolve it, if you edit const size_of_array in raw code. Now it " << size_of_array;
        return 1;
    }

    char raw_array[size_of_array];

    for (int i = 0; i < real_length; i++) {
        char value;
        cin >> value;
        raw_array[i] = value;
    }

    for (int i = 1; i < real_length - 1; i++) {
        for (int shift = 1; shift < real_length; shift++) {
            int end, start;
            end = i + shift;
            start = i - shift;

            if (raw_array[end] == raw_array[start]) {
                cout << start << " " << end << endl;
                if (printing) {
                    for (int t = start; t <= end; t++) {
                        cout << raw_array[t];
                    }
                    cout << endl;
                }
            }
            else {
                break;
            }

            if ((end == (real_length - 1)) || start == 0) {
                break;
            }
        }
    }

    for (int i = 0; i < real_length - 1; i++) {
        for (int shift = 1; shift < real_length; shift++) {
            int end, start;
            end = i + shift;
            start = i - shift + 1;

            if (raw_array[end] == raw_array[start]) {
                cout << start << " " << end << endl;
                if (printing) {
                    for (int t = start; t <= end; t++) {
                        cout << raw_array[t];
                    }
                    cout << endl;
                }
            }
            else {
                break;
            }

            if ((end == (real_length - 1)) || start == 0) {
                break;
            }
        }
    }
}
