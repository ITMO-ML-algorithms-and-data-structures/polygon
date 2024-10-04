#include <iostream>
#include <vector>

using namespace std;

int main(){
    int num = 1;
    int size;

    vector <int> arr{1, 2, 3, 1, 2, 5};

    size = arr.size();

    for(int i = 0; i < size - 1; i++){

        for(int j = i+1; j < size; j++){

            if((arr[i]-arr[j] == num) or (arr[j] - arr[i] == num)){

                cout << arr[i] << "-" << arr[j] << " " << "|" << " ";
            }
        }
    }
    return 0;
}