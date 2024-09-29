#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <sstream>

using namespace std;
//получить массив с уникальными значениями из массива с 1e4 чисел с разделителем ; и значением от 1 до 31765
int main(){
    string nums_str; // 32 Б
    set<int> num_arr; // 4 Б
    ifstream file("input.txt"); // 472 Б
    getline(file, nums_str); 
    stringstream stream(nums_str); //392 Б
    string num; // 32 Б

    while(getline(stream, num, ';')){
        num_arr.insert(stoi(num)); //в конце получится 48 Б
    }
    for(int i : num_arr){
        cout << i << " ";// я хз как считать вес вывода
    }
    // на выходе имеем 976 Б занимаеные всеми переменными, проверено все через sizeof()
    
    return 0; 
}