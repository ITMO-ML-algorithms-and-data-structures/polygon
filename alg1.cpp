#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include <chrono>
using namespace std;

// ������� ���������� Cocktail Shaker
void cocktailShakerSort(vector<int>& arr) {
    int left = 0; // 4 �����
    int right = arr.size() - 1; // 8 ���� (������� ������� �� ������� �������)
    bool swapped = true; // 1 ����

    while (swapped) {
        swapped = false; // 1 ����
        for (int i = left; i < right; ++i) { // O(n)
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]); // O(1)
                swapped = true; // 1 ����
            }
        }
        if (!swapped) break; // 1 ����

        swapped = false; // 1 ����
        --right; // O(1)

        for (int i = right; i > left; --i) { // O(n)
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]); // O(1)
                swapped = true; // 1 ����
            }
        }
        ++left; // O(1)
    }
}
/*
������ ���������:
- ��������� ���������:
  - � ������ � ������� ������: O(n^2) (������������).
- ������: O(1) (�������������� ������ ��� ����������).

����� ���������:
- ��������� ���������: O(n^2) (�� ���������� �������������).
- ������: O(1)
*/
// ������� ������ ������� �� �����
vector<int> readArrayFromFile(const string& filename) {
    vector<int> arr;
    ifstream file(filename);
    int num;
    while (file >> num) {
        arr.push_back(num);
    }
    return arr;
}

void test() {
    {
        vector<int> arr1 = { 5, 3, 8, 4, 2 };
        cocktailShakerSort(arr1);
        assert((arr1 == vector<int>{2, 3, 4, 5, 8}));
    }
    {
        vector<int> arr2 = { 1, 2, 3, 4 };
        cocktailShakerSort(arr2);
        assert((arr2 == vector<int>{1, 2, 3, 4}));
    }
    {
        vector<int> arr3 = { 2, 1 };
        cocktailShakerSort(arr3);
        assert((arr3 == vector<int>{1, 2}));
    }
    {
        vector<int> arr4 = {};
        cocktailShakerSort(arr4);
        assert(arr4.empty());
    }
    {
        vector<int> arr5 = { 3, 3, 3 };
        cocktailShakerSort(arr5);
        assert((arr5 == vector<int>{3, 3, 3}));
    }

}
int main() {
    test();
    cout << "All right!" << '\n';

    vector<int> arr = readArrayFromFile("8000.txt");
    auto start = chrono::high_resolution_clock::now();
    cocktailShakerSort(arr);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << duration.count() / 1e6 << '\n';
    return 0;
}
