#include <iostream>
//light задача 10 варианта
int main() {
	setlocale(LC_ALL, "RU");
	int ram[11] = { -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 100 };
	int arf = 0;
	for (int a = 0; a < sizeof(ram) / sizeof(ram[0]); ++a) {
		arf += ram[a];
	}
	arf = arf / sizeof(ram)/sizeof(ram[0]);
	int ds = 0;
	for (int i = 0; i < sizeof(ram) / sizeof(ram[0]); ++i) {
		if (ram[i] > arf) {
			ds += 1;

		}
	}
	std::cout << "Количество элементов в массиве, которые больше среднего арифметического массива:" << ds;
	return 0;
}