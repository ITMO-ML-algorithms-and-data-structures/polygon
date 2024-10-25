#include <iostream>
#include <vector>
#include <string>
using namespace std;
string func(int g,vector<int>a,int h){
    int ran,t;
    for(int i = 0;i < h;i++){ // мешаем рандомно i элемент с любым j >= i |o(4n) если h = n
        ran = rand() % (g - i) + i;
        t = a[i];
        a[i] = a[ran];
        a[ran] = t;
    }
    string ansarr;
    for (int ans : vector<int>(a.begin(), a.begin() + h)){//создаем строку с ответом | o(n)
        ansarr += to_string(ans);
        ansarr += ' ';
    }
    ansarr.pop_back();
    return ansarr;
}