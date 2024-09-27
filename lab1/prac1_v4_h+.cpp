#include <vector>
#include <iostream>
#include <string>
using namespace std;

/*
 решение hard+ 4 вариант, 1 занятие

 ввод массива одной строкой

 создание префсумм -> поддерживая минимальный элемент слева, найдем
 набольшую разницу между текущим элем. и минимальным слева
*/


int main(){
    vector<int> initial_arr;
    int buffer;
    
    // ввод массива, конец ввода - любой char
    while (cin >> buffer) initial_arr.push_back(buffer);

    if (initial_arr.size() != 0){
        vector<int> pref_sum_arr(size(initial_arr) + 1, 0);

        // создание префсумм 
        for (int i = 0; i < size(initial_arr); i++){
            pref_sum_arr[i + 1] = initial_arr[i] + pref_sum_arr[i];
        }
        
        //поддержание минимального слева + поиск наибольшей разницы
        int minelem = pref_sum_arr[0], answer = pref_sum_arr[1];
        
        for (int i = 1; i < size(initial_arr) + 1; i ++ ){
            minelem = min(pref_sum_arr[i], minelem);
            answer = max(answer, pref_sum_arr[i] - minelem);
        }

        cout << answer;
    }
    else cout << "error";
}