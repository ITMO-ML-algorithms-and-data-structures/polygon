#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long n ;
    fin >> n; 

    clock_t start = clock();
    vector <int> vec(n, 0); // вектор на n элементов int, n * 4 байт 
    for (long int i = 0; i < n; i++ ){
        fin >> vec[i];
    }
    fin.close();
    vector <vector <int>> ans;  // вектор векторов для ответов, до n(n-1)(n-2)(n-3) * 2/3 байт
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1 ; l < n; l ++){
                    if (vec[i] + vec[j] + vec[k] + vec[l] == 0) {
                        ans.push_back(vector<int> {i, j, k, l});
                    }
                }
            }
        }
    } 

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < 4; j++) {
            fout << ans[i][j] << " ";
        }
        fout << "\n";
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << seconds;
    return 0;
}