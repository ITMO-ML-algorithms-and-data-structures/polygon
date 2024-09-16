#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int s;
    cout << "Enter seeking number:";
    cin >> s;
    int len = 52;
    cout << "Enter amount of numbers in vector:";
    cin >> len;
    vector<int> numbers(len);
    vector<pair<int, int>> pairs;
    cout << "Enter numbers:" << endl;
    for (int i = 0; i < len; i++){
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < len-1; i++)
    {
        for (int j = i + 1; j < len; j++) 
        {
            if (s == (numbers[i] + numbers[j]) and numbers[i] != numbers[i + 1])
            {
                pairs.push_back(make_pair(numbers[i], numbers[j]));
            }
        }
    }

    for (int i = 0; i < pairs.size(); i++) {
        cout << pairs[i].first << " " << pairs[i].second << endl;
    }

}
