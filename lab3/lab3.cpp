#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <fstream>
#include <string>

using namespace std;

//принимает на вход массив типа vector c Элементами string, на выходе массив типа вектор с элементами типа int
vector<int> freqCount(vector<string> inputArray)
{   /*
    1. Объявляем хэш-таблицу c ключом типа стринг и значением типа int (до 1e9 повторений одного слова во входном массиве)
    2. Объявляем массив outputArray типа vector c Элементами int и с размером равным размеру inputArray
    */
    unordered_map<string, int> frequencyMap; //O(1) - для объявления переменной
    vector<int> outputArray (inputArray.size()); //O(N) - для выделения памяти
    /*
    1. Проходимся по значениям массива, помещая их в константу word типа string
    2. Увеличиваем значение на 1 по ключу word в хэш-таблице
    */
    for (const string& word : inputArray) //O(N) - цикл проходится по всем элементам inputArray
    {
        frequencyMap[word]++; //O(1) - увеличение значения в хэш-таблице
    }
    /*
    Цикл: каждый элемент входящего массива проеобразуется через хэш-таблицу в частоту появлений и это значение заносится 
    в результирующий массив по соответствующему индексу
    */
    for (int i = 0; i < (int) inputArray.size(); i++) //O(N) - цикл
    {
        outputArray[i] = frequencyMap[inputArray[i]]; //O(1) - доступ к элементам unordered_map
    }
    return outputArray;
} //Итог: O(N) + O(N) + O(N)= O(N)

//Тесты cassert
/*void test_freqCount() 
{
    vector<string> input_1 = {"orange", "red", "blue", "orange", "black"};
    vector<int> expected_output_1 = {2, 1, 1, 2, 1};
    vector<int> result_1 = freqCount(input_1);
    assert(result_1 == expected_output_1);
    cout << "test 1 is successful" << endl;

    vector<string> input_2 = {"orange", "red", "blue", "orange", "black", " ", "blue", " ", "orange"};
    vector<int> expected_output_2 = {3, 1, 2, 3, 1, 2, 2, 2, 3};
    vector<int> result_2 = freqCount(input_2);
    assert(result_2 == expected_output_2);
    cout << "test 2 is successful" << endl;

    vector<string> input_3 = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    vector<int> expected_output_3 = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    vector<int> result_3 = freqCount(input_3);
    assert(result_3 == expected_output_3);
    cout << "test 3 is successful" << endl;
}*/

int main()
{
    vector<string> input_array; //O(1) - создание вектора

    string filename = "dataset.txt"; // O(1) - присваивание строки
    // Открываем файл
    ifstream in(filename.c_str());  // O(1) - открытие файла

    // Считываем следующую строку из файла до конца.
    string str; // O(1) - создание строки
    while(getline(in, str)){ // O(N) - цикл while
        // если размер строки больше 0 то пушим в массив input_array
        if(str.size() > 0){ // O(1) + O(1) - размер и сравнение
            input_array.push_back(str); // O(1) - добавление строки в вектор
        } else {
            cerr << "Файл пуст" << endl; // O(1) - вывод сообщения об ошибке
        }
    }

    in.close(); //O(1) - закрытие файла

    vector<int> result = freqCount(input_array); // O(k) - k - количество уникальных строк, зависит от реализации функции freqCount
    
    // объявляем выходной поток и открываем файл для записи    
    ofstream out("result.txt"); // O(1) - открытие файла для записи

    if (out.is_open()) // O(1) - проверка, открыт ли файл
    {
        for (const int& count : result) // O(k) - k - количество элементов в result
        {
            out << count << " "; // O(1) для каждой записи, итого O(k)
        }
    }
    out.close(); // O(1) - закрытие файла
    
    cout << "File has been written" << endl; // O(1) - вывод сообщения

    // вывод в консоль

    // for (const int& count : result)
    // {
    //     cout << count << " ";
    // }

    // test_freqCount();
    return 0;
}
