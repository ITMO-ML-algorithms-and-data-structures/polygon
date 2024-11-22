#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool isIsomorphic(const string& s, const string& t) {
    // проверка на длины строк
    // не занимает памяти
    if (s.length() != t.length()) {
        return false;
    }

    // инициализируем два массива для хранения сопоставлений символов
    // использование памяти: 1024 байта для двух целочисленных массивов
    int sChar[256];  // массив для сопоставления символов из строки s с t
    int tChar[256];  // массив для сопоставления символов из строки t с s

    // наполняем оба массива -1, чтобы указать, что сопоставления еще не сделаны
    // Использование памяти: 4 байта для заполнения массивов
    fill_n(sChar, 256, -1);  // заполняем массив значениями -1
    fill_n(tChar, 256, -1);

    // пробегаемся по строке
    // для каждой переменной цикла 4 байта
    for (int i = 0; i < s.length(); ++i) {
        int sIndex = static_cast<unsigned char>(s[i]); // получим ASCII символа s
        int tIndex = static_cast<unsigned char>(t[i]); // получим ASCII символа t

        // если оба символа еще не были сопоставлены, создаем новое сопоставление
        // для доступа к элементам массива требуется 4 байта
        if (sChar[sIndex] == -1 && tChar[tIndex] == -1) {
            sChar[sIndex] = tIndex;  // сопоставляем символ из s с t
            tChar[tIndex] = sIndex;  // сопоставляем символ из t с s
        }
        // если уже есть сопоставление, проверяем на то, согласованы ли они между собой
        // для доступа к элементам массива требуется 4 байта
        else if (sChar[sIndex] != tIndex || tChar[tIndex] != sIndex) {
            return false;
        }
    }

    return true;
}

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    if (isIsomorphic(s, t)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}
