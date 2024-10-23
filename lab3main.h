#ifndef NAME_H  
#define NAME_H

#include <iostream>
#include <fstream>
#include <string>  
#include <vector>
using namespace std;


void printarr(vector<char> arr){
    int n = arr.size();
    for(int i=0; i<n;i++){int s = arr[i];cout<<s<<" ";}
}

vector<char> randomize(vector<char> arr){
    int n = arr.size();
    //vector<char> values(n);
    //srand(time(0));
	for(int i = 0;i<n;i = i +1){ // 4*
	    int rpos = rand(); // 4*
	    rpos = rpos%n;
	    int k = arr[i]; //4*
	    arr[i] = arr[rpos];
	    arr[rpos] = k;
	    }
    return arr;
}

vector<char> read_file(string name){
    //vector<int> values[n];
    string line;
    std::ifstream in("ttt.txt"); 
    getline(in, line);
    
    int n = stoi(line);
    vector<char> values(n);
    //cout<<n;
    if (in.is_open()) {
        int i = -1;
        while (getline(in, line)) {
            i = i+1;
            int int1 = stoi(line);
            //cout<<line;
            values[i] = int1;
            
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
