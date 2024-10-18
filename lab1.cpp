#include <iostream>
#include <vector>

using namespace std;

int main() {
    int answer = 0;
    int list_len;
    cin >> list_len;
    vector<int> list_of_digit(list_len);


    for (int i = 0; i < list_len; i++) { //создаём вектор 
        cin >> list_of_digit[i];
    }

    for (int k = 0; k < list_len; k++) {
        if(list_of_digit[k] > 0){ //проверка на положительность
            answer += list_of_digit[k];
        }
        
    }

    cout << answer << endl;

    return 0;
}
