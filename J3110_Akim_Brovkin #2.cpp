#include <iostream>
#include <string>
#include <vector>
using namespace std;

int count(const vector<int>& arr, int target) {
int count = 0;
for (int element : arr) {
if (element == target)
count++;
}
return count;
}

int main() {
string string1, string2;
cin >> string1;
cin >> string2;

string string1_01 = "";
string string2_01 = "";

vector<int> arr1;
vector<int> arr2;

for (int i = 0; i < string1.length(); i++) {
arr1.push_back(string1[i]);
}

for (int i = 0; i < string2.length(); i++) {
arr2.push_back(string2[i]);
}

for (int i = 0; i < arr1.size(); i++) {
    int countResult1 = count(arr1, arr1[i]);
    string countStr1 = to_string(countResult1);
    string1_01.append(countStr1);
}

for (int i = 0; i < arr2.size(); i++) {
    int countResult2 = count(arr2, arr2[i]);
    string countStr2 = to_string(countResult2);
    string2_01.append(countStr2);
}
if (string1_01 == string2_01)
cout << "true";
else
cout << "false";

return 0;
}
