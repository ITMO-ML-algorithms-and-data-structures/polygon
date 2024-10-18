#include "iostream"
#include "cassert"
#include "fstream"
#include "string"
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
	std::ifstream f;
	f.open("dataset.txt");
	std::string line;

	while (std::getline(f,line)){
		std::cout << line << " ";	
		std::cout << fun(line) << "\n";
	}
}
