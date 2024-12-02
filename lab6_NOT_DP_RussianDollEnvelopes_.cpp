#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// НИЖЕ ПЕРВАЯ РЕАЛИЗАЦИЯ, КОТОРАЯ ОКАЗАЛАСЬ НЕ DP(((


bool IfFirstMax(const vector<int>& pair1, const vector<int>& pair2) {
    return pair1[0] < pair2[0]; // O(1)
}

bool IfSecondMax(const vector<int>& pair1, const vector<int>& pair2) {
    return pair1[1] < pair2[1]; // O(1)
}


void SortDolls(vector<vector<int>>& pairs) {
    // сначала сортируем по ширине, затем по высоте
    sort(pairs.begin(), pairs.end(), IfFirstMax); // O(n * log(n)) в среднем и худшем случаях
    stable_sort(pairs.begin(), pairs.end(), IfSecondMax);
    // stable_sort чтобы не делать лишние перестановки при равных значениях

    /*for (const vector<int>& pair : pairs) {
        cout << pair[0] << " " << pair[1] << endl;
    }*/
}

int CountDolls(vector<vector<int>>& pairs) {
    if (pairs.empty()) return 0;
    SortDolls(pairs);
    int k = 1; // первая кукла уже учтена
    int last_w = pairs[0][0];
    int last_h = pairs[0][1];

    for (size_t i = 1; i < pairs.size(); ++i) { // O(n)
        int w = pairs[i][0];
        int h = pairs[i][1];
        if (w > last_w && h > last_h) {
            last_w = w;
            last_h = h;
            ++k;
        }
    }
    return k;
} 

/* Итак: общая сложность: мы n раз (в цикле основной функцции CountDolls()
 производим достаточно простые действия, так что там сложность O(n), но с тем мы
 вызываем SortDolls(), где сложность O(n*log(n)), т. е. итоговая сложность O(N*logN) */

int main() {
    vector<vector<int>> envelopes1 = {{2, 3}, {3, 5}, {4, 4}, {5, 9}, {6, 5}, {7, 6}}; 
    // сверху пример входных который мне был полезен/интересен
    SortDolls(envelopes1);
    int count = CountDolls(envelopes1);
    cout << "Количество матрёшек: " << count << endl;
    return 0;
}