#include <cassert>
#include "src.cpp"

void testSolve(){
	assert(solve({1, 1, 2, 3, 4, 1, 1}) == 4);
	assert(solve({1, 2, 3, 1, 1, 2, 3, 4, 5, 1, 1}) == 5);
	assert(solve({1, 1, 1, 1, 1, 1}) == 1);
	assert(solve({5}) == 1);
	assert(solve({1, 2, 3, 4, 5, 6, 7, 8, 9}) == 9);
	std::cout << "OK";
}

signed main(void){
	testSolve();
	return 0;
}

