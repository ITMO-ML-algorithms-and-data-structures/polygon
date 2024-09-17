#include <iostream>
//#include <vector>
using namespace std;

int main(){
    int mas[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int min = 100;

    cout << "mas: "; 
    for (int i = 0; i < 10; ++i){
        cout << mas[i] << " ";
    }

    for (int i = 0; i < 10; ++i){
        if (min > mas[i]){
            min = mas[i];
        }
    }
    cout << endl << "min in mas: " << min; 
    return 0;
}