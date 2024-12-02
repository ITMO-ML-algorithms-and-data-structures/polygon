#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <fstream>
#include <cstdlib>
using namespace std;



//ShakerSort
void cocktailShakerSort(vector<int>& arr) {
    int n = arr.size(); //8 байт
    bool swapped = true; //1 байт
    int start = 0; //4 байта
    int end = n - 1;

    while (swapped) {
        swapped = false; //1 байт
        for (int i = start; i < end; i++) { //O(n)
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]); //O(1)
                swapped = true; //1 Байт
            }
        }

        if (!swapped) //1 байт
            break;

        swapped = false; //1 Байт
        end--; //O(1)

        for (int i = end - 1; i >= start; i--) { //O(n)
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]); //O(n)
                swapped = true; //1 байт
            }
        }
        start++;
    }
}
//Общая сложность:
//В худшем и среднем случае: O(n^2).
//Память: O(1).


//TreeSort
struct Node { //O(n) памяти
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {} //O(1)
};

Node* insert(Node* root, int value) { //O(n^2) в худшем случае и O(n * log(n)) в среднем
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

void inOrderTraversal(Node* root, vector<int>& result) { //O(n) и O(n) либо O(log(n) памяти
    if (!root) return;
    inOrderTraversal(root->left, result);
    result.push_back(root->data);
    inOrderTraversal(root->right, result);
}

void treeSort(vector<int>& arr) {
    Node* root = nullptr;
    for (int value : arr) root = insert(root, value);

    arr.clear();
    inOrderTraversal(root, arr);
}
//Общая сложность:
//В худшем и среднем случае: O(n^2) и O(n * log(n)).
//Память: O(n).


//TimSort
const int RUN = 32;

void insertionSort(vector<int>& arr, int left, int right) { //O((right-left+1)^2)
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(vector<int>& arr, int left, int mid, int right) { //Итоговая сложность: O(right-left+1)
    int len1 = mid - left + 1;
    int len2 = right - mid;
    vector<int> leftPart(len1), rightPart(len2);

    for (int i = 0; i < len1; i++)
        leftPart[i] = arr[left + i]; //O(len1)
    for (int i = 0; i < len2; i++)
        rightPart[i] = arr[mid + 1 + i]; //O(len2)

    int i = 0, j = 0, k = left;

    //Слияние двух массивов
    while (i < len1 && j < len2) {  //O(right-left+1)
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }

    //Добавляем оставшиеся элементы
    while (i < len1) { // O(len1)
        arr[k++] = leftPart[i++];
    }

    while (j < len2) { //O(len2)
        arr[k++] = rightPart[j++];
    }
}

//Реализация Timsort
void timSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i += RUN) { //O(n*RUN)
        insertionSort(arr, i, min((i + RUN - 1), (n - 1)));
    }

    for (int size = RUN; size < n; size *= 2) { //O(n*log(n/RUN))
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}
// Временная сложность:
// Лучший случай: O(n) (если массив уже отсортирован)
// Средний и худший случаи: O(n log n)
// ПамятьЖ O(n)

void testShaker() {

    vector<int> arr1 = {5, 3, 8, 4, 2};
    cocktailShakerSort(arr1);
    assert((arr1 == vector<int>{2, 3, 4, 5, 8}));

    vector<int> arr2 = {1, 2, 3, 4, 5 };
    cocktailShakerSort(arr2);
    assert((arr2 == vector<int>{1, 2, 3, 4, 5}));

    vector<int> arr3 = {5, 4, 3, 2, 1};
    cocktailShakerSort(arr3);
    assert((arr3 == vector<int>{1, 2, 3, 4, 5}));

    vector<int> arr4 = {};
    cocktailShakerSort(arr4);
    assert(arr4 == vector<int>({}));

    vector<int> arr5 = {3, 3, 3};
    cocktailShakerSort(arr5);
    assert((arr5 == vector<int>{3, 3, 3}));
    
    vector<int> arr6 = {-1, -3, -2, -4, -5};
    cocktailShakerSort(arr6);
    assert(arr6 == vector<int>({-5, -4, -3, -2, -1}));


}

void testTree() {
    
    vector<int> arr1 = {5, 3, 8, 4, 2};
    treeSort(arr1);
    assert((arr1 == vector<int>{2, 3, 4, 5, 8}));

    vector<int> arr2 = {1, 2, 3, 4, 5};
    treeSort(arr2);
    assert((arr2 == vector<int>{1, 2, 3, 4, 5}));
    
    vector<int> arr3 = {5, 4, 3, 2, 1};
    treeSort(arr3);
    assert((arr3 == vector<int>{1, 2, 3, 4, 5}));
    
    vector<int> arr4 = {};
    treeSort(arr4);
    assert(arr4 == vector<int>({}));

    vector<int> arr5 = {3, 3, 3};
    treeSort(arr5);
    assert((arr5 == vector<int>{3, 3, 3}));
    
    vector<int> arr6 = {-1, -3, -2, -4, -5};
    treeSort(arr6);
    assert(arr6 == vector<int>({-5, -4, -3, -2, -1}));
    
}

void testTimSort() {
    vector<int> arr1 = {};
    timSort(arr1);
    assert(arr1 == vector<int>({}));

    vector<int> arr2 = {52};
    timSort(arr2);
    assert(arr2 == vector<int>({52}));

    vector<int> arr3 = {6, 1, 12, 2, 6, 2};
    timSort(arr3);
    assert(arr3 == vector<int>({1, 2, 2, 6, 6, 12}));

    vector<int> arr4 = {1, 2, 3, 4, 5};
    timSort(arr4);
    assert(arr4 == vector<int>({1, 2, 3, 4, 5}));

    vector<int> arr5 = {3, 3, 3};
    timSort(arr5);
    assert(arr5 == vector<int>({3, 3, 3}));

    vector<int> arr6 = {-1, -3, -2, -4, -5};
    timSort(arr6);
    assert(arr6 == vector<int>({-5, -4, -3, -2, -1}));

}

int main() {
    testShaker();
    testTree();
    testTimSort();
    cout << "OK" << '\n';
    
    //    int n;
    //        cout << "Enter the size of the array: ";
    //        cin >> n;
    //
    //        vector<int> arr(n), arr1, arr2, arr3;
    //        cout << "Enter the elements of the array: ";
    //        for (int i = 0; i < n; i++) {
    //            cin >> arr[i];
    //        }
    // Подсчет времени работы в зависимости от числа элементов
    vector<int> sizes;
    vector<double> times1;
    vector<double> times2;
    vector<double> times3;
    
    for (int n = 100000; n <= 1000000; n += 100000) {
        sizes.push_back(n);
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 10000;
        }
        vector<int> arr1 = arr;
        vector<int> arr2 = arr;
        vector<int> arr3 = arr;
        
        //CocktailSort
        auto start1 = chrono::high_resolution_clock::now();
        cocktailShakerSort(arr1);
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<double> duration1 = end1 - start1;
        times1.push_back(duration1.count());
        
        //TreeSort
        auto start2 = chrono::high_resolution_clock::now();
        treeSort(arr2);
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<double> duration2 = end2 - start2;
        times2.push_back(duration2.count());
        
        //TimSort
        auto start3 = chrono::high_resolution_clock::now();
        timSort(arr3);
        auto end3 = chrono::high_resolution_clock::now();
        chrono::duration<double> duration3 = end3 - start3;
        times3.push_back(duration3.count());
    }
    
    // Сохранение данных для графика
    ofstream outFile1("tim_sort_times1.txt");
    for (size_t i = 0; i < sizes.size(); ++i) {
        outFile1 << sizes[i] << " " << times1[i] << endl;
    }
    outFile1.close();
    
    ofstream outFile2("tim_sort_times2.txt");
    for (size_t i = 0; i < sizes.size(); ++i) {
        outFile2 << sizes[i] << " " << times2[i] << endl;
    }
    outFile2.close();
    
    ofstream outFile3("tim_sort_times3.txt");
    for (size_t i = 0; i < sizes.size(); ++i) {
        outFile3 << sizes[i] << " " << times3[i] << endl;
    }
    outFile3.close();
    
    // Boxplot
    const int num_runs = 50;
    
    // Для массива размером 10^4
    ofstream outFile110000("1 times_10000.txt");
    ofstream outFile210000("2 times_10000.txt");
    ofstream outFile310000("3 times_10000.txt");
    for (int run = 0; run < num_runs; run++) {
        vector<int> arr(10000);
        for (int i = 0; i < 10000; ++i) {
            arr[i] = rand() % 10000;
        }
        vector<int> arr1 = arr;
        vector<int> arr2 = arr;
        vector<int> arr3 = arr;
        
        //CocktailSort
        
        auto start1 = chrono::high_resolution_clock::now();
        cocktailShakerSort(arr1);
        auto end1 = chrono::high_resolution_clock::now();
        
        chrono::duration<double> duration1 = end1 - start1;
        outFile110000 << duration1.count() << endl;
        
        
        //TreeSort
        
        auto start2 = chrono::high_resolution_clock::now();
        treeSort(arr2);
        auto end2 = chrono::high_resolution_clock::now();
        
        chrono::duration<double> duration2 = end2 - start2;
        outFile210000 << duration2.count() << endl;
        
        
        //TimSort
        
        auto start3 = chrono::high_resolution_clock::now();
        timSort(arr3);
        auto end3 = chrono::high_resolution_clock::now();
        
        chrono::duration<double> duration3 = end3 - start3;
        outFile310000 << duration3.count() << endl;
        
        
    }
    outFile110000.close();
    outFile210000.close();
    outFile310000.close();
    
    
    // Для массива размером 10^5
    ofstream outFile1100000("1 times_100000.txt");
    ofstream outFile2100000("2 times_100000.txt");
    ofstream outFile3100000("3 times_100000.txt");
    for (int run = 0; run < num_runs; run++) {
        vector<int> arr(100000);
        for (int i = 0; i < 100000; ++i) {
            arr[i] = rand() % 100000;
        }
        vector<int> arr1 = arr;
        vector<int> arr2 = arr;
        vector<int> arr3 = arr;
        
        //CocktailSort
        
        auto start1 = chrono::high_resolution_clock::now();
        cocktailShakerSort(arr1);
        auto end1 = chrono::high_resolution_clock::now();
        
        chrono::duration<double> duration1 = end1 - start1;
        outFile1100000 << duration1.count() << endl;
        
        
        //TreeSort
        
        auto start2 = chrono::high_resolution_clock::now();
        treeSort(arr2);
        auto end2 = chrono::high_resolution_clock::now();
        
        chrono::duration<double> duration2 = end2 - start2;
        outFile2100000 << duration2.count() << endl;
        
        
        //TimSort
        
        auto start3 = chrono::high_resolution_clock::now();
        timSort(arr3);
        auto end3 = chrono::high_resolution_clock::now();
        
        chrono::duration<double> duration3 = end3 - start3;
        outFile3100000 << duration3.count() << endl;
        
        
    }
    outFile1100000.close();
    outFile2100000.close();
    outFile3100000.close();
}

//    cocktailShakerSort(arr1);
//    cout << "\nCocktail Shaker Sort result: ";
//    for (int num : arr1) cout << num << " ";
//
//    treeSort(arr2);
//    cout << "\nTree Sort result: ";
//    for (int num : arr2) cout << num << " ";
//
//    timSort(arr3);
//    cout << "\nTimSort result: ";
//    for (int num : arr3) cout << num << " ";

