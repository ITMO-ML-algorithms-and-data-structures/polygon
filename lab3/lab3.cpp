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
    unordered_map<string, int> frequencyMap;
    vector<int> outputArray (inputArray.size());
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
    for (int i = 0; i < (int) inputArray.size(); i++)
    {
        outputArray[i] = frequencyMap[inputArray[i]];
    }
    return outputArray;
}

//Тесты cassert
void test_freqCount() 
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
}

int main()
{
    vector<string> input_array;

    string filename = "dataset.txt";
    // Открываем файл
    ifstream in(filename.c_str());

    // Считываем следующую строку из файла до конца.
    string str;
    while(getline(in, str)){
        // если размер строки больше 0 то пушим в массив input_array
        if(str.size() > 0){
            input_array.push_back(str);
        } else {
            cerr << "Файл пуст" << endl;
        }
    }

    in.close();

    vector<int> result = freqCount(input_array);
    
    // объявляем выходной поток и открываем файл для записи    
    ofstream out("result.txt");

    if (out.is_open())
    {
        for (const int& count : result)
        {
            out << count << " ";
        }
    }
    out.close();
    
    cout << "File has been written" << endl;

    // вывод в консоль
    
    // for (const int& count : result)
    // {
    //     cout << count << " ";
    // }

    // test_freqCount();
    return 0;
}
