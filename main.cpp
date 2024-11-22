#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string_view>
#include <cassert> // Для тестов
using namespace std;

// Функция для обработки строк со значениями
vector<int> processLine(string_view line, unordered_map<string_view, int> &labels, int &index) {
    vector<int> result; // Вектор, хранящий индексы меток (размер вектора: 16 байт)
    size_t start = 0, end; // Два размера типа size_t: 8 байт * 2 = 16 байт

    // разделяем строку по ","
    while ((end = line.find(',', start)) != string::npos) {
        // получаем string_view нашей подстроки
        string_view curString = line.substr(start, end - start);

        // проверяем вхождение нашей строки в map лейблов, если нет, то добавляем и присваиваем новый индекс
        if (!labels.contains(curString)) {
            // Если метки нет, добавляем новую метку
            labels[curString] = index++;
        }
        result.push_back(labels[curString]); // Добавляем индекс метки в результат (4 байта на каждый int)
        start = end + 1;
    }
    // тот же самый код, только для самой последней строки с запятой
    string_view curString = line.substr(start);
    if (!labels.contains(curString)) {
        labels[curString] = index++;
    }
    result.push_back(labels[curString]);

    return result;
}

// Фукнция для вывода полученного списка из лэйблов
void printVector(const vector<int> &vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        // Проходим по вектору (4 байта на каждый элемент)
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Функция для чтения файла
void readFileAndProcess(const string &filename) {
    string line; // Строка для чтения из файла: базовое использование 16 байт + динамическая память для данных
    unordered_map<string_view, int> labels;
    // string_view чтобы избежать копирование данных
    vector<int> labelsVector; // наш вектор полученных лэйблов (базовые 16 байт)
    int index = 0; // Индекс для присвоения меткам: 4 байта

    fstream file(filename, fstream::in);
    // читаем файл построчно
    while (getline(file, line)) {
        vector<int> lineIndices = processLine(line, labels, index);
        labelsVector.insert(labelsVector.end(), lineIndices.begin(), lineIndices.end());
    }
    file.close();

    printVector(labelsVector);
}

// Функция с тестами
void testProcessLine() {
    unordered_map<string_view, int> testLabels1;
    unordered_map<string_view, int> testLabels2;
    unordered_map<string_view, int> testLabels3;
    int testIndex1 = 0;
    int testIndex2 = 0;
    int testIndex3 = 0;

    vector<int> result = processLine("Orange,Yellow,Orange", testLabels1, testIndex1);
    assert((result == vector{0, 1, 0}));

    result = processLine("Orange,Blue,Grey,Orange,Yellow,Blue", testLabels2, testIndex2);
    assert((result == vector{0, 1, 2, 0, 3, 1}));

    result = processLine("Blue", testLabels3, testIndex3);
    assert((result == vector{0}));

    cout << "All tests passed!" << endl;
}

int main() {
    testProcessLine(); // Запуск тестов

    cout << "File read started" << endl;
    readFileAndProcess("../dataset.txt");

    return 0;
}
