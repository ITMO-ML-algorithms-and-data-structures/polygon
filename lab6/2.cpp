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
	//s.push_back(-1);

	vector<int>a(1000, -1);
	vector<int>b(1000, -1);
	a[0] = 0;
	vector<vector<int>>c;
	for (int i = 0; i < s.size(); i++) {
		if (i % 100000000000 == 0) {
			c.push_back(a);
		}
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
	int max_ = -1;
	int last;
	//int last = 0;
	for (int i = 0; i < a.size(); i++) {
		if (max_ < a[i]) {
			max_ = a[i];
			last = i;
			//last = i;
		}
	}

	cout << max_ << endl;
	int sz = max_ - 1;
	//cout << last;
	a.clear();
	b.clear();
	//int temp;
	//if (s.size() > 1000) {
	//	temp = 1000;
	//}
	//else {
	//	temp = s.size();
	//}

	vector<int>ans;

	for (int i = c.size(); i > 0; i--) {
		vector<int>a_ = c[i - 1];
		vector<int>b_ = c[i - 1];
		vector<vector<int>>c_;
		//vector<map<int, int>>a_;
		//vector<map<int, int>>b_;
		//vector<map<int, int>>c_;
		for (int j = (i - 1) * 100000000000; j < (i) * 100000000000; j++) {
			for (int z = 0; z < b_.size(); z++) {

				if (s[j] - '0' >= z / 100) {
					int num = z % 100 * 10 + s[j] - '0';
					b_[num] = max(b_[num], a_[z] + 1);
					b_[z] = max(b_[z], a_[z]);
					//fs[num] = (fs[z] * 10) + s[j] - '0';
				}
			}
			//c_[j] = a_;
			a_ = b_;
			c_.push_back(a_);
			if (j + 1 == s.size()) { break; }
		}




		int cnt = (c_.size() * i);
		if (c_.size() != 100000000000) {
			cnt = s.size();
		}
		for (int j = c_.size() - 1; j > 0; j--) {
			cnt--;
			for (int z = 0; z < 10; z++) {
				int t = last / 100;
				int n = last % 100;
				int n1 = last / 10;
				if (s[cnt] - '0' == last % 10 && z <= (last % 10) && c_[j - 1][((z * 100) + n1)] == sz) {
					ans.push_back(last % 10);//last / 100             last % 100
					last = ((z * 100) + n1);//(n * 10) + z              (z * 100) + n
					sz--;
					//ans.push_back(last % 10);
					break;

				}
			}
		}
	}

	if (sz >= 0) ans.push_back(last % 10);
	//if (s[0] == '0') {
	//	ans.push_back(s[0] - '0');
	//}
	//if (s != "543210") {
	//	ans.push_back(last % 10);
	//}
	//ans.push_back(last % 10);
	for (int i = ans.size() - 1; i > -1; i--) {
		cout << ans[i];
	}
	return 0;
}
/*
543210
3
210

012345

*/
