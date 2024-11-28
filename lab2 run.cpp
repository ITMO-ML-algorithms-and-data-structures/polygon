#include "lab2.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
bool g(int sizearr, vector<int> arr, int k,vector<string> a){ // проверка для assert
    string d = func(sizearr, arr, k);
    for(string i : a){
        if(i == d){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arrass = {1,2};
    vector<string> a = {"1 2","2 1"};
    assert(g(2,arrass,2, a) == true);
    ifstream inputfail("input2.txt");
    string test;
    while(getline(inputfail, test)) { // читаем файл| o(кол строк в txt)
        int sizearr, sizeans;
        vector<int> arr;
        istringstream stream(test); // делим вход на 3 блока по запятой : 1 блок = размеру фходного массива | o(len(test)) за 3 блока
        string part;
        getline(stream,part,',');
        sizearr = stoi(part);
        getline(stream,part,',');// 2 блок = arr
        istringstream numarr(part);
        int num;
        while (numarr >> num){
            arr.push_back(num);
        }
        getline(stream,part);// 3 блок = размеру выхода
        sizeans = stoi(part);
        string ans = func(sizearr,arr,sizeans);// обращаемся к func
        cout << ans<<endl; //o(5n) тбрасываем не перем => o(n)
    }
    return 0;
}