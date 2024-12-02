#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <cmath>

using namespace std;

//   ×ÅËÍÎ×ÍÀß ÑÎĞÒÈĞÎÂÊÀ (SHUTTLE SORT)

void shuttle_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }

        for (int j = n - i - 2; j >= 0; j--) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


//   ÑÎĞÒÈĞÎÂÊÀ ÊÓ×ÅÉ  (HEAP SORT)

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);


        heapify(arr, n, largest);
    }
}


void heap_sort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}




//  ÑÎĞÒÈĞÎÂÊÀ ÏÎÄÑ×ÅÒÎÌ (COUNTING SORT)

void counting_sort(vector<int>& arr) {

    int max_val = *max_element(arr.begin(), arr.end());

    vector<int> count(max_val + 1, 0);

    for (int num : arr) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}




int main() {
    setlocale(LC_ALL, "Ru");
    //ifstream input_file("test_lite.txt");
    //ifstream input_file("test_medium.txt");
    ifstream input_file("test_hard.txt");

    vector<int> arr;
    int value;
    while (input_file >> value) {
        arr.push_back(value);
    }
    input_file.close();

    shuttle_sort(arr);
    //heap_sort(arr);
    //counting_sort(arr);

    cout << "Îòñîğòèğîâàííûé ìàññèâ: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << std::endl;

    return 0;
}