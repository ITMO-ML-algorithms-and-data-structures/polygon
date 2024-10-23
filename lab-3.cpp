//Удаление дубликата из массива [medium] Кирпо Тимофей 466167

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <string>





std::vector<int> fileinput(std::string filename) {
    std::vector<int> numbers;
    std::string project_path = "../";
    filename = project_path + filename;
    std::ifstream input_file(filename);
    std::string a;
    int n;

    if (!input_file.is_open()) {
        std::cout << "Error: failed to open file " << filename << std::endl;
        return numbers;
    }

    while (input_file >> a) {
        n = atoi(a.c_str());
        numbers.push_back(n);
    }

    input_file.close();
    return numbers;
}

void filewrite(std::vector<int> numbers, std::string filename) {
    std::string project_path = "../";
    filename = project_path + filename;
    std::ofstream output_file(filename);
    for(int number : numbers) {
        output_file << number << std::endl;
    }
    output_file.close();
}


std::vector<int> del_double(std::vector<int> names) {
    //Создание хэш таблицы для подсчета повторений
    std::unordered_map<int, int> count_repeat; //O(1) выделение памяти

    //Взятие размера входного значения
    int size = names.size(); //O(1) взятие ращмера массива

    //Подсчет повторений и запись в хэш таблицу
    for (int i = 0; i < size; i++) { //O(n)
        count_repeat[names[i]]++; //O(1) * n добавление элемемента повторяется n раз
    }

    //Создаем вектор для результата
    std::vector<int> result; //O(1) выделение памяти

    //Проходимся по элементам names и удаляем повторения
    for (int i = 0; i < size; i++) { //O(n)
        if (count_repeat[names[i]] > 1) {
            count_repeat[names[i]]--; //O(1) * n вычитание из хэш таблицы n раз
        }else {
            result.push_back(names[i]); //O(1) * n добавление элемента в вектор
        }
    }

    return result;
}

void tests() {
    // std::vector<int> vec = fileinput();
    // for (int i = 0; i < vec.size(); i++){
    //     std::cout << vec[i] << std::endl;
    // }
    // std::vector<int> vec = {1,2,3,4};
    // assert(del_double({1, 2 ,3 ,4}) == vec);
    // vec = {2,3,1};
    // assert(del_double({1, 1, 2 ,3 ,1}) == vec);
    // vec = {1};
    // assert(del_double({1, 1, 1}) == vec);
    // vec = {1,2};
    // assert(del_double({1, 2, 1, 2, 1, 2}) == vec);
    // vec = {};
    // assert(del_double({}) == vec);
}

int main() {
    filewrite(del_double(fileinput("million_nums.txt")), "output.txt");
    return 0;
}

//Сложность алгоритма составляет:
//O(N) - в худшем и среднем случае
//O(1) - в лучшем случае