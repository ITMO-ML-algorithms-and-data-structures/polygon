#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <cassert>




// Функция для удаления дубликатов и вывода уникальных чисел
// O(N) — Проход по вектору с входными данными




std::vector<int> demolishing_of_extra_numbers(const std::vector<int>& input_data) {
    std::unordered_map<int, bool> output_data;  // O(1) — Выделение памяти для мапы
    std::vector<int>data_to_return;
    for (const int& i : input_data) {
        // O(1) — Проверка наличия элемента в мапе
        if (output_data.count(i) == 0) {
            output_data[i] = true;  // O(1) — Добавление элемента в мапу
            std::cout << i << " ";  // O(1) — Вывод уникального элемента
            data_to_return.push_back(i);
        }
    }
    return data_to_return;
    std::cout << std::endl;  // O(1) — Печать новой строки
}

void test() {



    std::vector<int> test1 = { 1,2,3,4,1,1,1,3,5,7 };
    std::vector<int> result1 = { 1, 2, 3, 4 ,5,7};

    assert(demolishing_of_extra_numbers(test1) == result1);
    std::cout << std::endl;

    std::vector<int> test2 = { 1,2,3,4 };
    std::vector<int> result2 = { 1,2,3 ,4};

    assert(demolishing_of_extra_numbers(test2) == result2);
    std::cout << std::endl;

    std::vector<int> test3 = {};
    std::vector<int> result3 = {};

    assert(demolishing_of_extra_numbers(test3) == result3);
    std::cout << std::endl;

    std::vector<int> test4 = { 1,1,1,1,1,1 };
    std::vector<int> result4 = { 1 };

    assert(demolishing_of_extra_numbers(test4) == result4);
    std::cout << std::endl;


}


// Основная функция программы
// O(N) — Чтение данных из файла и удаление дубликатов
int main() {
    std::vector<int> input_data;  // O(1) — Выделение памяти под вектор
    std::ifstream inFile("C:\\Users\\Danielito\\source\\repos\\ConsoleApplication1\\numbers.txt");  // O(1) — Открытие файла

    // O(1) — Проверка успешного открытия файла
    if (!inFile) {
        std::cerr << "Не удалось открыть файл." << std::endl;  // O(1) — Сообщение об ошибке
        return 1;  // O(1) — Возврат ошибки
    }

    int number;
    test();
    // O(N) — Чтение чисел из файла и добавление их в вектор
    while (inFile >> number) {
        input_data.push_back(number);  // O(1) — Добавление числа в вектор
    }

    // O(1) — Закрытие файла после чтения
    inFile.close();

    // O(N) — Вызов функции для удаления дубликатов
    demolishing_of_extra_numbers(input_data);

    return 0;  // O(1) — Завершение программы
}



