//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>


vector <string> deletodinakovse() {
    vector <string> input={"Orange","Red","Green","Orange"};//24 байта * N
    map <string, int> exist;// 48*Количество уникальных слов
    int siz=input.size();//4 байта (не short, т.к. ограничение 10**9)
    auto  c=input.cbegin(); //8 байт (указатель, чтобы убирать значения по индексу (по сути c=i))
    for (int i; i<siz;i++){//4 байт
        if (exist.count(input[i])==1){
            input.erase(c);//- 24 байта за каждый дубликат
            siz--;
        }
        else{
            exist.insert(make_pair(input[i],1));
        }
        c++;
    }
    //24*N + 48*Количество уникальных слов + 16 байт, больше всего занимает словарь уникальных значений
    return input;//Вектор, ибо прописано в условии
}
int main() {
    deletodinakovse();
    return 0;
}
// Created by Даниил Петров on 14.10.2024.
//
