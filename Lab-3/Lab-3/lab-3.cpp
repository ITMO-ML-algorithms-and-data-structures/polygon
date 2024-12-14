#include <iostream>
#include <ctime>
#include <cstdlib>

void function(int mas [], int n) {
	srand(time(0)); // ������ ��������� �����
	for (int i = 0; i < n; ++i)
		std::swap(mas[i], mas[std::rand() % n]); // ���������� ��� ��������
}

void test1() {
	const int n = 9;
	int mas[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };              // ���������� ������ 12 ���� (����� ����� sizeof)

	function(mas, n);
	for (int i = 0; i < n-1; i++) {
		std::cout << mas[i] << ",";
	}
	std::cout << mas[n-1];
}

int main() {

	test1();
	return 0;
}