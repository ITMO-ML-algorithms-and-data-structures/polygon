#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
string IsIzoMorph(string str1, string str2) { //80 byte
	unordered_set<char> letters;   //80+80 byte
	unordered_set<string> pairs;     //80+80+80 byte
	if (str1.size() != str2.size()) {    
		return "false";
	}
	else {
		for (int i = 0; i < str1.size(); i++) {
			letters.emplace(str1[i]); //80+80+80+1*i
			pairs.emplace(string(1, str1[i]) + string(1, str2[i])); //80+80+80+1*i+80*i = 240+81*i
		}
		if (letters.size() == pairs.size()) {
			return "true";
		}
		else {
			return "false";
		}
	}
}
int main(){
	string str1, str2;
	cin >> str1;
	cin >> str2;
	cout << IsIzoMorph(str1, str2);
}
