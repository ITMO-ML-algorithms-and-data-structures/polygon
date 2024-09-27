//найти сумму всех чётных чисел в массиве
#include <iostream>
#include <vector>

int sumOfEvenNumbers(const std::vector<int>& array) {
	int sum = 0;
	for (int num : array) {
		if (num % 2 == 0) {
			sum += num;
		}
	}
	return sum;
}
int main() {
	std::vector<int> masif = {1,7,9,3,4};
	int Summ = sumOfEvenNumbers(masif);
	std::cout << Summ << std::endl;
	return 0;
}
