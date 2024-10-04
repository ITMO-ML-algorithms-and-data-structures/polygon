#include <functional>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// чтобы везде не писать std
using namespace std;

// Обозначение для "short int"
// unit8 (short int) занимает 2 байта = 16 бит в памяти
#define uint8 short int

// инициализирую функцию LabelEncoder
// на вход подается путь до датасета
// на выходе отдает вектор чисел unit8
// (нам точно хватит этого типа, так как по условию задачи уникальных значений <= 100)
vector<uint8> LabelEncoder(string dataset_path) {
    string line;
    // инициализирую входной поток считывания из файла
    ifstream in(dataset_path);
    vector<short int> answer(0);
    // хэщ-таблица вида: (строка (токен) -> число соответсвующее токену)
    unordered_map<string, short int> map;

    // проверка файла на открытость
    if (in.is_open()) {
        // считывание токенов из файла
        while (getline(in, line)) {
            // проверка наличия токена в хэш-таблице
            // если его нет, то он добавляется в таблицу и ему присваевается номер равный длине таблицы
            if (map[line] == 0) map[line] = (uint8)map.size();
            // в ответ добавляется номер токена
            answer.push_back(map[line]);
        }
        // файл закрывается
        if (answer.size()) in.close();
    }

    // Память answer = (2 * кол-во токенов в датасете) байт
    return answer;
}


int main() {
    string path;
    cout << "Введите путь до датасета:" << '\n';
    cin >> path;
    auto answer = LabelEncoder(path);
    if (!answer.size()) {
        cout << "[]";
        return 0;
    }
    cout << '[';
    for (int i = 0; i < answer.size() - 1; i++) cout << answer[i] << ", ";
    cout << answer[answer.size() - 1];
    cout << ']';
}