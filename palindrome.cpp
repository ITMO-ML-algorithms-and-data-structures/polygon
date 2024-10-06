//Найти индекс, с которого начинается последовательность, являющаяся палиндромом//
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string lane;
    string rev_lane = "";
    cout << "Enter a lane: ";
    cin >> lane;
    string lane2 = lane;
    int n = lane.size();
    bool flag = false;
    for (int j = 0; j < n; j++)
    {   
        string lane1 = lane.erase(0, j);
        int len = lane1.size();
        string rev_lane = "";
        if (lane1.size() == 0)
        {
            break;
        }
        for (int i = len-1; i >= 0; i--)
        {
            rev_lane += lane1[i];
        }
        if (rev_lane == lane1 && lane1.size() > 1)
        {
            cout << "The palindrome begins at the " << j << "th symbol" << endl;
            flag = true;
            break;
        }
        lane = lane2;
    }
    if (flag == false)
    {
        cout <<"No palindrome in line";
    }
    return 0;
}
