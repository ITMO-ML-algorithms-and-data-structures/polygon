#include <random>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ofstream out;
    out.open("tests_laba2.txt");
    vector<int>vec;
    int x1 = pow(10,9);
    long long int x2 = 18 * pow(10,17);
    for (int i = 0; i < (abs(rand()) % x1); i++)
    {
        vec.push_back(abs(rand()) % x2);
    }
    if (out.is_open())
    {
        out<<size(vec);
        out<<"\n";
        for (vector<int>::iterator it = vec.begin() ; it!=vec.end() ; ++it)
        {
            out<<*it;
            out<<" ";
        }
    }
    out.close();
    cout << "Test has been created" << endl;
}