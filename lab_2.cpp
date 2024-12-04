#include <iostream> 
#include <vector> 
#include <cmath> 
#include <string>
#include <fstream> 

#define ll long long
using namespace std;

int main(){
    // все измерения в байтах!!!

    ifstream fin("test0.txt"); // ~ 152 байта

    ll dlin, koll = 0; fin >> dlin; // 16 байт, тк 2 переменные
    
    vector <string> ass(dlin); // вес: 24 (вектор) + 32 * dlin, где dlin - кол-во строк во входном файле

    for (ll i = 0; i < dlin; ++i) fin >> ass[i]; // dlin * (32 байта + L), L - длина строки
    
    map <string, ll> repeats; // n * (32 байта + L + 8 байт + 40 байт), n - кол-во уникальных строк
    for (string value : ass) repeats[value]++; // 32 байта + L + 8 байт + 40 байт)

    for (ll i = 0; i < dlin; ++i){
        cout << repeats[ass[i]] << " ";
        if (repeats[ass[i]] == 1) koll++;
        
    }
    cout << endl << "Number of unique elements - " << koll;
    return 0;
}
// 24 + 32 * dlin + ∑L_i (сумма длин всех строк) + n * (32 + L + 8 + 40) и ещё 8 КБ для ввода/вывода
