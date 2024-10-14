#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <cassert>
using namespace std;

vector<int> shuffl(vector<int> arr) {
    random_device rd;  // Инициализируем случайное устройство
    mt19937 g(rd());   // Используем Mersenne Twister для генерации случайных чисел 2,5 КБ
    shuffle(arr.begin(), arr.end(), g); // Перемешиваем массив 16 байт + элементы(shuffle не занимает больше памяти, чем начальный массив)
    return arr;
}
int main() {
    vector <int> original = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
    vector <int> shuffled = shuffl(original);
    assert(shuffled != original);
    vector <int> original1 = { 1000,140,232,736,69,784,98,2, 1, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector <int> shuffled1 = shuffl(original1);
    assert(shuffled1 != original1);
}