#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

/*
1) Подсчет значений в массиве: есть массив, нужно подсчитать кол-во уникальных значений
и заменить каждое значение кол-вом	
2) вход: size=4
arr = [“Orange”, “Red”, “Green”, “Orange”]"	
3) выход: [2, 1, 1, 2]

Условия: 
количество значений во входном массиве - до 1e9
До 127 повторений одного слова во входном массиве
Максимальная длина строки - до 1000 символов
------ На выход std::vector<T>"  ---------

*/








// Создаём функцию
vector<int> vecCountUniqueValues(const vector<string>& arr) { // Подсчёт уникальных значений в массиве строк
    // На вход 1000 * N + 4 байт (N — количество строк, каждая строка до 1000 символов)

    unordered_map<string, int> frequencyMap; // Хэш-таблица для хранения частоты строк
    //(N * (1000 + 4)) + (N * 4) = N * 1004 байт (4 - размер int))


    vector<int> result(arr.size()); // Вектор для хранения количества вхождений
    //4 * arr.size() байт (4 - размер int)

    // Подсчёт количество вхождений каждого элемента в массив
    for (const string& str : arr) { 
        frequencyMap[str]++;
        // 1000 + 4 байта на строку (1000 - длина строки, 4 - размер int)
        // Память для одного элемента: 1000 + 4 + 4 = 1008 байт
        // + 4 байта только в рамках цикла (из-за области видимости)
    }

    // Замена каждого значения на количество его вхождений
    for (size_t i = 0; i < arr.size(); ++i) {
        result[i] = frequencyMap[arr[i]]; // Уже учли это в строке 29
    }

    return result;
}


// Эджкейсы

void testEdgeCases() {

//Пустой массив:
 vector<string> emptyArr;
    vector<int> emptyResult = vecCountUniqueValues(emptyArr);
    cout << "Пустой массив: ";
    cout << "[";
    for (size_t i = 0; i < emptyResult.size(); ++i) {
        cout << emptyResult[i];
        if (i < emptyResult.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    vector<int> result1vector = {};
    assert(vecCountUniqueValues(emptyArr) == result1vector);

// Массив с одним элементом:

 vector<string> singleElementArr = {"expulsion"};
    vector<int> singleElementResult = vecCountUniqueValues(singleElementArr);
    cout << "Массив с одним элементом: ";
    cout << "[";
    for (size_t i = 0; i < singleElementResult.size(); ++i) {
        cout << singleElementResult[i];
        if (i < singleElementResult.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    vector<int> result2vector = {1};
    assert(vecCountUniqueValues(singleElementArr) == result2vector);

// Массив с одинаковыми элементами:

vector<string> identicalElementsArr = {"AOW", "AOW", "AOW"};
    vector<int> identicalElementsResult = vecCountUniqueValues(identicalElementsArr);
    cout << "Массив с одинаковыми элементами: ";
    cout << "[";
    for (size_t i = 0; i < identicalElementsResult.size(); ++i) {
        cout << identicalElementsResult[i];
        if (i < identicalElementsResult.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    vector<int> result3vector = {3, 3, 3};

    assert(vecCountUniqueValues(identicalElementsArr) == result3vector);

}



//Посчитать память




// На выходе имеем 
// N * 1000 + N * 1008 + 4 + 4 * arr.size() = N * 1000 + N * 1008 + 4 + N * 4 = N * 2012 + 4 байт

int main() {

   // Пример (датасет?) массива;
vector<string> arr = {"expulsion", "AOW", "expulsion", "expulsion", "AOW", "mercy"};
    
    // Получение результата
    vector<int> result = vecCountUniqueValues(arr);
    
    // Вывод результата в виде std::vector<T>
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    testEdgeCases();

    return 0;
}
