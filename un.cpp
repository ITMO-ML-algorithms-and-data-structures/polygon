#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <string>
#include <cassert>
using namespace std;

// Удаление дубликатов
// На вход 8 * N байт
vector<unsigned long long> unique(string filename)
{
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); //начало подсчета времени
    fstream data;
    data.open(filename);
    vector<unsigned long long> vec{}; // 8 * n байт    //вектор со всеми значениями
    vector<unsigned long long> un_vec{}; // 8 * n байт //вектор с уникальными значениями
    unsigned long long num;
    while (data >> num){ //O(1)
            vec.push_back(num); //O(n)  //перевод значений из файла в вектор
    }
    unordered_map<unsigned long long, bool> in_vector; 
    for (unsigned long long elem: vec) //O(n)
    {
        if (in_vector[elem] == false){  // 8 * n байт + память для буллевых значний C
            un_vec.push_back(elem); //O(n) //если значение не встречалось ранее, то добавляется в вектор с уникальными значениями
        }
        in_vector[elem] = true; //O(1)
    }
    
    std::chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now(); //конец подсчета времени
    chrono::duration<double> duration = end - start;
    cout << "Time: ";
    cout << duration.count() << " ";
    return un_vec;
}

// Сумма всех нотаций: O(n)
// В сумме 2n * 8 + n * 8 + c = 24n + C байта


vector<unsigned long long> open_file(string filename){
    fstream file;
    file.open(filename);
    vector<unsigned long long> v{};
    unsigned long long num;
    while (file >> num){ 
            v.push_back(num); 
    }
    return v;
}

int main(){

    vector<unsigned long long> tvec{1};
    assert(unique("tests/numbers5.txt") == open_file("tests/res1e6.txt")); //проверка базовой отработки
    cout << "Base test\n";
    assert(unique("tests/numbers1.txt").size() == 0); //пустой массив
    cout << "Empty test\n";
    assert(unique("tests/numbers2.txt") == tvec); //единственный элемент
    cout << "One elem test\n";
    assert(unique("tests/numbers3.txt") == tvec); //все элементы одинаковые
    cout << "Same elem test\n";
    assert(unique("tests/numbers.tsv").size() == 10000); //1e7 элементов
    cout << "Many elem test";

    return 0;
}