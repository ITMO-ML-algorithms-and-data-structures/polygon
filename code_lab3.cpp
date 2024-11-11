#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <algorithm>

/* Задача: сэмплирование */




// (средняя врем. сложность O(1)) функция для генерации "случайного" индекса до максимального указанного
// с помощью момента времени и лин. конг. генератора (ниже)
long int IndexRandom(long int max) {
    static std:: unordered_map<long int, int> indexes_map;
    static size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    // получаем время прошедшее с эпохи Unix 
    // static чтобы выделить память один раз и не инициализировать сид каждый раз при вызове функции
    seed = (seed * 48271) % 2147483647; // O(1)
    // линейный конгруэнтный генератор (использует 48271 как 
    // множитель, обеспечивающий хорошую статистику случайности, а также 2**31 - 1, не давая выпрыгнуть за 32битное число)
    long int new_index = seed % max;
    if (indexes_map.find(new_index) == indexes_map.end()) { // проверяем что такого индекса ещё не встречалось
        return new_index;
    } // O(1)
    return -1;
}


std::vector<long int> GoAndSample(std::vector<long int> given_massive, long int n) { 
    if (n > given_massive.size()) {
        n = given_massive.size(); // проверка чтобы не выпасть из массива
    } // O(1)

    std::vector<long int> massive_sampled;
    std::unordered_set<long int> unique_indexes; // множество для хранения уникальных индексов

    while (massive_sampled.size() < n) // O(n)
     {
        long int new_index = IndexRandom(given_massive.size());
        if (new_index > -1 && unique_indexes.find(new_index) == unique_indexes.end()) { // проверяем уникальность
            unique_indexes.insert(new_index); // O(1)
            massive_sampled.push_back(given_massive[new_index]); // добавляем элемент в выборку
        } // O(1)
    }
    return massive_sampled; // возвращаем выборку
} // O(n) общая


// функция для проверки содержания всех элементов одного вектора в другом
bool containsAll(const std::vector<long int>& sampledarr, const std::vector<long int>& bigarr) {
    for (const long int& elem : sampledarr) { // O(n)
        bool found = false;
        for (const long int& sup_elem : bigarr) { // O(m)
            if (elem == sup_elem) {
                found = true;
                break;
            }
        }
        if (not found) {
            return false;
        }
    }
    return true; // O(n * m), т. е. O(n**2) в худшем случае
}


int main() {
    // Тест на массиве из повторяющихся элементов------
    long int m = 4;
    std:: cout << std::endl;
    std::vector<long int> Answer = GoAndSample({1, 1, 1, 1, 1, 1}, m);
    std::vector<long int> right_answer {1, 1, 1, 1};
    assert(Answer == right_answer);
    std::cout << std::endl;

    // Тест на отсутствие данных-----------------------
    std::vector<long int> Answer0 = GoAndSample({}, 0);
    assert(Answer0.size() == 0);
    // Тест на мусор в сэмплированном массиве----------
    // (+ с использованием данных из файла, где элементов > 10**4)

    std::ifstream stream_numbers("dataset_file.txt");
    std::vector<long int> dataset_nums;
    long int c;
    while (stream_numbers >> c) {
        dataset_nums.push_back(c);
    }
    stream_numbers.close();
    std::vector<long int> Answer2 = GoAndSample(dataset_nums, 10010);
    assert(containsAll(Answer2, dataset_nums));

    // Тест на массиве---------------------------------
    long int m1 = 4;
    std:: cout << std::endl;
    std::vector<long int> Answer1 = GoAndSample({1, 2, 3, -2, 2, 9}, m);
    for (const long int& i: Answer1){
        std:: cout << i << " ";
    }
    return 0;
}


// Итоговый подсчёт асимптотики: O(n^2)
