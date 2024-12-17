#include <array>
#include <iostream>
#include <vector>

#include <algorithm>
#include <random>

template <typename type_array>
void cycle_sort(type_array *Array, int array_size)
{
	for (int cycle_start = 0; cycle_start < array_size - 1; cycle_start++)
	{
		type_array item = Array[cycle_start];

		int pos = cycle_start;
		for (int i = cycle_start + 1; i < array_size; i++)
			if (Array[i] < item)
				pos += 1;
		if (pos == cycle_start)
			continue;
		while (item == Array[pos])
			pos += 1;

		std::swap(Array[pos], item);

		while (pos != cycle_start)
		{
			pos = cycle_start;
			for (int i = cycle_start + 1; i < array_size; i++)
				if (Array[i] < item)
					pos += 1;
			while (item == Array[pos])
				pos += 1;

			std::swap(Array[pos], item);
		}
	}
}

void combSort(int data[], int n) {
	int step = n;
	bool flag = false;
	while (step > 1 or flag) {
		if (step > 1) {
			step = step * 4 / 5;
		}
		flag = false;
		int i = 0;
		while (i + step < n) {
			if (data[i] > data[i + step]){
				flag = true;
				std::swap(data[i], data[i + step]);
			}
			i += step;
		}
	}
}

void insertionSort(std::vector<int>& bucket) {
	for (int i = 1; i < bucket.size(); ++i) {
		int key = bucket[i];
		int j = i - 1;
		while (j >= 0 && bucket[j] > key) {
			bucket[j + 1] = bucket[j];
			--j;
		}
		bucket[j + 1] = key;
	}
}


void bucketSort(int arr[], int n) {
	if (n <= 0) return;
	int minValue = arr[0], maxValue = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[i] < minValue) minValue = arr[i];
		if (arr[i] > maxValue) maxValue = arr[i];
	}
	int bucketCount = 10;
	int range = (maxValue - minValue + 1);
	int bucketSize = std::max(1, range / bucketCount);
	std::vector<std::vector<int>> buckets(bucketCount);
	for (int i = 0; i < n; ++i) {
		int bucketIndex = (arr[i] - minValue) / bucketSize;
		if (bucketIndex >= bucketCount) bucketIndex = bucketCount - 1;
		buckets[bucketIndex].push_back(arr[i]);
	}
	for (int i = 0; i < bucketCount; ++i) {
		insertionSort(buckets[i]);
	}
	int index = 0;
	for (int i = 0; i < bucketCount; ++i) {
		for (int value : buckets[i]) {
			arr[index++] = value;
		}
	}
}
