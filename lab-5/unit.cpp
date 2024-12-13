#include <iostream> 
#include <vector>
#include <cassert>
#include <algorithm>
#include "lab_5.cpp"

#define ll long long
using namespace std;

void comb_sort(vector<ll> &arr);
void binary_insertion_sort(vector<ll> &arr);
void flash_sort(vector<ll> &arr);

bool is_sorted(const vector<ll>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}

void test_comb_sort() {
    cout << "Comb Sort..." << endl;

    vector<ll> best_case = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    comb_sort(best_case);
    assert(is_sorted(best_case));

    vector<ll> avg_case = {5, 3, 8, 6, 2, 7, 4, 1, 9, 10};
    comb_sort(avg_case);
    assert(is_sorted(avg_case));

    vector<ll> worst_case = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    comb_sort(worst_case);
    assert(is_sorted(worst_case));

    cout << "Comb Sort успешно прошел все тесты!" << endl;
}

void test_binary_insertion_sort() {
    cout << "Binary Insertion Sort..." << endl;

    vector<ll> best_case = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    binary_insertion_sort(best_case);
    assert(is_sorted(best_case));

    vector<ll> avg_case = {5, 3, 8, 6, 2, 7, 4, 1, 9, 10};
    binary_insertion_sort(avg_case);
    assert(is_sorted(avg_case));

    vector<ll> worst_case = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    binary_insertion_sort(worst_case);
    assert(is_sorted(worst_case));

    cout << "Binary Insertion Sort успешно прошел все тесты!" << endl;
}


void test_flash_sort() {
    cout << "Flash Sort..." << endl;

    vector<ll> best_case = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    flash_sort(best_case);
    assert(is_sorted(best_case));

    vector<ll> avg_case = {5, 3, 8, 6, 2, 7, 4, 1, 9, 10};
    flash_sort(avg_case);
    assert(is_sorted(avg_case));

    vector<ll> worst_case = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    flash_sort(worst_case);
    assert(is_sorted(worst_case));

    vector<ll> equal_case = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    flash_sort(equal_case);
    assert(is_sorted(equal_case));

    vector<ll> large_case(10000, 0);
    for (int i = 0; i < 10000; i++) {
        large_case[i] = rand() % 10000;
    }
    flash_sort(large_case);
    assert(is_sorted(large_case));

    cout << "Flash Sort успешно прошел все тесты!" << endl;
}

int main() {
    test_comb_sort();
    test_binary_insertion_sort();
    test_flash_sort();
    cout << "Все тесты успешно пройдены!" << endl;
    return 0;
}
