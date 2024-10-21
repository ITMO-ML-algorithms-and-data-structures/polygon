#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <string>
using namespace std;
// подключение нужных библиотек для решения задачи

void test(const vector<long long>& res, const vector<long long>& exp){
    if(res == exp){
        cout << "good!!\n";
    }
    else{
        cout << "bad((\n";
    }
}

// функция для удаления дубликатов из вектора
vector<long long> solution(const string& myfile) {
    vector<long long> vec; // вектор с числами | максимум может содержать 1е9 значений => макс размер памяти 8 ГБ
    ifstream file(myfile);
    string line;
    // заполнение вектора данными из файла
    while (getline(file, line)){
        long long a = stoll(line);
        vec.push_back(a);
    }

    unordered_set<long long> map_seen;  // множество для отслеживания уникальных элементов | уникальных 1е4 значений => макс размер с доп данными примерно 160 КБ

    size_t index = 0;  // индекс для вставки уникальных элементов
    for (size_t i = 0; i < vec.size(); ++i) {
        if (map_seen.find(vec[i]) == map_seen.end()) {  // если элемент еще не был встречен
            map_seen.insert(vec[i]);  // добавляем элемент в множество
            vec[index++] = vec[i];  // переносим уникальный элемент в начало вектора
        }
    }
    // обрезаем вектор до нового размера, оставляя только уникальные элементы
    vec.resize(index);
    
    return vec;
}

int main() {

    vector<long long> res1 = solution("test1.txt");
    vector<long long> exp1 = {12345, 52341, 76452, 98989};
    test(res1, exp1);

    vector<long long> res2 = solution("test2.txt");
    vector<long long> exp2 = {};
    test(res2, exp2);
    
}

// итого будет где-то максимально 8 ГБ + 160 КБ + незначительные затраты типов line, size_t и буфер ввода fstream