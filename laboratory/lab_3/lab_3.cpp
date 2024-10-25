#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <cmath> 
#include <string>
#include <fstream> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <deque>

using namespace std;

int main(){
    ifstream fin("test1.txt");
    ofstream fein("test_result.txt");
    
    int n, ss = 0; fin >> n;
    vector <string> ass_str(n);

    for (int i = 0; i < n; ++i) {
        fin >> ass_str[i];
        if (ass_str[i] != "null")
            ss += stoi(ass_str[i]);
    }
    
    int aver = ss / n;
    fein << "average: " << aver << endl;
    for (int i = 0; i < n; ++i){
        if (ass_str[i] == "null")
            ass_str[i] = to_string(aver);

        fein << ass_str[i] << " ";
    }
}