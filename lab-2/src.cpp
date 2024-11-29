#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool solve(string a, string b){
	map <char, char> m;

	if (a.length() != b.length()) return 0;

	for (int i = 0; i < a.length(); i++){
		if (m[a[i]] == b[i]) continue;
		
		if (!m[a[i]]) m[a[i]] = b[i];
		else return 0;

	}

	return 1;
}