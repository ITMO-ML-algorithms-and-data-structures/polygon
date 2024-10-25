//Удаление дубликата из массива [medium] Кирпо Тимофей 466167

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <stdlib.h>
#include <fstream>


//Функция импорта из файла, где элементы построчно
std::vector<int> fileinput(std::string filename) {
    //Задаем вектор и инпутим файл
    std::vector<int> numbers;
    std::ifstream input_file(filename);
    std::string a;
    int n;

    //Проверяем открылся ли файл
    if (!input_file.is_open()) { //O(1)
        std::cout << "Error: failed to open file " << filename << std::endl;
        return numbers;
    }

    //Инпутим из файла
    while (input_file >> a) { //O(1) * n = O(n)
        n = atoi(a.c_str()); //O(n)
        numbers.push_back(n); //O(1)
    }

    input_file.close();
    return numbers;
}


//Функция записи в файл
void filewrite(std::vector<int> numbers, std::string filename) {

    //Открываем файл для записи
    std::ofstream output_file(filename);

    //Записываем файл
    for(int number : numbers) { //O(1) * n = O(n)
        output_file << number << std::endl; //O(1)
    }
    output_file.close();
}


std::vector<int> del_double(std::vector<int> names) {
    //Создание хэш таблицы для подсчета повторений
    std::unordered_map<int, int> count_repeat; //O(1) выделение памяти

    //Подсчет повторений и запись в хэш таблицу
    for (int i = 0; i < names.size(); i++) { //O(n)
        count_repeat[names[i]]++; //O(1) * n добавление элемемента повторяется n раз
    }

    //Создаем вектор для результата
    std::vector<int> result; //O(1) выделение памяти

    //Проходимся по элементам names и удаляем повторения
    for (int i = 0; i < names.size(); i++) { //O(n)
        if (count_repeat[names[i]] > 1) {
            count_repeat[names[i]]--; //O(1) * n вычитание из хэш таблицы n раз
        }else {
            result.push_back(names[i]); //O(1) * n добавление элемента в вектор
        }
    }

    return result;
}

void tests() {
    std::vector<int> vec = {1,2,3,4};
    assert(del_double({1, 2 ,3 ,4}) == vec);
    vec = {2,3,1};
    assert(del_double({1, 1, 2 ,3 ,1}) == vec);
    vec = {1};
    assert(del_double({1, 1, 1}) == vec);
    vec = {1,2};
    assert(del_double({1, 2, 1, 2, 1, 2}) == vec);
    vec = {};
    assert(del_double({}) == vec);
}

int main() {
    //filewrite(del_double(fileinput("1e9_data.txt")), "output_for_1e9.txt");
    //filewrite(del_double(fileinput("1e6_data.txt")), "outuput_for_1e6.txt");
    tests();
    return 0;
}

//Сложность алгоритма составляет:
//O(N) - в худшем и среднем случае
//O(1) - в лучшем случае