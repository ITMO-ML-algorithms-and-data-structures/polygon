#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int>arr = {0, 1, 1, 2, 3, 6};
	int cnt = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 3 == 0) {
			cnt += arr[i];
		}
	}

	cout << cnt;

	return 0;
}