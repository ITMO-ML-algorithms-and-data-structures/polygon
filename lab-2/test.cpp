#include <cassert>
#include "src.cpp"

void test(){
	assert(solve("egg", "add"));
	assert(!solve("foo", "bar"));
	assert(solve("aaaa", "bbbb"));
	assert(solve("abcd", "efgh"));
	assert(!solve("aabb", "ggcd"));
	assert(!solve("aaaa", "aaa"));
	std::cout << "OK";
}

signed main(void){
	test();
	return 0;
}