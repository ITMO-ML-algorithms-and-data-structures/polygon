#include <iostream>
#include <vector>
#include <fstream>
#include <string>  
using namespace std;
vector<int> func(vector<int>numbers){
    vector<int>answer;
    for (int i = 0; i < size(numbers); i++){
        int isIn = 1;
        for (int j = 0; j < size(answer); j++){
            if (numbers[i] == answer[j]){
                isIn = 0;
                break;
            }
        }
        if (isIn){
            answer.push_back(numbers[i]);
        }
    }
    for (vector<int>::iterator i = answer.begin() ; i!=answer.end() ; ++i){
        cout<<*i;
        cout<<" ";
    }

    return answer;
}


int main() {       
    string line;
    ifstream in("tests_laba2.txt");
        if (in.is_open())
    {
        int c = 0;
        vector<int> vec;
        int size_vec;
        in >> size_vec;
        while (in >> c)
        {
            vec.push_back(c);
        }
        func(vec);
    }
    in.close(); 
    return 0;
}
