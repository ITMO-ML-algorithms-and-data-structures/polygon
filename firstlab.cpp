#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int size;

    vector <int> arra = {1, 10, 148, 22, 16};

    size = arra.size();

    if(size % 2 == 0){
       cout << (arra[size/2] + arra[(size/2) - 1]) / 2;
    }
    else{
        cout << arra[size/2];
    }
    return 0;
}
