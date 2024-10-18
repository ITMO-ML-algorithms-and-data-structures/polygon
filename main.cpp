#include "iostream"
#include "cassert"


bool fun(std::string str){ //O(n)
	//std::string str = "((fqfqwfqwfqw))";
	int a = 0; //O(1)
	for(int i = 0; i < str.length();i++){ //O(n)
		if (str[i] == '('){ //O(1)
			a++; //O(1)
		}
		else if (str[i] == ')'){ //O(1)
			a--; //O(1)
		}
		if (a < 0){ //O(1)
			return true; //O(1)
		}
	}
	if (a > 0){ //O(1)
		return true; //O(1)
	}
	return false; //O(1)
}
int main(){
	std::cout << fun("(");
	assert(fun("(()))(") == true);
	assert(fun("") == false);
	assert(fun("()()()") == false);
	assert(fun("((((((((((((((((((((((((") == true);
	assert(fun(")") == true);
	assert(fun("a(b)(((a)b)") == true);	
}
