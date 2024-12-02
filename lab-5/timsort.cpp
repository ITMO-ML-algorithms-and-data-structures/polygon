#include <fstream>
#include <vector>
#include <ctime>
#include <string>
const int MIN_MERGE = 32;

using namespace std; 


// Сортировка вставками. Так как на вход подаются очень маленькие подмассивы, при это частично отсортированные 
// в среднем O(k^2) где k = MIN_MERGE
void insertionSort(vector<long int>& arr, long int left, long int right) {
    for (long int i = left + 1; i <= right; i++) {
        long int temp = arr[i];
        long int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
// Функция соеденения подмассивов 
// O(k)
void merge(vector<long int>& arr, long int left, long int mid, long int right) {
    long int len1 = mid - left + 1, len2 = right - mid;
    vector<int> leftArr(len1), rightArr(len2); // дополнительные O(n)
    for (long int i = 0; i < len1; i++)
		leftArr[i] = arr[left + i];
    for (long int i = 0; i < len2; i++)
	 	rightArr[i] = arr[mid + 1 + i];
	 	
    long int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }
    while (i < len1) arr[k++] = leftArr[i++];
    while (j < len2) arr[k++] = rightArr[j++];
}


// Вычисление minrun ~O(1)
long int calculateMinRun(long int n) {
    long int r = 0;
    while (n >= MIN_MERGE) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}
// Реализация самого алгоритма сортировки
// Финальная асимптотика O(n*log(n))
void timSort(vector<long int>& arr) {
    long int n = arr.size();
    long int minRun = calculateMinRun(n);
    // Cортировка подмассивов длинны minrun
    for (long int i = 0; i < n; i += minRun) {
        insertionSort(arr, i, min(i + minRun - 1, n - 1));
    }
    // Объединение runs
    for (long int size = minRun; size < n; size = 2 * size) {
        for (long int left = 0; left < n; left += 2 * size) {
            long int mid = left + size - 1;
            long int right = min(left + 2 * size - 1, n - 1);
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}


void tests(){
	ofstream fout("output_test_tim.txt");
	ofstream fout_time("output_time_tim.txt");
	for (int i=0; i<7; i++){
		long int n;  
		clock_t start, end;
		start = clock();
		string a = to_string(i) + "input.txt";
		fstream fin(a);
		fin >> n; 
		vector <long int> data(n); 
		for (long int i=0; i<n; i++){
			fin >> data[i]; 
		}
		timSort(data);
		
		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
		fout_time << time_taken << ' ';
		
//		for (long int i=0; i<n; i++)
//			fout << data[i] << ' ';
		fin.close();
	}
	fout_time.close();
	fout.close();
	
}

int main() {
	tests();
	ifstream fin("input.txt");
	long int n = 0;
	fin >> n;
	vector<long int> arr(n);
	for (long int i = 0;i<n; i++ ) {
		fin >> arr[i];
	}
    fin.close();
    timSort(arr);
    ofstream fout("output.txt");
    for (long int num : arr) {
        fout << num << " ";
    }
    fout.close();
    return 0;
}
