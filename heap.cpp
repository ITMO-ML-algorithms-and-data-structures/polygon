#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

void heapify(int *arr, int size, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int maxx = i;
    if (l<size && arr[l]>arr[maxx]){
        maxx = l;
    }
    if (r<size && arr[r]>arr[maxx]){
        maxx = r;
    }
    if (maxx != i){
        swap(arr[i], arr[maxx]);
        heapify(arr, size, maxx);
    }
}

int main(int argc, char* argv[]){
    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }
    string line;
    if (getline(inputFile, line)) {
        stringstream ss(line);
        string cell;
        int count = 0;

        stringstream temp(line);
        while (getline(temp, cell, '\t')) {
            count++;
        }
        int arr[count];
        int index = 0;
        while (getline(ss, cell, '\t')) {
            arr[index++] = stoi(cell);
        }
        inputFile.close();
        clock_t begin = clock();
        int size = sizeof(arr) / sizeof(arr[0]);
        for (int i = size/2-1; i >= 0; i--){
            heapify(arr, size, i);
        }
        for (int i = size-1; i >= 0; i--){
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
        clock_t end = clock();
        double elapsed = (double) (end - begin) / CLOCKS_PER_SEC;
        //cout << elapsed << endl;
		for (int i = 0; i < size; i++){
      		cout << arr[i] << " ";
    		}
        }
}