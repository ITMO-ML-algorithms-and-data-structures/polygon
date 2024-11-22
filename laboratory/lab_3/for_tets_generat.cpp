#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    srand (static_cast <unsigned int> (time(nullptr)));
    ofstream file ("test3.txt");
    long long n = pow(10, 2);
    file << n << endl;
    int ind = 0;
    int ind_start = 1, ind_end = 10;
    int start = 1, end = 1000;
    for (long long i = 0; i < n; i++){
            
            if (ind == 0) {
                file << "null" << " ";
                ind = rand() % (ind_end - ind_start + 1) + ind_start;
            } else{
                file << rand() % (end - start + 1) + start << " ";
                ind--;
            }
    }
    file.close();
}