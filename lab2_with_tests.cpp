// Решение задачи Удаление дубликатов hard с тестам

// Добавил тесты, для этого пришлось создать промежуточный вектор со всеми входными значениями, который у меня слишком огромный,
// чтобы скрипту на нем нормально работать. В прошлой версии без тестов не приходилось создавать этот вектор и на данных с датасета
// все работало. Хотел бы на будущее поинтересоваться, как можно было бы реализовать тесты без необходимости в создании промежуточной
// функции и массива, потому что сейчас я всю лабу сделал, но решение разделено на два: одно оптимальное, но без тестов, другое
// неоптимальное, но с тестами, так что надеюсь, что вкупе их достаточно для зачета этой лабы, ибо логика в них идентичная.


#include <iostream>
#include <fstream>
#include <unordered_set>
#include <cassert>
using namespace std;


unordered_set<unsigned long long int> delete_duplicates(int size, vector<unsigned long long int> input_vec, bool show_result) {
    unordered_set<unsigned long long int> visited_numbers; // множество уникальных чисел, вес = кол-во уникальных * 8 байт

    unsigned long long int input_number; // входное число, 8 байт 

    for (int i = 0; i <= size; i++) { // O(n)
        input_number = input_vec[i]; // O(1) 
        if (visited_numbers.find(input_number) == visited_numbers.end()) { // О(1)
            visited_numbers.insert(input_number); // О(1), в худшем случае О(n), когда выделенной под множество памяти не хватает и надо выделить больше
            if (show_result == true) {
                cout << input_number << endl; // сразу выводим число, если его еще не было в множестве
            }
        }
    }
    return visited_numbers;
}


void test_delete_duplicates() {
    unsigned int input_size_0 = 10;
    vector<unsigned long long int> input_vec_0 = { 1, 2, 1, 5, 13, 500000000000000, 500000000000000, 5, 5, 10 }; // тест 1
    unordered_set<unsigned long long int> excepted_result_0 = { 1, 2, 5, 13, 500000000000000, 10 };
    unordered_set<unsigned long long int> result_0 = delete_duplicates(input_size_0, input_vec_0, false);
    assert(excepted_result_0 == result_0);
    cout << "test 0 - success!" << endl;

    unsigned int input_size_1 = 12;
    vector<unsigned long long int> input_vec_1 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; // тест 2 (крайний случай, когда все элементы повторяются)
    unordered_set<unsigned long long int> excepted_result_1 = { 1 };
    unordered_set<unsigned long long int> result_1 = delete_duplicates(input_size_1, input_vec_1, false);
    assert(excepted_result_1 == result_1);
    cout << "test 1 - success!" << endl;

    unsigned int input_size_2 = 15;
    vector<unsigned long long int> input_vec_2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }; // тест 3 (крайний случай, когда все элементы уникальны)
    unordered_set<unsigned long long int> excepted_result_2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    unordered_set<unsigned long long int> result_2 = delete_duplicates(input_size_2, input_vec_2, false);
    assert(excepted_result_2 == result_2);
    cout << "test 2 - success!" << endl;

    unsigned int input_size_3 = 10;
    vector<unsigned long long int> input_vec_3 = { 242, 127, 135, 135, 134, 242, 240, 127, 157, 240 }; // тест 4 (крайний случай, когда на вход подаются смешные статьи из УК РФ)
    unordered_set<unsigned long long int> excepted_result_3 = { 242, 127, 135, 134, 240, 157 };
    unordered_set<unsigned long long int> result_3 = delete_duplicates(input_size_3, input_vec_3, false);
    assert(excepted_result_3 == result_3);
    cout << "test 3 - success!" << endl;
}


int main()
{   
    unsigned long long int input_number; // входное число, 8 байт 
    unsigned int size; // размер входного массива, 4 байта
    cin >> size;
    
    vector<unsigned long long int> input_vec; // массив входных чисел, 8 байт * size
    bool show_result = true; // флаг, отвечающий за то, будем ли выводить пользователю резльтат работы (чтоб юнит тесты не спамили), 1 байт
    
    ifstream myfile("C:\\Users\\79500\\Downloads\\dataset.txt"); // открываю сгенеренный датасет
    if (myfile.is_open()) {
        while (myfile >> input_number) {
            input_vec.push_back(input_number);
            }
        myfile.close();
    }
    else cout << "Unable to open file";

    unordered_set<unsigned long long int> result = delete_duplicates(size, input_vec, show_result); // множество уникальных чисел, вес = кол-во уникальных * 8 байт
    
    test_delete_duplicates();

    return 0;
}
