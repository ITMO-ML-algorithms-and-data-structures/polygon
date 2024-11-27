#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> comb_sort(vector<int>& arr)
{
	int length_arr = arr.size();
	int gap = length_arr;
	double shrink = 1.3;
	bool sorted = false;

	while (!sorted)
	{
		gap = int(gap / shrink);
		if (gap <= 1)
		{
			gap = 1;
			sorted = true;
		}

		for (int i = 0; i < length_arr - gap; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				swap(arr[i], arr[i + gap]);
				sorted = false;
			}
		}
	}
	return arr;
}

int main()
{
	ifstream input_file("test5.1.txt");

	vector<int> arr;
	int value;

	while (input_file >> value) {
		arr.push_back(value);
	}
	input_file.close();

	comb_sort(arr);
	for (int num : arr) cout << num << " ";
	cout << endl;
}