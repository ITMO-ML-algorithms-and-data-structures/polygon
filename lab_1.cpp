// Решение задачи Удаление дубликатов hard

// Скрипт, которым я генерил датасет:
// python generate_dataset.py --mode numeric --num-rows 1000000000 --min-unique 10000 --min-value 1 --max-value 18000000000000000000 --delimiter \n --output-file dataset.txt

// Я ждал создания датасета минут 10, но он не прекращал создаваться
// Стало страшно за своего старика Леново и я стопнул скрипт, когда размер dataset.txt дошел до 1.5 гб
// Скрипт оптимизировал как смог: сложность O(n), но на моем ноуте ему все равно не хватает памяти, чтоб отработать на таких данных
// Я тестил на датасетах поменьше, всё летает
// Тип unsigned long long использую потому что только он подходит под условие задачи - принимать числа от 1 до 18е18
// Всё уместил в один цикл: считываю значение, проверяю, есть ли оно в множестве, и если нет, то добавляю в множество и сразу вывожу на экран

#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;


int main()
{   
    unordered_set<unsigned long long int> visited_numbers; // множество уникальных чисел

    unsigned long long int input_number; // входное число, 8 байт 

    ifstream myfile("C:\\Users\\79500\\Downloads\\dataset.txt"); // открываю сгенеренный датасет
    if (myfile.is_open()) {

        while (myfile >> input_number) {
            if (visited_numbers.find(input_number) == visited_numbers.end()) { // О(1)
                visited_numbers.insert(input_number); // О(1), в худшем случае О(n), когда выделенной под множество памяти не хватает и надо выделить больше
                cout << input_number << endl; // сразу выводим число, если его еще не было в множестве
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}