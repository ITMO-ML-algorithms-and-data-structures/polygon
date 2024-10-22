#include <iostream>
#include <vector>
#include <fstream>
#include <ctime> // time()

using namespace std;

// Извлекаем dataset в vector
vector<int> read_file(const string filename) {
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
void shuffle_vector(vector<int>& a) {
    // Перемешивание с помощью прохода по всем элементам
    for (int i = 0; i < a.size(); ++i) { // O(N)
        // Генерируем случайный индекс для обмена в диапазоне от i до конца массива
        int j = i + rand() * time(0) % (a.size() - i);

        // Меняем местами элемент на позиции i и элемент на позиции j
        swap(a[i], a[j]);
    }
}

int main() {
    // Читаем данные из файла и сохраняем их в вектор
    vector<int> mas = read_file("/Users/mir/CLionProjects/lab-3/numbers.txt");

    // Перемешиваем вектор
    shuffle_vector(mas);

    // Выводим вектор после перемешивания
    for (int num: mas) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}