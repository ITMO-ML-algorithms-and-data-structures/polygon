#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
string func(int g, vector<int>a, int h) {
    string ansarr;
    srand(static_cast<unsigned int>(time(0)));//o(n)
    for (int i = 0; i < h; i++) {
        int ran = rand() % (g - i) + i; // Выбираем случайный индекс
        ansarr += to_string(a[ran]) + ' ';
        a[ran] = a[i]; // Перемещаем текущее значение в случайную позицию
    }
    ansarr.pop_back();
    return ansarr;
}