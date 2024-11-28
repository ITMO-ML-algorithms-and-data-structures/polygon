#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

void sort(vector<double>& a) { //o(n^2) сортировка
	for (int i = 0; i < a.size(); i++) {
		double min = a[i];
		int min_ind = i;
		for (int j = i + 1; j < a.size(); j++) {
			if (a[j] < min) {
				min = a[j];
				min_ind = j;
			}
		}
		double c = a[i];
		a[i] = min;
		a[min_ind] = c;
	}
}

double allcost(const vector<double>& arr, const vector<int>& nu, int n) {// o(2n) находим цену разбиения
	double ans = 0;
	double cur = 0;
	int f = 0;
	for (int i = 0; i < n-1; ++i) {
		if (nu[i] == 0) {
			cur += arr[i];
			f += 1;
		}
		else {
			cur += arr[i];
			double h = cur / (f + 1);
			for (int g = 0; g <= f; ++g) {
				ans += abs(arr[i - f + g] - h);
			}
			cur = 0;
			f = 0;
		}
	}
	cur += arr[n - 1];
	double h = cur / (f + 1);
	for (int g = 0; g <= f; ++g) {
		ans += abs(arr[n - 1 - f + g] - h);
	}
	return ans;
}
vector<double> findClusters(const vector<double>& arr, int K) {// o(2^(n-1)) поребираем все концы скобочек при класторизации
	int n = arr.size();
	int g = 1 << (n - 1);
	vector<double> ans = { 9999999, 9999999.9 };
	for (int i = 0; i < g; ++i) {
		vector<int> nu(n, 0);
		int t = i;
		for (int j = n - 2; j >= 0; --j) {
			nu[j] = t % 2;
			t /= 2;
		}
		double cost = allcost(arr, nu, n);
		int s = 0;
		for (int j : nu) {
			s += j;
		}
		if (s == K - 1) {
			if (cost < ans[1]) {
				ans[0] = i;
				ans[1] = cost;
			}
		}
	}
	return ans;
}
int main() {
	vector<double> test1 = { 1, 2, 3, 4, 5, 6 };
	sort(test1);
	assert((findClusters(test1, 2)) == (vector<double> {4,4}));
	vector<double> test2 = {1, 10, 9, 2, 3, 8};
	sort(test2);
	assert((findClusters(test2, 2)) == (vector<double> {4, 4}));
	vector<double> test3 = {99.5, -1.1, 101};
	sort(test3);
	assert((findClusters(test3, 2)) == (vector<double> {2, 1.5}));
	vector<double> arr;
	int n;
	cin >> n;
	double inp;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		arr.push_back(inp);
		
	}
	int K;
	cin >> K;
	sort(arr);
	vector<double> ans = findClusters(arr, K);//o(n*2^n)
	int t = ans[0];
	vector<int> nu(n, 0);
	for (int j = n - 2; j >= 0; --j) {
		nu[j] = t % 2;
		t /= 2;
	}
	cout << "(";
	for (int i = 0; i < n - 1; ++i) {
		if (nu[i] == 0) {
			cout << arr[i] << ",";
		}
		else {
			cout << arr[i] << ")(";
		}
	}
	cout << arr[n - 1] << ")";
	return 0;
}