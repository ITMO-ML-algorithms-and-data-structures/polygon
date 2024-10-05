#include <iostream>

const int N = 10;
const int MAX_VALUE = 1000;

int MaxLength(int arr[]){
    int max_length = 0; //для хранения максимальной длины подмассива
    int start = 0; //для отслеживания начала текущего подмассива
    int flag[MAX_VALUE + 1];
    for (int i = 0; i <= MAX_VALUE; ++i){
        flag[i] = 0; //ни один элемент не встречался изначально
    }
    for (int i = 0; i < N; i++){
        while (flag[arr[i]] == 1){ //проверка на повтор
            flag[arr[start]] = 0; 
            ++start; //начало подмассива перемещаем правее(пока идет цикл)
        }
        flag[arr[i]] = 1; 
        max_length=std::max(max_length,i-start+1); //сравниваем текущее значение с длиной текущего подмассива
    }
    return(max_length);
}
int main(){
    int arr[N]={8,23,3,4,5,64,3,4,5,6};
    std::cout<< MaxLength(arr);
}