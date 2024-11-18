//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <cassert>

using namespace std;

// Функция для удаления дубликатов из вектора строк
vector<string> deletodinakovse(const vector<string>& input) {
    vector<string> result;
    map<string, bool> exist;
    for (const auto& str : input) {
        if (exist.count(str) == 0) {
            result.push_back(str);
            exist[str] = true;
        }
    }
    return result;
}

// Функция для тестирования deletodinakovse
void test_deletodinakovse() {
    // Тест 1: Общий случай
    vector<string> input1 = {"Orange", "Red", "Green", "Orange"};
    vector<string> expected1 = {"Orange", "Red", "Green"};
    assert(deletodinakovse(input1) == expected1);

    // Тест 2: Все уникальные элементы
    vector<string> input2 = {"Apple", "Banana", "Cherry"};
    vector<string> expected2 = {"Apple", "Banana", "Cherry"};
    assert(deletodinakovse(input2) == expected2);

    // Тест 3: Все элементы одинаковые
    vector<string> input3 = {"Blue", "Blue", "Blue", "Blue"};
    vector<string> expected3 = {"Blue"};
    assert(deletodinakovse(input3) == expected3);

    // Тест 4: Пустой вектор
    vector<string> input4 = {};
    vector<string> expected4 = {};
    assert(deletodinakovse(input4) == expected4);

    // Тест 5: Смешанный ввод
    vector<string> input5 = {"Red", "Blue", "Red", "Green", "Blue", "Yellow"};
    vector<string> expected5 = {"Red", "Blue", "Green", "Yellow"};
    assert(deletodinakovse(input5) == expected5);

    // Тест 6: Смешанные регистры
    vector<string> input6 = {"apple", "Apple", "APPLE", "banana", "Banana"};
    vector<string> expected6 = {"apple", "Apple", "APPLE", "banana", "Banana"};
    assert(deletodinakovse(input6) == expected6);

    cout << "Все тесты пройдены!" << endl;
}



vector <string> deletodinakovse() {
    vector <string> input={"Orange","Red","Green","Orange"};//24 байта * N
    map <string, int> exist;// 48*Количество уникальных слов
    int siz=input.size();//4 байта (не short, т.к. ограничение 10**9)
    auto  c=input.cbegin(); //8 байт (указатель, чтобы убирать значения по индексу (по сути c=i))
    for (int i; i<siz;i++){//4 байт
        if (exist.count(input[i])==1){
            input.erase(c);//- 24 байта за каждый дубликат
            siz--;
        }
        else{
            exist.insert(make_pair(input[i],1));
        }
        c++;
    }
    //24*N + 48*Количество уникальных слов + 16 байт, больше всего занимает словарь уникальных значений
    return input;//Вектор, ибо прописано в условии
}
int main() {
    vector <string> del = deletodinakovse();
    for (int i=0; i<del.size(); i++) {
        cout<<del[i]<<endl;
    }
    test_deletodinakovse();
    return 0;
}
