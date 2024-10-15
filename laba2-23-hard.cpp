#include <iostream>
#include <vector>
#include <fstream>
#include <string>  
using namespace std;
// N — это количество элементов в векторе vec (читаемом из файла)
// M — это количество уникальных элементов, которые добавляются в вектор answer.
vector<int> func(vector<int> numbers) {
    vector<int> answer; // память под вектор (не учитываем пока он пуст) + 24 байта на метаданные вектора
    for (int i = 0; i < size(numbers); i++) { // 4 байта для i
        int isIn = 1; // 4 байта для isIn
        for (int j = 0; j < size(answer); j++) { // 4 байта для j (только внутри цикла)
            if (numbers[i] == answer[j]) { // 4 байта для numbers[i], 4 байта для answer[j]
                isIn = 0; // 4 байта для isIn (изменение значения)
                break;
            }
        }
        if (isIn) {
            answer.push_back(numbers[i]); // 4 байта для каждого числа, добавленного в answer
            // Каждое добавление увеличивает размер вектора на 4 байта * количество добавленных элементов
        }
    }

    // Выводим результат, память под итератор:
    for (vector<int>::iterator i = answer.begin(); i != answer.end(); ++i) {
        cout << *i; // 4 байта на каждый элемент вывода
        cout << " ";
    }

    return answer; // память под вектор answer (не учитывается в возвращаемом значении, так как это временная копия)
}

int main() {
    string line; // 24 байта под строку line
    ifstream in("tests_laba2.txt"); // 8 байт на объект ifstream
    if (in.is_open()) {
        int c = 0; // 4 байта для c
        vector<int> vec; // память под вектор (метаданные вектора, 24 байта)
        int size_vec; // 4 байта для size_vec
        in >> size_vec; // считываем размер вектора
        while (in >> c) {
            vec.push_back(c); // добавляем элементы в вектор, каждый элемент занимает 4 байта
        }
        func(vec); // передача вектора в функцию, занимаемая память — память самого вектора (размер * 4 байта)
    }
    in.close(); // закрытие файла (дополнительной памяти не требует)
    return 0; // программа завершена
}

// Итоговое использование памяти:
// = 76 байт + 4 * N + 4 * M байт