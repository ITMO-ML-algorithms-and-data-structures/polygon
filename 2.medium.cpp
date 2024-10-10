#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
string IsIzoMorph(string str1, string str2) {
	unordered_set<char> letters;
	unordered_set<string> pairs;
	if (str1.size() != str2.size()) {
		return "false";
	}
	else {
		for (int i = 0; i < str1.size(); i++) {
			letters.emplace(str1[i]);
			pairs.emplace(string(1, str1[i]) + string(1, str2[i]));
		}
		if (letters.size() == pairs.size()) {
			return "true";
		}
		else {
			return "false";
		}
	}
}
