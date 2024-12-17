#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cassert>
void function(const std::vector<int> numers, std::vector<std::vector<int>>& result, std::vector<int> current, int start) {
    // Память: O(n), где n — максимальное количество комбинаций (в данном случае это 7 элементов).
    // Асимптотика: O(C(n, 7)), где C(n, k) — количество сочетаний из n по k.

    if (current.size() == 7) {
        result.push_back(current); // добавление текущей комбинации.
        // Память: O(7) на текущую комбинацию, но эта память освобождается после выхода из функции.
    }

    for (int i = start; i < numers.size(); i++) {
        current.push_back(i); // добавление текущего индекса.
        function(numers, result, current, i + 1); // рекурсивный вызов.
        current.pop_back(); // удаление последнего элемента.
        // Память в стеке на каждую рекурсию: O(7).
    }
}

std::string vuvod(std::vector<std::vector<int>> result, std::vector<int>& numers) {
    std::string s = ""; // пустая строка для результата

    // Память: O(n) для строки s, где n — длина результата.
    // Асимптотика: O(m * 7) в худшем случае, если все комбинации удовлетворяют условию (m — количество комбинаций).

    for (int flag = 0; flag < size(result); flag++) {
        // Проверка суммы.
        if (numers[result[flag][0]] + numers[result[flag][1]] +
            numers[result[flag][2]] + numers[result[flag][3]] +
            numers[result[flag][4]] + numers[result[flag][5]] +
            numers[result[flag][6]] == 0) {

            s = s + "[";
            for (int flag2 = 0; flag2 < 7; flag2++) {
                s = s + std::to_string(result[flag][flag2]);
                if (flag2 != 6) {
                    s = s + ", ";
                }
                else {
                    s = s + "]";
                }
            }
            s = s + ", ";
        }
    }
    if (size(s) != 0) {
        s.pop_back();
        s.pop_back(); // удаление запятой и пробела в конце строки.
    }
    return s; // Возврат сформированной строки.
}

void test() {
    std::vector<int> numers;
    numers = { 10,20,0,0,0,1,0,0 }; // тестовый ввод
    std::vector<std::vector<int>> result;
    result = { {0,0,0,0,0,0,0} };
    assert(vuvod(result, numers) == ""); // проверка на пустой вывод
}

int main() {
    test(); // выполнение теста
    time_t start, end;
    setlocale(LC_ALL, "Russian");
    std::vector<int> numers;
    std::vector<int> current;
    std::vector<std::vector<int>> result;
    std::string numbers_mini;

    std::cout << "Введите элементы массива, если закончите вводить, то выведите <continue>: ";
    numbers_mini = "";

    while (numbers_mini != "continue") {
        std::cin >> numbers_mini;
        if (numbers_mini != "continue") {
            numers.push_back(std::stoi(numbers_mini)); // добавление чисел в вектор
        }
    }

    time(&start);
    function(numers, result, current, 0); // поиск комбинаций
    std::cout << vuvod(result, numers); // вывод результата
    time(&end);

    double time_taken = double(end - start);
    std::cout << "\n";
    std::cout << time_taken << std::setprecision(7);
    std::cout << " sec " << std::endl;
}