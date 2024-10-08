#include <iostream>

int main()
{
	int arr[]{ -10, -6, -2, -1, 0, 1, 2, 3, 4, 7 };
	int first_max = arr[0];
	int second_max;

	for (int i = 0; i < std::size(arr); i++)
	{
		if (arr[i] != first_max) { second_max = arr[i]; break; }
	}
	

	for (int i = 0; i < std::size(arr); i++)
	{
		if (arr[i] > first_max) {
			second_max = first_max;
			first_max = arr[i];
		}
	}
	std::cout << second_max;
}
