#include <iostream>
#include <vector>
#include <set>
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
}
 
int main()
{
    vector<int> mass = {1, 2, 3, 2, 1, 4, 5, 3,67000, 67000};
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
}