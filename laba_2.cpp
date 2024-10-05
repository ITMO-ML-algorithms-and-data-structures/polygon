#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

// Исходная функция main
void removeDuplicates(const std::string& input, std::ostringstream& output) {
    int number; // + 4 байта
    std::vector<int> start_string;
    std::unordered_set<int> seen;
    std::vector<int> result;
    std::istringstream stream(input);

    // Цикл, пока есть числа для чтения
    while (stream >> number) {
        start_string.push_back(number); // + 4 байта * n     n - кол - во чисел
    }

    // Перебираем все числа
    for (int con : start_string) {
        // Если число не встречалось раньше, добавляем его в вектор результат, и добавляем в хеш-таблицу, что мы его встречали
        if (seen.count(con) == 0) {
            result.push_back(con); // 4 байта  * l     l - кол - во уникальных значений
            seen.insert(con); //  + 4 байта  * l
        }
    }

    // Выводим начальную строчку без дубликатов
    for (int con : result) {
        output << con << " ";
    }
}
// Всего 4 + 4 * n + 4 * l + 4 * l == 4 + 4n + 8 * 2l байт

void testRemoveDuplicates() {
    {
        std::ostringstream output;
        removeDuplicates("1 2 3 4 5", output);
        assert(output.str() == "1 2 3 4 5 ");
    }

    {
        std::ostringstream output;
        removeDuplicates("1 1 1 1 1", output);
        assert(output.str() == "1 ");
    }

    {
        std::ostringstream output;
        removeDuplicates("5 4 3 2 1", output);
        assert(output.str() == "5 4 3 2 1 ");
    }

    {
        std::ostringstream output;
        removeDuplicates("2 2 3 3 4 4", output);
        assert(output.str() == "2 3 4 ");
    }

    {
        std::ostringstream output;
        removeDuplicates("", output);
        assert(output.str() == "");
    }

    {
        std::ostringstream output;
        removeDuplicates("10 20 10 30 40 50 60 60", output);
        assert(output.str() == "10 20 30 40 50 60 ");
    }

    std::cout << "Все тесты прошли успешно!" << std::endl;
}
int main() {
    testRemoveDuplicates();
    return 0;
}