#include <iostream>
using namespace std;

int main()
{
	// У меня не получилось сделать ввод массива, поэтому прийдётся вводить его вручную заранее :(

	int arr[]{ 1, 2, 3, 4, 5, -7, 7, 3, 4, -1, 1, 8, 9, 0, 2 };
	int first_max = 0;
	int second_max = 0;

	for (int i = 0; i < size(arr); i++)
	{
		if (arr[i] > first_max) {
			second_max = first_max;
			first_max = arr[i];
		}
	}
	cout << second_max;
}