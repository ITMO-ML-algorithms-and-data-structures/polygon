#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <algorithm>
#include "src.cpp"
#define all(x) (x).begin(), (x).end()

bool isSorted(vector <int> a){
	for (int i = 0; i < a.size() - 1; i++)
		if (a[i] > a[i + 1]) return 0;
	return 1;
}

vector <int> T;

void testPancakeSort(){
	assert(isSorted(pancakeSort({5, 4, 3, 2, 1})));
	assert(isSorted(pancakeSort({5, 4, 2, 1, 1, 2, 4})));
	assert(isSorted(pancakeSort({1, 6, 3, 8, 1, 4, 9, 10})));

	assert(isSorted(pancakeSort({1, 2, 3, 4, 5})));

	assert(isSorted(pancakeSort(T)));

	printf("TEST 1 OK\n");
}

void testTreeSort(){
	assert(isSorted(treeSort({5, 4, 3, 2, 1})));
	assert(isSorted(treeSort({5, 4, 2, 1, 1, 2, 4})));
	assert(isSorted(treeSort({1, 6, 3, 8, 1, 4, 9, 10})));

	assert(isSorted(treeSort({1, 2, 3, 4, 5})));

	assert(isSorted(treeSort(T)));

	printf("TEST 2 OK\n");
}

void testCountingSort(){
	assert(isSorted(countingSort({5, 4, 3, 2, 1})));
	assert(isSorted(countingSort({5, 4, 2, 1, 1, 2, 4})));
	assert(isSorted(countingSort({1, 6, 3, 8, 1, 4, 9, 10})));

	assert(isSorted(countingSort({1, 2, 3, 4, 5})));	

	assert(isSorted(countingSort(T)));

	printf("TEST 3 OK\n");
}

signed main(void){

	freopen("test.txt", "r", stdin);

	int t;
	while (cin >> t){
		T.push_back(t);
	}

	testPancakeSort();
	testTreeSort();
	testCountingSort();
	return 0;
}