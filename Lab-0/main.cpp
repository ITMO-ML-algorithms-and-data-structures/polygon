#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<pair<int, int>> f( vector<int>& e, int s) {
    set<pair<int, int>> res;
    for (size_t i = 0; i < e.size(); ++i) {
        for (size_t j = i + 1; j < e.size(); ++j) {
            if (e[i] + e[j] == s) {
                res.insert(make_pair(e[i], e[j]));
            }
        }
    }

    return res;

}


int main() {
    int s;
    cout << "Введите сумму пары:";
    cin >> s;

    int arraySize;
    cout << "Введите размер массива: ";
    cin >> arraySize;

    vector<int> e(arraySize);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < e.size(); i++){
        cin >> e[i];
    }



    set<pair<int, int>> pairs;

    pairs = f(e, s);


    for (const auto pair : pairs) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    return 0;
}