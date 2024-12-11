#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <cassert>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()

using namespace std;

/* Задача: 

Сэмплирование массива: есть массив, необходимо его сэмплировть, то есть 
создать новый массив размера K, элементы которого должны быть выбраны случайным образом, 
но не должны повторяться

Вход: size = 4
arr = [1, 100, 10, 2]
K = 3	

Выход: [1, 2, 10]
			
Условия:
1) Количество значений во входном массиве - до 1e9
2) Сложность работы алгоритма не должна превышать O(N)

*/




// Функция с решением


vector<int> sampleArray(const vector<int>& arr, int K) {
    // Проверяем, что K не больше размера массива
    if (K > arr.size()) {
        throw invalid_argument("K не может быть больше размера массива"); // O(1) - проверка условия
    }

    set<int> selectedIndices; // Множество для хранения выбранных индексов; O(1) - выделение памяти для множества
    vector<int> sampledArray;  // Вектор для хранения результата; O(1) - выделение памяти для результирующего массива

    // Генерируем случайные индексы до тех пор, пока не наберём K уникальных
    while (selectedIndices.size() < K) { // O(K) в худшем случае, если K уникальных индексов не найдены сразу
        int randomIndex = rand() % arr.size(); // Генерируем случайный индекс; O(1)
        selectedIndices.insert(randomIndex);    // Добавляем индекс в множество (дубликаты игнорируются); O(1) в среднем случае 
    }

    // Переносим выбранные элементы в конечный массив
    for (int index : selectedIndices) { // Проходим по K уникальным индексам; O(K)
        sampledArray.push_back(arr[index]); // Вставляем элемент в вектор; O(1)
    }

    return sampledArray; // Возвращаем новый массив; O(1)
}



// Функция с тестами
// Эджкейсы
void testEdgeCases() {

    //Кейс 1: массив только с одинаковыми значениями
    vector<int> identicalElementsArr = {1, 1, 1, 1};
    try {
        vector<int> result = sampleArray(identicalElementsArr, 1);
        cout << "Массив с одинаковыми элементами: [";
        cout << result[0] << "]" << endl; // Должен быть возвращён один элемент
        assert(result.size() == 1 && result[0] == 1);
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }


    //Кейс 2: K больше N
    vector<int> smallArr = {1, 2};
    try {
        sampleArray(smallArr, 3); // Должно выбросить исключение
    } catch (const invalid_argument& e) {
        cout << "K больше N: " << e.what() << endl; // Должно быть выведено сообщение об ошибке
    }



    //Кейс 3: пустой массив
    vector<int> emptyArr;
    try {
        vector<int> emptyResult = sampleArray(emptyArr, 0); // Должен быть возвращён пустой массив
        cout << "Пустой массив: [";
        for (size_t i = 0; i < emptyResult.size(); ++i) {
            cout << emptyResult[i];
            if (i < emptyResult.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl; // Должен быть пустой вывод
        assert(emptyResult.empty());
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    
    
    //Кейс 4: массив с одним элементом
    vector<int> singleElementArr = {42};
    try {
        vector<int> singleElementResult = sampleArray(singleElementArr, 1);
        cout << "Массив с одним элементом: [";
        cout << singleElementResult[0] << "]" << endl; // Должен быть возвращён тот же элемент
        assert(singleElementResult.size() == 1 && singleElementResult[0] == 42);
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

    


// Посчитать алгоритмическую сложность 

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел; O(1)

    vector<int> arr = {1, 100, 100, 10, 2, 7, 20}; // Пример (датасет) массива; O(1)
    int K = 4;  // Количество элементов для выборки; присваивание - O(1)

    try {
        vector<int> result = sampleArray(arr, K); // Получаем сэмплированный массив; вызов функции -  O(N + K)

        // Выводим результат
        cout << "Сэмплированный массив: [";         // Вывод - O(1)
        for (size_t i = 0; i < result.size(); ++i) { // Проход по массиву - O(N)
            cout << result[i];                  // Вывод - O(1)
            if (i < result.size() - 1) { 
                cout << ", ";                   // Вывод - O(1)
            }
        }
        cout << "]" << endl; // Вывод - O(1)
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl; // Вывод - O(1)
    }
    
    testEdgeCases(); // Запуск тестов на крайние случаи

    return 0; // // Вывод - O(1)
}

    // Сложность алгоритма составляет:
    // O(N+K) - в худшем случае
    
    // O(N) (то есть скорее O(K), елси берём так, что K -
    // количество уникальных элементов, которые хотим выбрать из исходного массива, а
    // N - размер массива) - в худшем случае
    
    // ≈O(N+K) в среднем случае