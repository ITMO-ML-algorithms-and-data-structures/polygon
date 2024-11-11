#include <iostream>

using namespace std;

// Найти сумму всех чисел массива, кратные 3

int main() {

	int list[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int summa_3 = 0;

	for (int i = 0; i < 15; i++) {
		if (list[i] % 3 == 0) {
			summa_3 += list[i];
		}
	}

	cout << summa_3;

	return 0;
}