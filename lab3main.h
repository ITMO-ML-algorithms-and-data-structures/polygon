#ifndef NAME_H  
#define NAME_H

#include <iostream>
#include <fstream>
#include <string>  
#include <vector>
using namespace std;


void printarr(vector<char> arr){ // O(1)
    int n = arr.size(); // O(1) + O(1)
    for(int i=0; i<n;i++){int s = arr[i];cout<<s<<" ";}
} // O(n) ; O(1) + O(1)  + O(1) + O(1) ; O(1) + O(1) + O(1) + O(1)

vector<char> randomize(vector<char> arr){ // O(1) 
    int n = arr.size(); // O(1) + O(1)
    //vector<char> values(n);
    //srand(time(0));
	for(int i = 0;i<n;i = i +1){ // O(1) + O(1) +  O(1) + O(1) + O(1)
	    int rpos = rand(); // O(1) + O(1)
	    rpos = rpos%n; // O(1) + O(1)
	    int k = arr[i]; // O(1) + O(1)
	    arr[i] = arr[rpos]; // O(1)
	    arr[rpos] = k; // O(1) 
	    }
    return arr; 
}

vector<char> read_file(string name){ // O(1) 
    //vector<int> values[n];
    string line; // O(1) 
    std::ifstream in("ttt.txt"); 
    getline(in, line); // O(1) 
    
    int n = stoi(line); // O(1) + O(1)
    vector<char> values(n); // O(1) 
    //cout<<n;
    if (in.is_open()) {
        int i = -1; // O(1) + O(1)
        while (getline(in, line)) { // O(1) ;O(n+1)
            i = i+1; // O(1) 
            int int1 = stoi(line); // O(1) + O(1)
            //cout<<line;
            values[i] = int1; // O(1) 
            
        }
    }
 
    return values;
}
/*
int main(int argc, char *argv[])
{
    string name = "ttt.txt";
    vector<char> arr = read_file(name);
    arr = randomize(arr);
    int n = arr.size();
    for(int i=0; i<n;i++){int s = arr[i];cout<<s<<" ";}
}
*/
#endif

/*
само перемешивание массива содержит 1 цикл O(n), который в лучшем и худшем случае одинаков.
функция чтения файла тоже не зависит от массива и еë сложность O(n)
printarr также O(n)
*/
