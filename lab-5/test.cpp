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
	assert(isSorted(pancakeSort({10000, 100, 10000000, 111, 222})));
	assert(isSorted(pancakeSort({(int)1e6, (int)1e5, (int)1e6 - 10, (int)1e6 - 20})));
	printf("TEST 1 OK\n");
}

void test2(){
	//assert();
	printf("TEST 2 OK\n");
}

void test3(){
	//assert();
	printf("TEST 3 OK\n");
}

signed main(void){
	testPancakeSort();
	test2();
	test3();
	return 0;
}