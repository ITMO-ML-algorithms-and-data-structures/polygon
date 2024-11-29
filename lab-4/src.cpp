#include <iostream>
#include <vector>

using namespace std;

vector <int> d;
vector <vector <int>> r;
const int K = 6;

void gen(int i, int s, vector <int>& a) {
	
		if (s == 0 && d.size() == K) {
				r.push_back(d);
				return;
		}
		if (i == a.size() - 1) return;
		for (int j = i + 1; j < a.size(); j++) {
			d.push_back(j);
			gen(j, s + a[j], a);
			d.pop_back();
		}
}

vector <vector <int>> solve(vector <int> a){

	d.clear();
	r.clear();

	for (int i = 0; i < a.size(); i++) {
		d.push_back(i);
		gen(i, a[i], a);
		d.pop_back();
	}

	return r;
}