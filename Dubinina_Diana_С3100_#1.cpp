/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main(){
    int const size = 11; 
    int arrayofnumbers[size] = {-5,-4,-3,-2,-1, 0, 1, 2, 3, 4, 5 }; 
    int count = 0; 
    for (int i=0;i<size;i++){  
        if(arrayofnumbers[i] < 0){ 
            count +=1; 

        }

    }
    cout << count;
    
}