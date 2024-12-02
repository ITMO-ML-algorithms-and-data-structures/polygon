#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <random>
using namespace std;


void print_mas(const std::vector<int>& mas){
    for (int i = 0 ; i < mas.size(); i++){
        cout << mas[i] << " ";
    }
    cout << endl;
}

void man(int size_mas){

    //int size_mas;
    //cout<<"size: ";
    //cin >> size_mas;
    vector<int> mas(size_mas);
    srand(time(0));                     // random seed 
    for (int i = 0; i<size_mas; i++){
        mas[i] = rand() %10;           // random number to my mas 
    }
    //cout<<endl;
    //print_mas(mas);       //"start" rand mas 
    
    
    for (int i = 0; i<(size_mas-1); i++){   // swapper
        swap(mas[i], mas[rand() % (size_mas-i)]);
    }
    //print_mas(mas);
    
    cout << size_mas << ";" << clock()/1000.0 << endl; // время работы программы   
}

int main(){
    int qwe = 1000;
    for (int i = 1 ; i < qwe ; i++){
        man(i);
    }
}
