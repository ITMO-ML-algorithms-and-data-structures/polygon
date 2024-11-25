#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>
#include <random>
#include <unordered_map>
using namespace std;
    
vector<int> open_file(string filename){ //функция для перевода чисел из файла в вектор
    fstream file;
    file.open(filename); 
    vector<int> v{}; //n * 4 байт
    int num; // + 4 байт
    while (file >> num){  //O(n)
            v.push_back(num); //O(1)
    }
    file.close();
    return v;
}
// O(n) + O(1) = O(n)
// 4n + 4 байт

vector<int> shuffle(string filename){
    vector<int> vec = open_file(filename); //O(n) начальный вектор
    int vec_size = vec.size(); // n * 4 байт
    for (int i = vec_size-1; i > 1; i--){  //O(n) + 4 байт для i
        int num = rand() % (i+1); //+ 4 байт   берем случайное число из сужающего диапазона 1 - i
        swap(vec[num], vec[i]); //O(1) меням местами случайное число и число из конца диапазона
    }
    return vec;
    
}
// O(1) + O(n) + O(n) + O(1) = O(n)
// 4n + 4 + 4 + (4n + 4) = 8n + 12 байт (с учетом вспомогательного open_file)

vector<int> easy_shuffle(string filename){ // для оценки сравним разработанное перемешивание и готовое из библиотеки random
    vector<int> vec = open_file(filename);
    random_device rd; //базовый генератор чисел
    mt19937 g(rd()); //улучшеный генератор, где rd используется для инициализации
    shuffle(begin(vec), end(vec), g);
    return vec;
}


int Inversions(string filename, bool easy = false){ //для теста возьмем отсортированный массив, если программа хорошо перемешала числа, 
//то количество случаев, когда большее число стоит левее меньшего (количество инверсий) должно возрасти
    vector<int> vec{};
    if (easy == true){
        vec = easy_shuffle(filename); //готовое перемешивание
    }
    else{
        vec = shuffle(filename); //разработанное перемешивание
    }
    int count = 0;
    int vec_size = vec.size();
    for (int i = 0; i < vec_size-1; i++){
        for (int j = i+1; j < vec_size; j++){
            if (vec[i] > vec[j]){
                count++;
            }
        }
    }
    return count;
}

float Correlation(string filename, bool easy = false){ //если массив хорошо отсортирован, то и корреляция между оригинальным массивом 
//и отсортированным будет минимальна
    vector<int> vec_x = open_file(filename);
    vector<int> vec_y{};
    if (easy == true){
        vec_y = easy_shuffle(filename); //готовое перемешивание
    }
    else{
        vec_y = shuffle(filename); //разработанное перемешивание
    }
    int vec_size = vec_x.size(); 
    int sum_x = 0;
    int sum_y = 0;
    for (int num_x: vec_x){
        sum_x += num_x;
    }
    for (int num_y: vec_y){
        sum_y += num_y;
    }

    int mean_x = sum_x / vec_size;
    int mean_y = sum_y / vec_size;
    int first_sum = 0;
    int x_sq = 0;
    int y_sq = 0;
    for (int i = 0; i < vec_size; i++){
        first_sum += ((vec_x[i] - mean_x) * (vec_y[i] - mean_y));
        x_sq += pow((vec_x[i] - mean_x), 2);
        y_sq += pow((vec_y[i] - mean_y), 2);
    }
    float res = first_sum / (sqrt(x_sq) * sqrt(y_sq)); //Используется формула корреляции Пирсона
    return res;
}


bool no_duplicates(string filename){ //используется хеш-таблица т.к. во входном массиве могут содержаться повторяюзиеся значения
    vector<int> vec_orig = shuffle(filename);
    vector<int> vec_sh = shuffle(filename);
    unordered_map<int, int> count_sh;
    for (int num: vec_sh)
    {
        ++count_sh[num];
    }
    unordered_map<int, int> count_orig;
    for (int num: vec_sh)
    {
        ++count_orig[num];
    }
    
    return count_sh == count_orig;
}


int main(){
    srand((unsigned(time(0)))); //задаем сид для генерации случайного числа
    vector<int> tvec{1};
    vector<int> tvec_un{1,1,1,1,1,1,1,1,1,1};
    assert(shuffle("tests/test_emp").size() == 0); //проверка на пустой вектор
    cout << "Test empty done\n";
    assert(shuffle("tests/test_one") == tvec); //проверка на один элемент
    cout << "Test one element done\n";
    assert(shuffle("tests/test_un") == tvec_un);
    cout << "Test no new elements\n";
    cout << "No dublicates test: " << no_duplicates("tests/test_base.tsv") << '\n';
    cout << "My shuffle inversions count: " << Inversions("tests/sorted_base")<< ", " << "Easy shuffle inversions count: " << Inversions("tests/sorted_base", true) << '\n'; //проверка количества инверсий
    cout << "My shuffle correlation: " << Correlation("tests/test_base.tsv") << ", " << "Easy shuffle correlation: " << Correlation("tests/test_base.tsv", true) << '\n'; //проверка корреляции с оригинальным массивом
    assert(shuffle("tests/test_big.tsv") != open_file("tests/test_big.tsv")); //проверка производительности
    cout << "Test big done";


    return 0;
}
