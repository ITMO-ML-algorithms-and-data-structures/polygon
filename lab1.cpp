#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cassert>

void count_strings(int size, const std::vector<std::string>& all_strings, std::vector<short>& res) { // функция для подсчёта одинаковых строк
    std::unordered_map<std::string, short> dict; //пары строка - сколько раз встречается        + 80 байт

    for (int i = 0; i < size; i++) {
        std::string new_string = all_strings[i];
        dict[new_string]++; // +1 к количеству таких строк
    }

    for (int i = 0; i < size; i++) { // сохраняем всё в изначальном порядке
        res.push_back(dict[all_strings[i]]);
    }
}

void test() {  //тесты
    {
        // Пример из условия
        std::vector<std::string> all_strings = { "Orange", "Red", "Green", "Orange"};
        std::vector<short> res;
        count_strings(4, all_strings, res);
        std::vector<short> expected = { 2, 1, 1, 2 };
        assert(res == expected);
    }
    {
        // Все строки разные
        std::vector<std::string> all_strings = { "one", "two", "three", "four", "five", "six" };
        std::vector<short> res;
        count_strings(6, all_strings, res);
        std::vector<short> expected = { 1, 1, 1, 1, 1, 1 };
        assert(res == expected);
    }
    {
        // Все строки одинаковые
        std::vector<std::string> all_strings = { "abc", "abc", "abc" };
        std::vector<short> res;
        count_strings(3, all_strings, res);
        std::vector<short> expected = { 3, 3, 3 };
        assert(res == expected);
    }
    {
        // Пустой ввод
        std::vector<std::string> all_strings = {};
        std::vector<short> res;
        count_strings(0, all_strings, res);
        std::vector<short> expected = {};
        assert(res == expected);
    }
    {
        // Одиночный элемент
        std::vector<std::string> all_strings = { "one" };
        std::vector<short> res;
        count_strings(1, all_strings, res);
        std::vector<short> expected = { 1 };
        assert(res == expected);
    }
    {
        // Одинаковые строки в разном регистре
        std::vector<std::string> all_strings = { "ORANGE", "OrAnGe", "orange", "Orange"};
        std::vector<short> res;
        count_strings(4, all_strings, res);
        std::vector<short> expected = { 1, 1, 1, 1 };
        assert(res == expected);
    }

    std::cout << "All tests passed!" << "\n";
}

int main() {
    int size; // + 4 байта
    std::cin >> size; // количество строк
    std::vector<short> res; // результат   + 2 * m байт  m - количество уникальных строк
    std::vector <std::string> all_strings; // + 40 байт * n        n - кол-во введенных строк
    for (int i = 0; i < size; i++) { // Считывание данных
        std::string new_string;
        std::cin >> new_string;
        all_strings.push_back(new_string);
    }
    count_strings(size, all_strings, res);
    for (auto i : res) {
        std::cout << i << " "; //вывод результата
    }
    std::cout << "\n";
    test();
    return 0;
}
//Итог по памяти: 80 + 4 + 2 * m + 40 * n = 84 + 2 * m + 2 * n байт
