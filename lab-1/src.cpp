#define _CRT_SECURE_NO_WARNINGS

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>

#define ull unsigned long long

using namespace std;

int solve(vector <int> a){

	unordered_set <int> s;
	int n = a.size();
	ull mxlen = 0;
	int l = 0;

	for (int r = 0; r < n; r++){
		
		while (s.count(a[r])){
			s.erase(a[l]);
			l++;
		}

		s.insert(a[r]);
		mxlen = max(mxlen, s.size());
	}

	return mxlen;
}

/*

signed main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	//solve(a);

	return 0;
}

*/