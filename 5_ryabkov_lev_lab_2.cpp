#include <unordered_set>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    unordered_set<int> viewed;
    list<int> out_list;
    int arr_lenght = 10000000;
    int arr[arr_lenght];

    ifstream infile("dataset.txt");
    for (int u = 0; u < arr_lenght; ++u)
    {
        infile >> arr[u];
    }
    infile.close();

    for (int i = 0; i < arr_lenght; i++)
    {
        if (viewed.find(arr[i]) == viewed.end())
        {
            out_list.push_back(arr[i]);
            viewed.insert(arr[i]);
        }
    }

    vector<int> out(out_list.begin(), out_list.end());
    cout << "новый массив: ";

    for (size_t i = 0; i < out.size(); ++i)
    {
        cout << out[i] << " ";
    }

    cout << endl;
    return 0;
}
