#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> comb_sort(vector<int>& arr) // 60 байт, O(N**2)
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

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void heapify(vector<int>& arr, int n, int i)
{
	int index_largest = i;
	int index_left = 2 * i + 1;
	int index_right = 2 * i + 2;

	if (index_left < n && arr[index_left] > arr[index_largest])
		index_largest = index_left;

	if (index_right < n && arr[index_right] > arr[index_largest])
		index_largest = index_right;

	if (index_largest != i) {
		swap(arr[i], arr[index_largest]);
		heapify(arr, n, index_largest);
	}
}

void heapSort(vector<int>& arr) // 84 байт, O(n log n)
{
	int n = arr.size();

	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

vector<int> countingSort(const vector<int>& arr) // 120 байт, O(n + k)
{

	int min_value = *min_element(arr.begin(), arr.end());
	int max_value = *max_element(arr.begin(), arr.end());

	int range = max_value - min_value + 1;

	vector<int> count(range, 0);

	for (int num : arr) {
		count[num - min_value]++;
	}

	for (int i = 1; i < count.size(); i++) {
		count[i] += count[i - 1];
	}

	vector<int> output(arr.size());

	for (int i = arr.size() - 1; i >= 0; i--) {
		int num = arr[i];
		output[count[num - min_value] - 1] = num;
		count[num - min_value]--;
	}

	return output;
}

int main()
{
	ifstream input_file("light_test.txt");
	vector<int> arr;
	int value;

	while (input_file >> value) {
		arr.push_back(value);
	}
	input_file.close();

	//heapSort(arr);
	//comb_sort(arr);
	//vector<int> arr = countingSort(arr);
	for (int num : arr) cout << num << " ";
	cout << endl;
}