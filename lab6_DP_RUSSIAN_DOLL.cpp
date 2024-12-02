#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/* Решение задачи о матрёшках сводится к, по сути, двум этапам:
1) грамотной сортировке: необходимо сортировать width(1 показатель)
   по возрастанию, а там, где показатели width равны, сортировать
   height по убыванию, чтобы при дальнейшей обработке не брать дубли в расчёт 
2) поиск lis(longest increasible subsequense), её макс длина и будет ответом
*/


static bool comp(vector<int> &a, vector<int> &b){ // 0(1)
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}
    
int maxPairs(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), comp); // O(n*log(n))
    int i; // 4 байта
    int j; // 4 байта
    int len_pairs = pairs.size(); // 4 байта
    vector<int> lis; // 4*n байт
    for(i = 0; i < len_pairs; i++){ // O(n)
        vector<int>::iterator first_height = lower_bound(lis.begin(), lis.end(), pairs[i][1]); // 8 байт
        // O(log(n))
        // lower_bound - бинарный поиск (Finds 
        // the first position in which val (здесь - pairs[i][1]) could be 
        // inserted without changing the ordering)
        if (first_height == lis.end()){
            lis.push_back(pairs[i][1]);
            }
        // если итератор указывает на конец
        else{
            *first_height = pairs[i][1];
            // если не на конец, то возвращаем значение на которое указывает итератор
        }
    }
    return lis.size(); // длина lis - ответ на вопрос задачи
}

// Асимптотическая сложность: O(n * log(n))
// Память: len_pairs * 8 + 4n + 4*3 = 8n + 4n + 12 = 12n + 12 байт

/*  Общая память примерно 12n(pairs, dp) + 12(i, j, maxCount) байт
    Итоговая сложность O(N * N + NlogN) = O(N^2), где n=N=кол-ву пар*/

/* Итог: написала я классическое DP решение через массив, хранящий максимальные
кол-ва помещающихся внутрь матрёшек, заполняющийся за O(N^2), как сделала изначально,
и leetcode не засчитал (огр-е по времени), однако в этом решении тоже
есть элементы динамического программирования, тому док-во вектор lis меняющийся
по ходу решения и применение lower_bound для каждой высоты (разбиение на подзадачи)*/

int main() {
    vector<vector<int>> pairs = {{2, 3}, {3, 5}, {4, 4}, {5, 9}, {6, 5}, {7, 6}};
    
    int result = maxPairs(pairs);
    cout << "Максимальное количество вложенных пар: " << result << endl;

    return 0;
}