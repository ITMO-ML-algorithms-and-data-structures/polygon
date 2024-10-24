//Ксения Автономова 24.10.2024
//Поток: 4
//Задача: Есть массив, нужно подсчитать кол-во уникальных значений и заменить каждое значение кол-вом.

#include <iostream>
#include <string> 
#include <unordered_map>
#include <fstream>

using namespace std;

int main()
{
    ifstream dataSet("dataset.txt");               //O(1)
    ofstream resultSet("resultset.txt");           //O(1)

    if (!dataSet.is_open()) {                      //O(1)
        cout << "File dataset.csv doesn't exist";
        return 1;
    }

    unordered_map<string, int> dictionary;         //O(1)

    string element;                                //O(1)

    while (getline(dataSet, element, ',')) {       //O(n) loop 1
        auto dictValue = dictionary[element];      //O(1) unordered map lookup

        if (dictValue == NULL) {                   
            dictionary[element] = 1;               //O(1) unordered map insert
        }
        else {
            dictionary[element]++;                 //O(1) unordered map update
        }
    }

    dataSet.clear();                               //O(1)
    dataSet.seekg(0, ios::beg);                    //O(1)

    bool firstElement = true;                      //O(2)

    while (getline(dataSet, element, ',')) {       //O(n) loop 2
        auto dictValue = dictionary[element];      //O(1) unordered map lookup

        if (firstElement) {
            resultSet << dictValue;                //O(1)
            firstElement = false;                  //O(2)
        }
        else {
            resultSet << ',' << dictValue;         //O(1)
        }
    }

    dataSet.close();                               //O(1)
    resultSet.close();                             //O(1)

    //loop 1 O(n) + loop 2 O(n) = O(n+n) = O(n)
}