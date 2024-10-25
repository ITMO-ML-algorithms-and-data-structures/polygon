#include <iostream>
#include <vector>
#include <string>
using namespace std;
string MixArr(int sizee, const vector<int>& arr1) { //сдвиг, по сути перемешивание
	vector<int> arr2(sizee);
	for (int i = 0; i < sizee; i++) { //O(N)
		arr2[(i + 1) % sizee] = arr1[i];
	}
	string res;
	for (int i = 0; i < sizee; i++) { //O(N)
		res = res + to_string(arr2[i]) + ' ';
	}
	return res;
}
bool test(int sizee, const vector<int>& arr1, string arr2) {
	return (MixArr(sizee, arr1) == arr2);
}
int main() {
	cout << MixArr(5, { 1,2,3,4,5 });
	cout << (test(5, {1,2,3,4,5}, "5 1 2 3 4 "));
	cout << (test(5, {1,1,1,1,1}, "1 1 1 1 1 "));
	cout << (test(2, {1,2}, "1 2 "));
	cout << (test(4, {1,2,2,2}, "2 1 2 2 "));
}
