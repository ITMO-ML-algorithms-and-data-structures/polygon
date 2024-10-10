using namespace std;
#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <string>
// Подключение нужных библиотек для решения задачи

set<long long> mass; // Создаю множество с большими значениями | если до 1е9: примерно 315 КБ (на один элемент 8 байт + указатели по 8 байт = примерно 32 КБ)
vector<int> vec; // Создаю вектор для вывода результата | если до 1е4: примерно 40 КБ (на один элемент 4 байта)
// Итоговое кол-во памяти примерно 360 КБ

int main() {
    ifstream file("numbers1.txt"); // Импортирую файл для считывания чисел
    string line; // Считываю число как string
    while (getline(file, line)) { // Цикл для считывания чисел из файла
        long long m = stoll(line); // преобразую string в long long
        mass.insert(m); // Добавляю число во множество
    }

    vec.assign(mass.begin(), mass.end()); // Преобразуем множество в вектор
    for (long long i : vec) { // Выводим результат
        cout << i << ", ";
    }
}