#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
	vector<int>arr0{1, 2, 3, 1}; // +24 байта
	vector<int>arr1{11, 23, 534, 652, 56, 256, 357, 64, 645, 6, 6, 565, 634, 45, 456, 54, 6, 145, 6, 61, 2, 3, 1}; // +24 байта

	int l0 = arr0.size(); // + 4 байта
	int l1 = arr1.size(); // +4 байта
 	set<int> as0; // +48 байта
	set<int> as1; // +48 байта

	for (int i = 0; i < l0; i++) {
		int r = arr0[i]; // + 4 байта * l0
		as0.insert(r);
	}
	for (int i = 0; i < l1; i++) {
		int r = arr1[i]; // + 4 байта * l1
		as1.insert(r);
	}
	cout << "Для 1 массива: " << endl;
    for (int elem : as0) {  // +4 байта 
        cout << elem << ' ';   
    }
	cout << endl << "Для 2 массива: " << endl;

	for (int elem : as1) {  // +4 байта 
        cout << elem << ' ';   
    }
	// На выходе получаем : 2*(24+4+48+4*l0)
	return 0;
}