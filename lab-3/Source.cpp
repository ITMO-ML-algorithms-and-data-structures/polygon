#include <iostream>

using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int n, result;
	cout << "������ �������� �����:" << endl;
	cin >> n;

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 9, 10, 5 };

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		if (n == arr[i]) {
			result++;
		}

	}
	cout << "���������� ��������� � �������, ������ ��������� �����:" << " " << result;


	return 0;

}