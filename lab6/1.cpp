#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string s;
	int target;
	cin >> s;

	vector<int>a(1000, -1);
	vector<int>b(1000, -1);
	a[0] = 0;
	for (int i = 0; i < s.size(); i++) {

		for (int j = 0; j < a.size(); j++)
		{

			if (s[i] - '0' >= j / 100) {
				int num = j % 100 * 10 + s[i] - '0';
				b[num] = max(b[num], a[j] + 1);
				b[j] = max(b[j], a[j]);
			}
		}
		a = b;
		//b.clear();
		//b.resize(1001, -1);
	}

	int max = -1;
	for (int i = 0; i < a.size(); i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	cout << max;
	return 0;
}