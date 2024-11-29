#include <iostream>
#include <cstdlib> // для system
#include <set> // уникальные значения
using namespace std;

//Удалить дублирующиеся значения из входного массива

set<int> function(int mas[], int n) {         // Создание функциии, которая принимает входной массив и его размер
	set<int> mas2;                            // Создание множества, откуда будут выходить значения, занимаемая память - 12 байтов 
	for (int i = 0; i < n; i++) {
		mas2.insert(mas[i]);     
	}

	//std::cout << sizeof(mas2) << "\n";

	for (const int& i : mas2) {
		cout << i << " ";
	}

	return mas2;
}

void test1() {
	int n = 4;
	int mas[] = { 1, 2, 3, 1 };               // Занимаемая память 12 байт (нашли через sizeof)
	set<int> mas2 = function(mas, n);

	if (mas2 == set<int>{1, 2, 3})
	{
		cout << "Test1 passed" << " ";
	}
	else {
		cout << "Test1 failed" << " ";
		for (const int& i : mas2) {
			cout << i << " ";
		}
	}
}

void test2() {
	int n = 10;
	int mas[] = { 1, 2, 3, 3, 5, 6, 4, 6, 4, 2 };               // Занимаемая память 12 байт (нашли через sizeof)
	set<int> mas2 = function(mas, n);

	if (mas2 == set<int>{1, 2, 3, 4, 5, 6})
	{
		cout << "Test2 passed" << " ";
	}
	else {
		cout << "Test2 failed" << " ";
		for (const int& i : mas2) {
			cout << i << " ";
		}
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