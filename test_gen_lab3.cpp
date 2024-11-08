#include <random>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ofstream out;
    srand(static_cast<unsigned int>(time(0)));
    out.open("tests_laba3.txt");
    vector<int>vec;
    int x1 = pow(10,2);
    long long int x2 = pow(10,2);
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