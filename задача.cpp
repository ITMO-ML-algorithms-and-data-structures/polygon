#include <iostream>
using namespace std;
int main() {
    int arr[5];
    int count = 0;
    cout << "Введите 5 чисел:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i]; 
    }
    for (int i = 0; i < 5; i++) {
        if (arr[i] < 0) { 
            count++;
        }
    }
   cout << "Количество отрицательных чисел: " << count << endl;
   return 0;
}