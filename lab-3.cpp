#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>

using std::cout;
using std::ifstream;
using std::numeric_limits;
using std::scientific;
using std::setprecision;
using std::string;
using std::vector;

int findMax(const vector<int> &vec)
{
    int maxValue = numeric_limits<int>::lowest();

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > maxValue)
        {
            maxValue = vec[i];
        }
    }
    return maxValue;
}

int findMin(const vector<int> &vec)
{
    int minValue = numeric_limits<int>::max();

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < minValue)
        {
            minValue = vec[i];
        }
    }
    return minValue;
}

void readVectorFromFile(vector<int> &vec, const string &filename)
{
    ifstream file(filename);
    int value;

    while (file >> value)
    {
        vec.push_back(value);
    }
    file.close();
}

vector<float> minMaxScaler(vector<int> &vec)
{
    int minValue = findMin(vec);
    int maxValue = findMax(vec);

    vector<float> scaledVec(vec.size());

    for (int i = 0; i < vec.size(); i++)
    {
        scaledVec[i] = static_cast<float>(vec[i] - minValue) / (maxValue - minValue);
    }

    return scaledVec;
}

int main()
{

    vector<int> vec;
    string filename = "numbers.txt";

    readVectorFromFile(vec, filename);
    vector<float> scaledVec = minMaxScaler(vec);

    cout << scientific << setprecision(1);
    for (int i = 0; i < 100; i++)
    {
        cout << scaledVec[i] << " ";
    }
}
