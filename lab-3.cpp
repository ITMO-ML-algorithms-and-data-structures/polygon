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

int findMax(const vector<int> &vec) // O(n)
{
    int maxValue = numeric_limits<int>::lowest();

    for (int i = 0; i < vec.size(); i++) // O(n)
    {
        if (vec[i] > maxValue)
        {
            maxValue = vec[i];
        }
    }
    return maxValue; // O(1)
}

int findMin(const vector<int> &vec) // O(n)
{
    int minValue = numeric_limits<int>::max();

    for (int i = 0; i < vec.size(); i++) // O(n)
    {
        if (vec[i] < minValue)
        {
            minValue = vec[i];
        }
    }
    return minValue; // O(1)
}

void readVectorFromFile(vector<int> &vec, const string &filename) // O(n)
{
    ifstream file(filename);
    int value;

    while (file >> value) // O(n)
    {
        vec.push_back(value);
    }
    file.close(); // O(1)
}

vector<float> minMaxScaler(vector<int> &vec) // O(n)
{
    int minValue = findMin(vec); // O(n)
    int maxValue = findMax(vec); // O(n)

    vector<float> scaledVec(vec.size()); // O(n)

    for (int i = 0; i < vec.size(); i++) // O(n)
    {
        scaledVec[i] = static_cast<float>(vec[i] - minValue) / (maxValue - minValue); // O(1)
    }

    return scaledVec; // O(1)
}

int main()
{

    vector<int> vec; // O(1)
    string filename = "numbers10.txt"; // O(1)

    readVectorFromFile(vec, filename); // O(n)
    vector<float> scaledVec = minMaxScaler(vec); // O(n)

    cout << scientific << setprecision(1); // O(1)
    for (int i = 0; i < 10; i++) // O(n)
    {
        cout << scaledVec[i] << "   "; // O(1)
    }
}
// ИТОГ O(n) complexity