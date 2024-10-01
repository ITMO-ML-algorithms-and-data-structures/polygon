#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include<cmath>
#include <random>

 using namespace std;

int test_maker(int m){
    random_device rd;
    mt19937 gen(rd());
    string alph = "qwertyuiopasdfghjklzxcvbnm";
    ofstream test; //создания перемнной файла для изменения
    test.open("C:/Users/artem/Desktop/лабы/алгосы/test.txt");
    test << m << endl; //ввод кол-ва строк в файл
    string str; //переменная для записи строк
    uniform_int_distribution<> distrib_size_str(1, 1000); //ссоздания генератора кол-ва символов в строке
    uniform_int_distribution<> dustrib_char(0, 25); //создания генератора для символа из алфавита

    for (int i = 0; i < m; i++){
        short size_str = distrib_size_str(gen); //переменная рандомного числа кол-ва элементво строки
        for (short j = 0; j < size_str; j++){
            short _char = dustrib_char(gen); // перемнная рандомного символа из алфавита
            str.push_back(alph[_char]);
        }
        test << str << endl; // добавление строки в файл
        str.clear();
    }
    test.close();
    return 0;
}

 int main(){
     test_maker(pow(10, 3));
     unordered_map <string, short> repeats;
     ifstream input_file;
     input_file.open("C:/Users/artem/Desktop/лабы/алгосы/test.txt");
     int n;
     input_file >> n; //+4 байт
     string str; //+25 + size_str

     for (int i = 0; i < n; i++){ //+4 байта
        getline(input_file, str);
        if (repeats.find(str) != repeats.end()){
            repeats[str]++;
        }else{
        repeats[str] = 1;
        }
        str.clear();
     }
     //+(25 + size_str + 8 + 8 + 2) * n байт

     input_file.seekg(0);
     input_file >> n;
     ofstream ans;
     ans.open("C:/Users/artem/Desktop/лабы/алгосы/ans.txt");

     for (int i = 0; i < n; i++){
        getline(input_file, str);
        ans << repeats[str] << endl;
    }
    ans.close();
    return 0;
    //На выход 4 * n байт
    //Максимальное чило байт достигаться после заполнения repeats и равно
    //4 + 4 +(25 + средняя(size_str) + 8 + 8 + 2) * n байт
 }
