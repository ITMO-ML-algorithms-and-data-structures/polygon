#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

vector<int> beadSort(vector<int> a, int len) 
{
	int max = a[0]; 
	for (int i = 1; i < len; i++) { 
		if (a[i] > max) { 
			max = a[i]; 
		} 
	} 

	vector<vector<int>> beads;
	beads.resize(len);
	for (int i = 0; i < len; i++) {
		beads[i].resize(max);
		fill(beads[i].begin(), beads[i].end(), 0);
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < a[i]; j++) {
			beads[i][j] = 1;
		}
	}

	for (int j = 0; j < max; j++) {
		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum += beads[i][j];
			beads[i][j] = 0;
		} 
		for (int i = len-1; i >= len - sum; i--) { 
			beads[i][j] = 1;
		} 
	} 

	vector<int> result;
	result.resize(len);
	for (int i = 0; i < len; i++) {
		int sum = 0;
		for (int j = 0; j < max; j++) {
			sum += beads[i][j];
		}
		result[i] = sum;
	}
	return result;
}

int main(){
    vector<int> a = {60, 20, 40, 70, 30, 10};
    printf("Исходный массив\n");
	for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    vector<int> result = beadSort(a, 6);
    printf("\nОтсортированный массив\n");
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}