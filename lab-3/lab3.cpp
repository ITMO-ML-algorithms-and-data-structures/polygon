#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}


int main(){
    int total = 0;
    int count = 0;
    int n;
    cin >> n;
    vector <std::string> a;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        a.push_back(temp);
        if (isInteger(temp)){
            total += stoi(temp);  
            }
        count += 1;   
    }
    int mid = total/count;
    auto mids = std::to_string(mid);
    cout << mids << " ";
    cout << "\n" << "";
    replace(a.begin(), a.end(), string{"null"} , mids);
    for (auto now : a) {   
        cout << now << " ";
    }
    return 0;

}