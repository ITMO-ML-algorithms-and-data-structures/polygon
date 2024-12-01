#include <iostream>
#include <vector>
using namespace std;

void flip(vector <int>& a, int l, int r){
	for (int i = 0; i <= (r - l) / 2; i++)
		swap(a[l + i], a[r - i]);
}

vector <int> pancakeSort(vector <int> a){
	for (int i = a.size() - 1; i >= 0; i--){
		
		int pos = i;
		for (int j = 0; j < i; j++){
			if (a[j] > a[pos]) pos = j;
		}

		if (pos == i) continue;

		if (pos != 0) flip(a, 0, pos);

		flip(a, 0, i);

	}
	return a;
}

vector <int> sort2(vector <int> a){
	return a;
}

vector <int> sort3(vector <int> a){
	return a;
}

// signed main(void){

// 	vector <int> a = {5, 4, 1, 2, 3};
// 	for (auto c : pancakeSort(a)){
// 		cout << c << " ";
// 	}

// 	return 0;
// }