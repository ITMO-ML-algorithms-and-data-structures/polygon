#include <iostream>
#include <cstdlib> // для system
using namespace std;

// Найти количество чисел в массиве, которые делятся на 3
int main()
{
	int n = 10;
	int A[10];

	// std::cout << sizeof(A) << "\n";

	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
	}

	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (A[i] % 3 == 0) {
			sum++;
		}
	}

	std::cout << "Sum number of massiv, which del 3: " << sum;
	return 0;
}