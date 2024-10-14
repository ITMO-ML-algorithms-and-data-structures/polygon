#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>


using namespace std;

//принимает на вход массив типа vector c Элементами string, на выходе массив типа вектор с элементами типа short
vector<short> freqCount(vector<string> inputArray)
{
    // Кол-во значений во входном массиве - до 1e4
    // До 127 повторений одного слова во входном массиве
    // Максимальная длина строки - до 100 символов
    // Avg string size = max / 2 = 100 / 2 = 50 символов
    // MAX Input Size = 24 + N * (32 + 50) = 24 + 82 * N
    /*
    1. Объявляем хэш-таблицу c ключом типа стринг и значением типа short (до 127 повторений одного слова во входном массиве, short должно хватить)
    2. Объявляем массив outputArray типа vector c Элементами short и с размером равным размеру inputArray
    */
    unordered_map<string, short> frequencyMap; 
    // printf("Size of map: %ld bytes \n", sizeof(frequencyMap)); //56 bytes
    vector<short> outputArray (inputArray.size());
    // printf("Size of vector: %ld bytes \n", sizeof(outputArray)); //24 bytes

    /*
    1. Проходимся по значениям массива, помещая их в константу word типа string
    2. Увеличиваем значение на 1 по ключу word в хэш-таблице
    */
    for (const string& word : inputArray)
    {
        frequencyMap[word]++; //max size = (32+50 bytes for key (string) + 2 bytes for value (short) + map_overhead) * N = (84 + map_overhead)* N
    }
    /*
    Цикл: каждый элемент входящего массива проеобразуется через хэш-таблицу в частоту появлений и это значение заносится 
    в результирующий массив по соответствующему индексу
    */
    for (short i = 0; i < (short) inputArray.size(); i++)
    //2 bytes inside the loop
    {
        outputArray[i] = frequencyMap[inputArray[i]]; //24 + 2 * N
    }
    return outputArray;
}

//Тесты cassert
void test_freqCount() 
{
    vector<string> input_1 = {"orange", "red", "blue", "orange", "black"};
    vector<short> expected_output_1 = {2, 1, 1, 2, 1};
    vector<short> result_1 = freqCount(input_1);
    assert(result_1 == expected_output_1);
    cout << "test 1 is successful" << endl;

    vector<string> input_2 = {"orange", "red", "blue", "orange", "black", " ", "blue", " ", "orange"};
    vector<short> expected_output_2 = {3, 1, 2, 3, 1, 2, 2, 2, 3};
    vector<short> result_2 = freqCount(input_2);
    assert(result_2 == expected_output_2);
    cout << "test 2 is successful" << endl;

    vector<string> input_3 = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    vector<short> expected_output_3 = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    vector<short> result_3 = freqCount(input_3);
    assert(result_3 == expected_output_3);
    cout << "test 3 is successful" << endl;
}

int main()
{
    vector<string> input_array = {"orange", "red", "blue", "orange", "orange"};
    vector<short> result = freqCount(input_array);
    for (const short& count : result)
    {
        cout << count << " ";
    }
    cout << endl;
    test_freqCount();
    return 0;

    // Max Memory size = 24 + 82 * N + 56 + 24 + (84 + map_overhead) * N + 2 + 24 + 2 * N = 130 + 168 * N + map_overhead * N
}