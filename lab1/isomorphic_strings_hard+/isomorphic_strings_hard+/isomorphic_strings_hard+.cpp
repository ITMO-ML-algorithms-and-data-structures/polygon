#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string str1, string str2) {

	unordered_map<char, char> biection;

	int size1 = str1.size();

	if (size1 != str2.size()) {

		return false;
	}

	for (size_t i = 0; i != size1; ++i) {

		char curr_el1 = str1[i];
		char curr_el2 = str2[i];

		if (biection.find(curr_el1) == biection.end()) {

			biection[curr_el1] = curr_el2;
		}
		else {

			if (biection[curr_el1] != curr_el2) {

				return false;
			}
		}
	}

	return true;
}

int main() {

	setlocale(LC_ALL, "Russian");
	string s1, s2;
	cin >> s1 >> s2;

	bool out = isIsomorphic(s1, s2);

	cout << boolalpha << out;

	return 0;
}


