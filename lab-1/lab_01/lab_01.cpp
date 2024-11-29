#include <iostream> 
#include <string> // библиотека дл€ работы со строками
#include <vector> // библиотека дл€ динамических массивов
#include <unordered_map> // библиотека дл€ хранени€ пар ключ-значение"; примерно 100 байт 

using namespace std;

vector<int> values(const vector<string> arr, int size) { // объ€вление функции с параметрами динамического массива и его размера

    unordered_map<string, int> st_values;
    for (int i = 0; i < size; i++) {
        st_values[arr[i]]++; //создаЄм хэш-таблицу с значени€ми и ключами
    }

    vector<int> fin_arr(size); // создаЄм массив, который будем возвращать

    for (int i = 0; i < size; i++) {
        fin_arr[i] = st_values[arr[i]]; // дл€ значени€ в исходном массиве записываетс€ количество его вхождений
    }

    return fin_arr; 
}

void test1()
{
    vector<string> arr = { "Orange", "Red", "Green", "Orange" }; // 17 байт
    int size = 4;
    vector<int> arrive = values(arr, size);

    if (arrive == vector<int>{2, 1, 1, 2}) {
        cout << "Test1 passed";
    }
    else
    {
        cout << "Test1 failed";
        for (int i = 0; i < size; i++){
            cout << arrive[i] << " ";
        }
    }
}

int main()
{
    test1(); // 16 байт 
    return 0;
}
// примерно 130 байт 