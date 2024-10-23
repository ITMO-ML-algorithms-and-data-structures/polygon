#include <iostream>
#include <vector>
using namespace std;
int main() {
	int sizee;
	cin >> sizee;
	cout << endl;
	vector<int> arr1(sizee);
	for (int i = 0; i < sizee; i++) {
		cin >> arr1[i];
	}
	vector<int> arr2(sizee);
	for (int i = 0; i < sizee; i++) {
		arr2[(i + 1) % sizee] = arr1[i];
	}
	for (int i = 0; i < sizee; i++) {
		cout << arr2[i] << ' ';
	}
}