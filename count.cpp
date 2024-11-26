#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;


int count_sort(vector<int> arr, int n) {

    vector <int> c_arr(20001, 0);
    for (int i = 0; i < n; i++) {
      c_arr[arr[i] + 1000] += 1;
    }

    int c = 0;
    int j = 0;
    while (c < 20001) {
        if (c_arr[c] == 0) {
            c += 1;
        }
        else{
          arr[j] = c - 10000;
          c_arr[c] -= 1;
          j += 1;
        }
    }
    return 1;
}

int count1() {
    
    ifstream fin("data.txt");
    ofstream fout;
    fout.open("count_time.txt");
    for (int n = 1000; n <= 1000000; n += 1000) {

        vector<int> arr(n, 0);

        for (int i = 0; i < n; i++ ) {
            fin >> arr[i];
        }
        

        clock_t start = clock();
        count_sort(arr, n);
        clock_t end = clock();

        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        fout << n << " " << seconds << "\n";
    }
    fin.close();
    fout.close();
    cout << 1;
    return 1;
}

int count2() {
    ifstream fin("data.txt");
    ofstream fout("count_1e4.txt");
    int j;
    int n = 10000;
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
        count_sort(arr, n);
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
    count2();

}