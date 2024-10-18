#include <iostream>
#include <random>
#include <vector>
#include <cassert>
#include <random>
using namespace std;
vector<int> shuffle(vector<int> vec) {
    // Создаем генератор случайных чисел
    random_device rd;
    mt19937 g(rd());

    // Алгоритм Фишера-Йетса
    for (int i = vec.size() - 1; i > 0; --i) {
        // Генерируем случайное число от 0 до i
        uniform_int_distribution<int> dist(0, i);
        int j = dist(g);

        // Меняем местами элементы
        swap(vec[i], vec[j]);
    }
    return vec;
}

int main() {
    vector <int> original = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector <int> shuffled = shuffle(original);
    assert(shuffled != original);
    vector <int> original1 = { 1000,140,232,736,69,784,98,2, 1, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector <int> shuffled1 = shuffle(original1);
    assert(shuffled1 != original1);
}