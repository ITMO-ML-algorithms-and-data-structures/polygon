#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

bool solution(const string& str) {
    int skobka = 0;

    for (char ch : str) {
        if (ch == '(') {
            skobka++;
        } else if (ch == ')') {
            if (skobka == 0) {
                return false;
            }
            skobka--;
        }
    }

    // Если все скобки открыты и нет лишней закрывающей
    return true;
}

void test() {
    // Тест 1: сбалансированные скобки
    assert(solution("()") == true);
    // Тест 2: несбалансированные скобки
    assert(solution("a(b)(((a)b)") == true);
    // Тест 3: только открывающие скобки
    assert(solution("(((") == true);
    // Тест 4: только закрывающие скобки
    assert(solution(")))") == false);
    // Тест 5: пустая строка
    assert(solution("") == true);
    // Тест 6: строка без скобок
    assert(solution("Hello, World!") == true);
    // Тест 7: комбинированные скобки
    assert(solution("((ad)ad)(wd(a))()a") == true);

    cout << "Все тесты завершены" << endl;
}

int main() {
    // Ввод данных из файла
    ifstream MyFile("input.txt");
    string str;
    getline(MyFile, str);

    // Проверка скобок в строке из файла
    if (solution(str)) {
        cout << "good!!\n" << endl;
    } else {
        cout << "bad((\n" << endl;
    }

    // Запуск юнит-тестов
    test();
}
