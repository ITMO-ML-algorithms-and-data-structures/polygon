#include <iostream>
#include <cstdlib> // ��� system
#include <set> // ���������� ��������
using namespace std;

//������� ������������� �������� �� �������� �������

set<int> function(int mas[], int n) {         // �������� ��������, ������� ��������� ������� ������ � ��� ������
	set<int> mas2;                            // �������� ���������, ������ ����� �������� ��������, ���������� ������ - 12 ������ 
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
	int mas[] = { 1, 2, 3, 1 };               // ���������� ������ 12 ���� (����� ����� sizeof)
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
	int mas[] = { 1, 2, 3, 3, 5, 6, 4, 6, 4, 2 };               // ���������� ������ 12 ���� (����� ����� sizeof)
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