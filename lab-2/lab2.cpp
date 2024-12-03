#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <string> arr;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }


    vector <int> final_arr;
    int counter = 0;
    std::string target = "raz";
    for (int i = 0; i < n; i++){
        std::string target = arr[i];
        for (int j = 0; j < n; j++) {
        // Check if the current element equals the target
        // number
        if (arr[j] == target) {
            counter++;
        }
    }
    final_arr.push_back(counter);
    counter = 0;
    }
    
    for (auto now : final_arr) {
        cout << now << " ";
    }
    return 0;

}