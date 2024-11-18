#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
void duplicates(vector<int>& mass) {
    set<int> uniqu;
    vector<int> result;
    for (int num : mass)
    {
        uniqu.insert(num);
    }
    for (int uniq : uniqu)
    {
        result.push_back(uniq);
    }
    mass = result;
   // cout<<endl<<sizeof(uniqu);
    //cout<<endl<<sizeof(result);
}
 
int main()
{
    vector<int> mass;
    ifstream input;
    input.open("C:\\Users\\oleg-\\numbers.txt");
    if (!input) { 
        cout << "Не";
        return 1; 
    }
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        string number;
        while (getline(ss, number, '\t')) {
            mass.push_back(stoi(number));
        }
    }
   // cout<< sizeof(mass);
    cout << "massiv";
    for (int num : mass)
    {
        cout << num << " ";
    }
    duplicates(mass);
    cout << endl;
    cout << "otvet";
    for (int num : mass)
    {
        cout << num << " ";
    }
   // cout<<endl<<sizeof(mass);
    
}
//mass = 24 + 4*n
//result = 24 + 4*n
//uniqu = 48 + 4*n
//Num = 4
//100 + 12n