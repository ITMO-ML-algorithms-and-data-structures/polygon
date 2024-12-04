#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
void countingSort(const vector<int>& arr, vector<int>& sorted_arr) {
    if (arr.empty()){
        return;
        }
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;
    vector<int> count(range, 0);
    for (int num : arr) {
        count[num - min_val]++;
    }
    for (size_t i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    sorted_arr.resize(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        sorted_arr[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }
}
void quicksort(vector<int>& arr, int low, int high) { // N * 4 байт (где N — размер массива)
    if (low >= high) {
        return;
    }
    int pivot = arr[(low + high) / 2]; // 4 байта для pivot
    int i = low; // 4 байта для int i
    int j = high; // 4 байта для int j
    while (i <= j) {
        while (arr[i] < pivot) { // 4 байта для arr[i]
            i++; // 4 байта для i
        }
        while (arr[j] > pivot) { // 4 байта для arr[j]
            j--; // 4 байта для j
        }
        if (i <= j) {
            swap(arr[i], arr[j]); // 4 байта для arr[i] и arr[j]
            i++; // 4 байта для i
            j--; // 4 байта для j
        }
    }
    if (low < j) {
        quicksort(arr, low, j);
    }
    if (i < high) {
        quicksort(arr, i, high);
    }
}
void CoctailSort(vector<int>& arr){ // 4N байт (+ служебная инфа, но вроде можно не учитывать)
    int start = 0; //4 байта
    int end = arr.size()-1; //4 байта
    bool c = true; // 1 байт
    while(c){
        c = false;
        for(int i = start;i<end;i++){
            if (arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                c = true;
            }
        }
        if (c== false) break;
        end--;
        c = false;
        for(int i = end;i>start;i--){
            if (arr[i]<arr[i-1]){
                swap(arr[i],arr[i-1]);
                c = true;
            }
        } // два цикла с ппеременными i т.е. 8 байт
        start++;
    }
}

int main() {
    vector<int> arr;
    ifstream file("aaa.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
    }
    file.close();
    vector<int> sorted_arr{};
    
    // countingSort(arr, sorted_arr);

    // quicksort(arr, 0, arr.size() - 1);
    // sorted_arr = arr;

    // CoctailSort(arr);
    // sorted_arr = arr;

    for (int x : sorted_arr) {
        cout << x << " ";
    }
    return 0;
}