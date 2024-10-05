#include <iostream>
using namespace std;


int main(){
    int n,sum=0,mean;
    cout<<"Введите количество чисел в массиве: ";
    cin>>n;
    int arr[n];
    cout<<"Введите числа массива: ";
    for(int i=0;i<n;i++){ // i++ === i=i+1  ++i
        cin>>arr[i];
        sum = sum + arr[i]; // sum+=arr[i]
    }
    // cout<<"\nЭлементы массива:\n";
    // for(int i =0;i<n;i++){
    //     cout<<"Элемент с массива с индексом "<<i<<": "<<arr[i]<<endl;
    // }
    mean = sum/n; // 10/4 = 2.5 =>2
    int result = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]>mean){
            result++;
        }
    }
    cout<<"Количество чисел, которые больше чреднего арифметического: "<<result;
    return 0;
}
