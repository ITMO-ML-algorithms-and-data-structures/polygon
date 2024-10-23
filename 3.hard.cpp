#include <iostream>
#include <vector>
#include <string>
using namespace std;
string MixArr(int sizee, const vector<int>& arr1) {
	vector<int> arr2(sizee);
	for (int i = 0; i < sizee; i++) {
		arr2[(i + 1) % sizee] = arr1[i];
	}
	string res;
	for (int i = 0; i < sizee; i++) {
		res = res + to_string(arr2[i]) + ' ';
	}
	return res;
}