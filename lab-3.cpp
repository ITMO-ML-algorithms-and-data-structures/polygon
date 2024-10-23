
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

// Функция для удаления дубликатов из строки чисел
void removeDuplicates(const std::string& input, std::ostringstream& output) {
    int number;
    std::vector<int> start_string;
    std::vector<int> result;
    std::istringstream stream(input);

    // Читаем числа из входной строки и добавляем их в start_string
    while (stream >> number) { // O(n) - считавем n чисел из строки
        start_string.push_back(number); // Добавляем число в вектор O(1)
    }

    // Удаляем дубликаты, оставляя только уникальные числа
    for (int con : start_string) { // O(n) проход по всему массиву
        // Проверяем, встречалось ли число ранее
        if (std::find(result.begin(), result.end(), con) == result.end()) { // O(m) - m - кол-во уникальных элементов
            result.push_back(con); // Если нет, добавляем его в результат  // O(1) - добавляем элемент в вектор
        }
    }

    // Записываем уникальные числа в выходной массив
    for (int con : result) {
        output << con << " "; // выводим Итоговый массив O(m) m - кол-во уникальных элементов
    }
}
//итоговая сложность O(n^2) n - кол-во элементов в начальной строке
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
        removeDuplicates("2 3 3 4 4", output);
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

