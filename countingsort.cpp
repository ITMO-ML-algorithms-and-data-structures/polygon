#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]){
    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }
    string line;
    vector<int> arr;
    if (getline(inputFile, line)) {
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, '\t')) {
            arr.push_back(stoi(cell));
        }
    }
    inputFile.close();
    clock_t begin = clock();

    int sizee = arr.size();
    int maximum = 0;

    for (int i = 0; i < sizee; i++) {
        maximum = max(arr[i], maximum);
    }

    vector<int> pref_summa(maximum + 1, 0);

    for (int i = 0; i < sizee; i++) {
        pref_summa[arr[i]]++;
    }
    for (int i = 1; i <= maximum; i++) {
        pref_summa[i] += pref_summa[i - 1];
    }

    vector<int> answer(sizee);
    for (int i = 0; i < sizee; i++) {
        answer[pref_summa[arr[i]] - 1] = arr[i];
        pref_summa[arr[i]]--;
    }
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    //cout << time_spent << endl;

    for (int i = 0; i < sizee; i++) {
        cout << answer[i] << " ";
     }
}