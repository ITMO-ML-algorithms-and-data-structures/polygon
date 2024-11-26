#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

int comb_sort(vector<int>& vec, int n) {
    // int j;
    // for (int i = 0; i < n * k; i++ ){
    //     j = i / k;
    //     fin >> vec[j];
    // }
    double factor = 1.25;  
    int step = n - 1; 
    while (step >= 1) {
        for (int i = 0; i + step < n; i++) {
            if (vec[i] > vec[i+step]) {
                swap(vec[i], vec[i + step]);
            }
        }
        step = step / factor;
    }
    return 1;
}
int count2 () {
    ifstream fin("data.txt");
    ofstream fout("comb_1e5.txt");
    int j;
    int n = 100000;
    vector<int> vec(1000000,0);

    for (int i = 0; i < 1000000; i++) {
            fin >> vec[i];
        }

    for (int k = 0; k <= 980000; k += 20000) {

        vector<int> arr(n, 0);

        for (int i = k; i < n + k; i++) {
            fin >> arr[i];
        }


        clock_t start = clock();
        comb_sort(arr, n);
        clock_t end = clock();

        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        fout << seconds << "\n";
    }
    fin.close();
    fout.close();
    cout << 1;
    return 0;
}

int main() {

    ifstream fin("data.txt");
    ofstream fout("comb_1e5.txt");
    int j;
    int n = 100000;
    vector<int> vec(1000000,0);

    for (int i = 0; i < 1000000; i++) {
            fin >> vec[i];
        }

    for (int k = 0; k <= 980000; k += 20000) {

        vector<int> arr(n, 0);

        for (int i = k; i < n + k; i++) {
            fin >> arr[i];
        }


        clock_t start = clock();
        comb_sort(arr, n);
        clock_t end = clock();

        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        fout << seconds << "\n";
    }
    fin.close();
    fout.close();
    cout << 1;
    return 0;
}
// Затраты по памяти: n*4 байта, где n - колличество элементов во входном массиве
// Ассимптотика: два вложенных цикла => примерная сложность O(n^2)