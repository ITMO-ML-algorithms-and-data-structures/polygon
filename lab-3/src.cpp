#include <iostream>
#include <vector>

using namespace std;

string conv(int x){
	if (x == 1) return "1";
	if (x == 2) return "2";
	if (x == 3) return "3";
	if (x == 4) return "4";
	if (x == 5) return "5";
	if (x == 6) return "6";
	if (x == 7) return "7";
	if (x == 8) return "8";
	else return "9";
}

string solve(string a){
	a += "$";
	int now = 1;
	string s = "";
	for (int i = 1; i < a.length(); i++){
		if (a[i] == a[i - 1]) now++;
		else {
			s += a[i - 1];
			s += conv(now);
			now = 1;
		}
	}
	return s;
}