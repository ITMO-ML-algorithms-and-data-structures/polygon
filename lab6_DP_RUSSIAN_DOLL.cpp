#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*ЭТО ЗАДАЧА О ВЛОЖЕНИИ МАТРЁШЕК, hard
1) ВХОД: МАССИВ ИЗ ПАР (WIDTH, HEIGHT)
2) НЕЛЬЗЯ МЕНЯТЬ ЭТИ ПАРАМЕТРЫ МЕСТАМИ
3) НЕОХОДИМО НАЙТИ МАКСИМАЛЬНОЕ КОЛИЧЕСТВО
МАТРЁШЕК, КОТОРЫЕ МОЖНО СЛОЖИТЬ В ОДНУ 
(ОТВЕТ С УЧЁТОМ ЭТОЙ ОДНОЙ)*/

bool IfFirstMax(const vector<int>& pair1, const vector<int>& pair2) {
    return pair1[0] < pair2[0];
}

bool IfSecondMax(const vector<int>& pair1, const vector<int>& pair2) {
    return pair1[1] < pair2[1];
}


void SortDolls(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), IfFirstMax);
    // stable_sort для сохранения порядка равных элементов
    stable_sort(pairs.begin(), pairs.end(), IfSecondMax); // O(N*logN), память тоже
}

int maxPairs(vector<vector<int>>& pairs) { // память под pairs: 8n байт
    if (pairs.empty()) return 0;
    SortDolls(pairs);
    vector<int> dp(pairs.size(), 1); // 4n байт
    int maxCount = 1; // минимальное кол-во вложенных пар

    // заполняем dp-шку
    for (int i = 1; i < pairs.size(); ++i) { //O(N)
        for (int j = 0; j < i; ++j) { // O(N) в худшем случае
            if (pairs[i][0] > pairs[j][0] && pairs[i][1] > pairs[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxCount = max(maxCount, dp[i]);
    }
    return maxCount;
}

/*  Общая память примерно 12n(pairs, dp) + 12(i, j, maxCount) байт
    Итоговая сложность O(N * N + NlogN) = O(N^2), где n=N=кол-ву пар*/

/* это пример динамического программирования тк одна большая задача
разбита на много подзадач (например, мы последовательно рассматриваем 
каждую матрёшку отдельно, и для неё тоже определяем задачи), также
используется массив dp, который изменяется в ходе решения. А
вот алгоритм (сложностью O(N*logN)), написанный мной и хранящийся в файлике lab6_NOT_DP_RussianEnvelopes
больше смахивает на жадный алгоритм через аналитику */

int main() {
    vector<vector<int>> pairs = {{2, 3}, {3, 5}, {4, 4}, {5, 9}, {6, 5}, {7, 6}};
    
    int result = maxPairs(pairs);
    cout << "Максимальное количество вложенных пар: " << result << endl;

    return 0;
}
