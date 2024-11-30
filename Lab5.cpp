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

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void heapify(vector<int>& arr, int n, int i) {
	int largest = i;  
	int left = 2 * i + 1;  
	int right = 2 * i + 2;  

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(vector<int>& arr) {
	int n = arr.size();

	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
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