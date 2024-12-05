#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <fstream> 

using std::string;

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    std::vector<int> prev(m+1, 0), curr(m+1, 0);
    prev[0] = 1;
    curr[0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s[i-1] == t[j-1]) 
                curr[j] = prev[j-1] + prev[j];
            else
                curr[j] = prev[j];
        }
        prev = curr;
    }
    return curr[m];
}

int main() {
    std::ifstream data_set("dataset.txt");
    std::ofstream test("test.txt", std::ios::app);

    string element; // 32 байта
    string s; // 24 байта

    while (getline(data_set, element, ';')) 
        s += element;

    string t;
    for (int i=0; i<=s.size(); i++)
        t.push_back(s[i]);

    std::cout << numDistinct(s, t);
}