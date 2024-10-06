//Найти сумму всех чисел массива, которые кратны 3

#include <iostream>
using namespace std;

int main ()
{
    int u  = 0;
    int one [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i=0; i<10; i++) 
    { 
        if (one [i] %3 == 0){
            u = u + one [i] ;
        }
                
    }
    cout << u;

}
