#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


void bucketSort(vector<int>& arr) {

    int maxElement = *max_element(arr.begin(), arr.end());
    int bucketCount = arr.size();
    vector<vector<int> > buckets(bucketCount);


    for (int i = 0; i < arr.size(); i++)
    {
        int index = (arr[i] * bucketCount) / (maxElement + 1);
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < bucketCount; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
}

int main()
{
    int n = 1000;

    ifstream infile("/Users/levr/всякое/pythonProject/dataset_1.txt");
    vector<int> arr(n);

    for (int u = 0; u < n; ++u)
    {
        infile >> arr[u];
        arr[u] = (arr[u] % 1000);
    }

    infile.close();
    bucketSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}