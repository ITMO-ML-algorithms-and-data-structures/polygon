//1 

#include <iostream>
#include <vector>

int main() {
	std::vector<int>vec{ 1,2,3,4,5 ,1,2,1,3,4,1,4,2,1,5,1 };
	int len= vec.size();
	int c = 1;
	int kol = 0;
	for (int i = 0; i < len; ++i) {
		if (vec[i] == c) {
			++kol;
		}
	}
	std::cout << kol;
	return 0;
}

#include <iostream>

int main() {
	int i = 0;
	for(int t = 0 )
}