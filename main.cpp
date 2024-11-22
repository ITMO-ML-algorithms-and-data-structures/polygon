#include <iostream>
#include <random>
#include <vector>
#include <random>
#include <fstream>
#include <cassert>

using namespace std;

void random_shuffle(vector<int> & array) {
    // Создание устройства для получения случайных чисел
    random_device rd;
    // Использование генератора случайных чисел
    mt19937 gen(rd());

    // Алгоритм Фишера-Йетса для перемешивания
    // O(N) сложность
    for (int i=array.size()-1; i > 0; i--) {
        // Генерация случайного числа от 0 до i
        uniform_int_distribution<> dis(0, i);
        // Инициализация рандомного ключа
        int random_key = dis(gen);
        // меняем местами элементы
        swap(array[i], array[random_key]);
    }
}


// Тест
void test_shuffle(vector<int>& array) {
    vector<int> original_array = array;
    random_shuffle(array);
    bool is_shuffled = true;

    // Проверка на то, что все элементы перемешаны
    // O(N) сложность
    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] == original_array[i]) {
            is_shuffled = false;
            break;
        }
    }

    // Если перемешивание не изменило порядок элементов, то выводим ошибку
    assert(is_shuffled && "Массив плохо перемешан");
}


int main() {
    ifstream infile("input.txt");
    vector<int> array;
    int number;

    // Добавляем элементы в массив array из input
    // O(N) сложность
    while (infile >> number) {
        array.push_back(number);
    }
    infile.close();

    // Проверка на пустоту файла
    if (array.empty()) {
        cerr << "Подан пустой файл" << endl;
        return 1;
    }

    test_shuffle(array);
    random_shuffle(array);

    // O(N) сложность
    for (int i: array) {
        cout << i << ' ';
    }

    return 0;
}