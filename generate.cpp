#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    int count;
    cout << "Введите количество случайных чисел: ";
    cin >> count;

    ofstream outFile("random_numbers.txt"); // Открытие файла для записи
    if (!outFile) {
        cerr << "Не удается открыть файл для записи!" << endl;
        return 1;
    }

    // Запись случайных целых чисел в файл
    for (int i = 0; i < count; ++i) {
        int randomNumber = rand(); // Генерация случайного числа
        outFile << randomNumber << endl; // Запись числа в файл
    }

    outFile.close(); // Закрытие файла
    cout << "Случайные числа записаны в файл random_numbers.txt" << endl;

    return 0;
}
