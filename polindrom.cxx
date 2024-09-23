
#include <map>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    bool flag = true;
    int array1[5] = {1,2,3,4,5};
    //int array1[5] = {5,6,7,6,5};
    //int array1[4] = {4,4,4,4};
    int n = sizeof(array1)/sizeof(array1[0]);
    //cout<<n;
    
    int array2[n];
    for(int i=n-1;i>=0;i--){array2[n-i-1]=array1[i];};
    
    for(int i=0;i<=n-1;i++){if(array2[i]!=array1[i]){flag = false;};};
    
    //cout << "\n";
    
    //for(int i = 0;i<= n-1;i++){cout<<"z";cout<<array1[i];cout<<array2[i];};
    
    if(flag==true){cout<<"polindrom";}
    else{cout<<"no";};
    
}