#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <set>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <cmath>

using namespace std;


// Ищем пересечение неотсортированных множеств. Функция работает за O(u * m),
// где u - мощность universe, а m - общее кол-во уникальных элементов в подмножествах заданного множества (в условии не указано, сколько их может быть)
insert_iterator<unordered_set<int>> unordered_set_intersection(unordered_set<int>::iterator b1, unordered_set<int>::iterator e1, unordered_set<int>::iterator b2, unordered_set<int>::iterator e2, insert_iterator<unordered_set<int>> out) {
    while (!(b1 == e1)) {
        if (!(find(b2, e2, *b1) == e2)) {
            *out = *b1;
            ++out;
        }

        ++b1;
    }

    return out;
}

// Функция cover для нахождения минимального покрытия множества
// Перебираем все двоичные числа от 0...01 до 1...1 длины мощности принимаемого массива, рассматривая эти числа как маски
// для выбора множеств из массива
// Итоговая сложность O(2^n * u * m * 25), что позволяет оценить сложность алгоритма как > O(2^n * n^3)
short int cover(vector<unordered_set<int>> arr, unordered_set<int> universe) { // arr: m * 4 байт, universe: 200 байт
    int arr_size = arr.size(); // 4 байта
    long int bin = stoi(string(arr_size, '1'), nullptr, 2); // O(n) - получаем битовую маску из всех единиц, 8 байт
    int mincount = 26; // 4 байта

    // Основной цикл: перебор всех масок. O(2^n), т.к. возмножных масок как раз 2^n.
    for (long int i = 1 ; i <= bin; ++i) {
        // i - 8 байт
        short int number_of_arrays = 0;   // Счетчик числа выбранных множеств, 2 байта
        bitset<25> bitset = i;            // Битовая маска для выбора множества, ~4 байта
        unordered_set<int> set_for_intersection = {}; // собираем цельное множество из выбранных для последующего его пересечения с universe

        // Вложенный цикл: обработка каждого бита
        for (short int j = 0; j < 25; ++j) {
            // j - 2 байта
            if (bitset[j] == 1 && j < arr_size) {
                //// Вставляем элементы множества в пересечение
                set_for_intersection.reserve(arr[j].size());
                set_for_intersection.insert(arr[j].begin(), arr[j].end());
                //// O(1) - вставка в неупорядоченное множество
                ++number_of_arrays;  // Увеличиваем счетчик
            }
        }
        // Сложность этого цикла O(25), т.к вставка в unordered_set - это O(1)

        unordered_set<int> intersection;

        // Пересечение множества set_for_intersection с universe
        unordered_set_intersection(universe.begin(), universe.end(), set_for_intersection.begin(), set_for_intersection.end(),
            inserter(intersection, intersection.begin()));

        // Если пересечение совпадает с universe, возвращаем число использованных множеств
        if (intersection == universe) {
            if (number_of_arrays < mincount) mincount = number_of_arrays;
        }
    }

    // Возвращаем кол-во, -1 если покрытия нет
    if (mincount != 26) return mincount;
    else return -1;
} // По памяти итого имеем: 4 * m + 200 + 4 + 4 + 8 + 8 + 2 + 4 + 2 = 4 * m + 232 байт

// Тестирующая функция
void test() {
    vector<vector<unordered_set<int>>> arrays = { { {1, 2, 3}, {2, 3}, {3, 4} }, { {1, 2, 3, 4, 5}, {17, 8, 9} },
        {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, {14}, {15}, {16}, {17}} };
    vector<unordered_set<int>> universums = { { 1, 3 }, {1, 2, 3, 9, 81},  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 } };
    vector<int> right_answers = { 1, -1, 17 };
    for (int i = 0; i < arrays.size(); i++) {
        assert(cover(arrays[i], universums[i]) == right_answers[i]);
    }
}

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian");

    // Предварительное тестирование программы
    test();

    // Читаем данные из файла
    string line;
    string path{};
    cin >> path;
    ifstream in(path);

    // Применяем алгоритм к заданному набору данных
    vector<unordered_set<int>> arrays{};
    unordered_set<int> universum{};
    if (in.is_open())
    {
        bool f = false;
        while (getline(in, line)) {
            unordered_set<int> st{};
            istringstream iss(line);
            string token;
            while (iss >> token) {
                st.insert(stoi(token));
            }
            if (line.size() == 0) f = true;
            if (f == false) {
                arrays.push_back(st);
            }
            else {
                universum.insert(st.begin(), st.end());
            }
        }
    }
    else cout << "Неверное наименование файла";
    in.close();

    // Вызов функции cover
    int res = cover(arrays, universum);
    cout << "Минимальное число множеств: " << res << endl;
}