#include <iostream>
#include <vector>

using namespace std;

void shuttle_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }

        for (int j = n - i - 2; j >= 0; j--) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main() {
    setlocale(LC_ALL, "Ru");
    vector<int> arr = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    shuttle_sort(arr);

    cout << "Отсортированный массив: ";

    for (int num : arr) {
        cout << num << " ";
    }
    cout << std::endl;

    return 0;
}