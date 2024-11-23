#include <iostream>

using namespace std;

int main(){
    vector<int> arr = {10, 2, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 2};

    int sizee = arr.size();
    int maximum = 0;

    for (int i = 0; i < sizee; i++) {
        maximum = max(arr[i], maximum);
    }

    vector<int> pref_summa(maximum + 1, 0);

    for (int i = 0; i < sizee; i++) {
        pref_summa[arr[i]]++;
    }
    for (int i = 1; i <= maximum; i++) {
        pref_summa[i] += pref_summa[i - 1];
    }

    vector<int> answer(sizee);
    for (int i = 0; i < sizee; i++) {
        answer[pref_summa[arr[i]] - 1] = arr[i];
        pref_summa[arr[i]]--;
    }

    for (int i = 0; i < sizee; i++) {
        cout << answer[i] << " ";
    }
}