#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// решение hard+ 4 вариант, 1 занятие
// вводите массив одной строчкой

int main(){
    vector<int> A;
    string a;
    stringstream aa;
    getline(cin, a);
    aa << a;
    // ввод массива
    while (aa >> a) A.push_back(stoi(a));
    vector<int> A1(size(A) + 1, 0);

    // создание префсумм 
    for (int i = 0; i < size(A); i++){
        A1[i + 1] = A[i] + A1[i];
    }
    
    int minelem = A1[0], ans = A1[1];
    for (int i = 1; i < size(A) + 1; i ++ ){
        minelem = min(A1[i], minelem);
        ans = max(ans, A1[i] - minelem);
    }

    cout << ans;
}