#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>  // Для rand() и srand()

using namespace std;

// Извлекаем dataset в vector
vector<int> read_file(const string& filename) {
    vector<int> mas;
    ifstream in(filename);  // Открываем файл для чтения
    int number;

    // Копируем значения dataset в vector
    while (in >> number) {
        mas.push_back(number);  // Добавляем число в конец вектора
    }
    return mas;  // Возвращаем вектор с числами
}

// Функция для перемешивания вектора
void shuffle_vector(vector<int>& mas) {
    srand(static_cast<unsigned>(time(0)));  // Инициализируем генератор случайных чисел с помощью времени

    // Перемешивание с помощью прохода по всем элементам
    for (size_t i = 0; i < mas.size(); ++i) { // O(N)
        // Генерируем случайный индекс для обмена в диапазоне от i до конца массива
        size_t j = i + rand() % (mas.size() - i);

        // Меняем местами элемент на позиции i и элемент на позиции j
        swap(mas[i], mas[j]);
    }
}

int main() {
    // Читаем данные из файла и сохраняем их в вектор
    vector<int> mas = read_file("/Users/mir/CLionProjects/lab-3/numbers.txt");

    // Перемешиваем вектор
    shuffle_vector(mas);

    // Выводим вектор после перемешивания
    for (int num : mas) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}