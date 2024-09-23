//1
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main() {
//    vector <string> msg{ "Hello, world!" };
//
//    for (const string& word : msg)
//    {
//        cout << word << " ";
//    }
//    cout << endl;
//} 


// 3 light . Посчитать количество положительных чисел в массиве
#include <iostream>
using namespace std;

int count_positive_number(int N, int massive[]) {
	int positive_numbers = 0;

	for (int i = 0; i < N; i++) {
		if (massive[i] > 0) {
			positive_numbers += 1;
		}
	}
	return positive_numbers;
}


int main() 
{
	int massive[] = {1,2,3,4,5,-1,-2,-3,-4, 7,8,3,3,};
	int N = sizeof(massive) / sizeof(massive[0]);

	int positive_numbers = count_positive_number(N, massive);

	cout << "The number of positive numbers in the array: "<< positive_numbers << endl;
	cout << sizeof(massive);
	return 0;
}
