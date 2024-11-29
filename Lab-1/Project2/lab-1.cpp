#include <iostream>
#include <cstdlib> // для system
#include <set> // уникальные значения
using namespace std;

//Удалить дублирующиеся значения из входного массива

int function(int mas[], int n) {         // Создание функциии, которая принимает входной массив и его размер
	int sumn = 0;                            // Создание множества, откуда будут выходить значения, занимаемая память - 12 байтов 
	for (int i = 0; i < n; i++) {
		if (mas[i] % 3 == 0) {
			sumn++;
		}
	}
	return sumn;
}

void test1() {
	int n = 4;
	int mas[] = { 1, 2, 3, 1 };               // Занимаемая память 12 байт (нашли через sizeof)
	int sumn = function(mas, n);

	if (sumn == 1)
	{
		cout << "Test1 passed" << " ";
	}
	else {
		cout << "Test1 failed" << " ";
		cout << sumn << " ";
	}
}

void test2() {
	int n = 10;
	int mas[] = { 1, 2, 3, 3, 5, 6, 4, 6, 4, 2 };               // Занимаемая память 12 байт (нашли через sizeof)
	int sumn = function(mas, n);

	if (sumn == 4)
	{
		cout << "Test2 passed" << " ";
	}
	else {
		cout << "Test2 failed" << " ";
		cout << sumn << " ";
	}
}

int main()
{
	test1();
	//set<int>soul = set<int>{ 1, 2, 3, 1 };
	//std::cout << sizeof(soul) << "\n";
	std::cout << "\n";
	test2();
	return 0;
}