#include <cassert>
#include <algorithm>
#include "src.cpp"
#define all(x) (x).begin(), (x).end()

bool isSorted(vector <int> a){
	for (int i = 0; i < a.size() - 1; i++)
		if (a[i] > a[i + 1]) return 0;
	return 1;
}

void testPancakeSort(){
	assert(isSorted(pancakeSort({5, 4, 3, 2, 1})));
	assert(isSorted(pancakeSort({5, 4, 2, 1, 1, 2, 4})));
	assert(isSorted(pancakeSort({1, 6, 3, 8, 1, 4, 9, 10})));
	printf("TEST 1 OK\n");
}

void testTreeSort(){
	assert(isSorted(treeSort({5, 4, 3, 2, 1})));
	assert(isSorted(treeSort({5, 4, 2, 1, 1, 2, 4})));
	assert(isSorted(treeSort({1, 6, 3, 8, 1, 4, 9, 10})));
	printf("TEST 2 OK\n");
}

void testCountingSort(){
	//assert();
	printf("TEST 3 OK\n");
}

signed main(void){
	testPancakeSort();
	testTreeSort();
	testCountingSort();
	return 0;
}