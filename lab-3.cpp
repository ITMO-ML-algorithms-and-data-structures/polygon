#include <iostream>
#include <random>
#include <vector>
#include <cassert>
#include <random>
#include <fstream>
#include <string>
using namespace std;
vector<int> shuffle(vector<int> vec) {
    // Создаем генератор случайных чисел
    random_device rd;
    mt19937 g(rd()); // О(1)

    // Алгоритм Фишера-Йетса
    for (int i = vec.size() - 1; i > 0; --i) { // O(N)
        // Генерируем случайное число от 0 до i
        uniform_int_distribution<int> dist(0, i); // O(1)
        int j = dist(g);

        // Меняем местами элементы
        swap(vec[i], vec[j]); // O(1)
    }
    return vec;
    //  O(N) - сложность
}

void test() {
    vector <int> original = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector <int> shuffled = shuffle(original);
    assert(shuffled != original);
    vector <int> original1 = { 1000,140,232,736,69,784,98,2, 1, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector <int> shuffled1 = shuffle(original1);
    assert(shuffled1 != original1);
}

int main() {
    test();
    // получаем данные из файла
    ifstream MyReadFile("vhod.txt");
    string str;
    vector <int> arr;
    while (getline(MyReadFile, str)) arr.push_back(stoi(str));
    vector <int> shuffled = shuffle(arr);
    // записываем данные в файл
    ofstream MyFile("vihod.txt");
    for (int i = 0; i < shuffled.size(); i++)MyFile << shuffled[i] << '\n';
    MyFile.close();
}
