
#include <list>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    bool flag = true;
    int array1[5] = {1,2,3,4,5};
    //int array1[5] = {5,6,7,6,5};
    int n = 5;
    int array2[5];
    for(int i=n-1;i>=0;i--){array2[n-i-1]=array1[i];};
    
    for(int i=0;i<=4;i++){if(array2[i]!=array1[i]){flag = false;};};
    
    cout << "\n";
    
    //for(int i = 0;i<= 4;i++){cout<<array1[i];cout<<array2[i];};
    
    if(flag==true){cout<<"polindrom";}
    else{cout<<"no";};
    
}