#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>


using namespace std;

//принмает на вход массив типа vector c Элементами string, на выходе массив типа вектор с элементами типа char
vector<char> freqCount(vector<string> inputArray)
{
    /*
    1. Объявляем хэш-таблицу c ключом типа стринг и значением типа char (до 127 повторений одного слова во входном массиве, char должно хватить)
    2. Объявляем массив outputArray типа vector c Элементами char и с размером равным размеру inputArray
    */
    unordered_map<string, char> frequencyMap;
    vector<char> outputArray (inputArray.size());
    /*
    1. Проходимся по значениям массива, помещая их в константу word типа string
    2. Увеличиваем значение на 1 по ключу word в хэш-таблице
    */
    for (const string& word : inputArray)
    {
        frequencyMap[word]++;
    }
    /*
    Цикл: каждый элемент входящего массива проеобразуется через хэш-таблицу в частоту появлений и это значение заносится 
    в результирующий массив по соответствующему индексу
    */
    for (int i = 0; i < inputArray.size(); i++)
    {
        outputArray[i] = frequencyMap[inputArray[i]];
    }

    return outputArray;
}

//Тесты cassert
void test_freqCount() 
{
    vector<string> input_1 = {"orange", "red", "blue", "orange", "black"};
    vector<char> expected_output_1 = {2, 1, 1, 2, 1};
    vector<char> result_1 = freqCount(input_1);
    assert(result_1 == expected_output_1);
    cout << "test 1 is successful" << endl;

    vector<string> input_2 = {"orange", "red", "blue", "orange", "black", " ", "blue", " ", "orange"};
    vector<char> expected_output_2 = {3, 1, 2, 3, 1, 2, 2, 2, 3};
    vector<char> result_2 = freqCount(input_2);
    assert(result_2 == expected_output_2);
    cout << "test 2 is successful" << endl;

    vector<string> input_3 = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    vector<char> expected_output_3 = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    vector<char> result_3 = freqCount(input_3);
    assert(result_3 == expected_output_3);
    cout << "test 3 is successful" << endl;
}

int main()
{
    vector<string> input_array = {"orange", "red", "blue", "orange", "orange"};
    vector<char> result = freqCount(input_array);
    for (const short& count : result)
    {
        cout << count << " ";
    }
    cout << endl;
    test_freqCount();
    return 0;
}