#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

void vanl(vector<int>a)
{
    map<int, int> elements;
    for (int i = 0; i < size(a); i++)
    {
        if (elements.count(a[i]))
        {
            elements[a[i]]++;
        }
        else
        {
            elements[a[i]] = 1;
        }
    }
    for (auto& item : elements)
    {
        if (item.second % 2 == 0)
        {
            cout << item.first << " ";
        }
    }
}

int main() {
    vector<int> vec;
    int c = 0;
    while (cin >> c)
    {
        vec.push_back(c);
    }
    vanl(vec);
    return 0;
}
