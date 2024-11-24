#include <cassert>
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace std;

const int RUN_SIZE = 32;

void insertionSort(vector<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void merge(vector<int>& arr, int l, int m, int r) {
	int len1 = m - l + 1, len2 = r - m;
	vector<int> left(len1), right(len2);

	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < len1 && j < len2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		} else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < len1) {
		arr[k] = left[i];
		k++;
		i++;
	}

	while (j < len2) {
		arr[k] = right[j];
		k++;
		j++;
	}
}

void timSort(vector<int>& arr) {
	int n = arr.size();

	for (int i = 0; i < n; i += RUN_SIZE) {
		insertionSort(arr, i, min((i + RUN_SIZE - 1), (n - 1)));
	}

	for (int size = RUN_SIZE; size < n; size *= 2) {
		for (int left = 0; left < n; left += 2 * size) {
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1), (n - 1));
			if (mid < right) {
				merge(arr, left, mid, right);
			}
		}
	}
}

bool arraysEqual(const vector<int>& arr1, const vector<int>& arr2) {
    if (arr1.size() != arr2.size()) return false;
    for (size_t i = 0; i < arr1.size(); i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

void test_timsort() {
    // Тест 1: Пустой массив
    vector<int> arr1 = {};
    timSort(arr1);
    assert(arr1 == vector<int>({}));

    // Тест 2: Массив с одним элементом
    vector<int> arr2 = {42};
    timSort(arr2);
    assert(arr2 == vector<int>({42}));

    // Тест 3: Массив с дублирующимися элементами
    vector<int> arr3 = {5, 3, 3, 2, 5, 1};
    timSort(arr3);
    assert(arr3 == vector<int>({1, 2, 3, 3, 5, 5}));

    // Тест 4: Уже отсортированный массив
    vector<int> arr4 = {1, 2, 3, 4, 5};
    timSort(arr4);
    assert(arr4 == vector<int>({1, 2, 3, 4, 5}));

    // Тест 5: Массив с уже отсортированными значениями в обратном порядке
    vector<int> arr5 = {5, 4, 3, 2, 1};
    timSort(arr5);
    assert(arr5 == vector<int>({1, 2, 3, 4, 5}));

    // Тест 6: Массив с отрицательными числами
    vector<int> arr6 = {-1, -3, -2, -4};
    timSort(arr6);
    assert(arr6 == vector<int>({-4, -3, -2, -1}));

    cout << "Tests passed" << endl;
}

int main() {
	// Пример использования - средний случай
    vector<int> arr = { 1, 7, 8, 2, 3, 5, 4, 6 };
    timSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

	// Тесты
    test_timsort();

	// Подсчет времени работы в зависимости от числа элементов
	vector<int> sizes;
	vector<double> times;

	for (int n = 100000; n <= 1000000; n += 100000) {
		sizes.push_back(n);
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			arr[i] = rand() % 10000;
		}

		auto start = chrono::high_resolution_clock::now();
		timSort(arr);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;
		times.push_back(duration.count());
	}

	// Сохранение данных для графика
	ofstream outFile("tim_sort_times.txt");
	for (size_t i = 0; i < sizes.size(); ++i) {
		outFile << sizes[i] << " " << times[i] << endl;
	}
	outFile.close();

    // Boxplot
    const int num_runs = 50;

    // Для массива размером 10^4
    ofstream outFile10000("3 timing_10000.txt");
    for (int run = 0; run < num_runs; run++) {
        vector<int> arr(10000);
        for (int i = 0; i < 10000; ++i) {
            arr[i] = rand() % 10000;
        }

        auto start = chrono::high_resolution_clock::now();
        timSort(arr);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        outFile10000 << duration.count() << endl;
    }
    outFile10000.close();

    // Для массива размером 10^5
    ofstream outFile100000("3 timing_100000.txt");
    for (int run = 0; run < num_runs; run++) {
        vector<int> arr(100000);
        for (int i = 0; i < 100000; ++i) {
            arr[i] = rand() % 100000;
        }

        auto start = chrono::high_resolution_clock::now();
        timSort(arr);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        outFile100000 << duration.count() << endl;
    }
    outFile100000.close();

    return 0;
}
