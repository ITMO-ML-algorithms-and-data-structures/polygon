#include <cassert>
#include "src.cpp"

void test(){
	assert(solve("aaabb") == "a3b2");
	assert(solve("bbbccjjwww") == "b3c2j2w3");
	assert(solve("aaaaaa") == "a6");
	assert(solve("c") == "c1");
	std::cout << "OK";
}

signed main(void){
	test();
	return 0;
}