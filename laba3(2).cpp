#include <iostream> 
#include <unordered_map> // хеш-таблицы. 
#include <vector> // динамические массивы. 
#include <string> // для работы со строками. 
#include <cassert> // для тестов
using namespace std;

// Функция для подсчета вхождений строк в массиве
vector<string> countString(int n, const vector<string>& input) {
    vector<string> arr = input;  // создаем копию входного массива для обработки
    // Память: вектор arr — 4 * n байт (каждый элемент типа string занимает 4 байта + m байт для самой строки, где m — средняя длина строки).

    unordered_map<string, int> countMap; // хеш-таблица для подсчета вхождений строк.
    // Память для хеш-таблицы: на каждом уникальном элементе хранится строка (4 * m байт для строки) и целое число (4 байта) для счетчика.

    for (const string& str : arr) {
        countMap[str]++; // увеличиваем счетчик для каждой строки
        // Доступ к элементу и обновление хеш-таблицы занимает O(1) в среднем, но память будет зависеть от количества уникальных строк.
    }

    for (int i = 0; i < n; i++) {
        arr[i] = to_string(countMap[arr[i]]); // заменяем строку на её счетчик
        // Память для каждой строки в arr — 4 * k байт, где k — количество цифр в числе.
        // Память для массива arr после выполнения: 4 * n * k байт.
    }

    return arr; // возвращаем массив с результатами подсчета
    // Возвращаемый вектор требует 4 * n * k байт, где n — количество строк, k — средняя длина числа.
}

int main() {
    // Тест 1: Уникальные строки
    vector<string> input1 = {"apple", "banana", "apple", "orange", "banana"};
    vector<string> expected1 = {"2", "2", "2", "1", "2"};
    vector<string> result1 = countString(input1.size(), input1);
    assert(result1 == expected1); // Проверка, что результат совпадает с ожидаемым

    // Тест 2: Все строки одинаковые
    vector<string> input2 = {"apple", "apple", "apple"};
    vector<string> expected2 = {"3", "3", "3"};
    vector<string> result2 = countString(input2.size(), input2);
    assert(result2 == expected2); // Проверка, что результат совпадает с ожидаемым

    // Тест 3: Все строки уникальные
    vector<string> input3 = {"apple", "banana", "2"};
    vector<string> expected3 = {"1", "1", "1"};
    vector<string> result3 = countString(input3.size(), input3);
    assert(result3 == expected3); // Проверка, что результат совпадает с ожидаемым

    // Тест 4: Пустой массив
    vector<string> input4 = {};
    vector<string> expected4 = {};
    vector<string> result4 = countString(input4.size(), input4);
    assert(result4 == expected4); // Проверка, что результат пустой

    cout << "Все тесты успешно пройдены!" << endl;

    return 0;
}
