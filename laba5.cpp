#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;

// Cocktail Sort
/*
 * Асимптотика:
 * - Худший случай: O(n^2) (если массив отсортирован в обратном порядке)
 * - Лучший случай: O(n) (если массив уже отсортирован)
 * - Средний случай: O(n^2)
 *
 * Память:
 * - Использует O(1) дополнительной памяти (сортировка на месте).
 */
vector<int> CocktailSort(vector<int>& vec) { // Память: O(1)
    bool isChange = true; // Память: O(1)
    int start = 0; // Память: O(1)
    int finish = vec.size() - 1; // Память: O(1)
    while (isChange) { // Время: Лучший случай: O(n), Худший/Средний случай: O(n^2)
        isChange = false;
        for (int i = start; i < finish; i++) { // Время: Лучший случай: O(n), Худший/Средний случай: O(n^2)
            if (vec[i] > vec[i + 1]) { // Время: O(1), Память: O(1)
                swap(vec[i], vec[i + 1]); // Время: O(1), Память: O(1)
                isChange = true;
            }
        }
        if (!isChange) break;
        isChange = false;
        for (int i = finish; i > start; i--) { // Время: Лучший случай: O(n), Худший/Средний случай: O(n^2)
            if (vec[i] < vec[i - 1]) { // Память: O(1)
                swap(vec[i], vec[i - 1]); // Время: O(1), Память: O(1)
                isChange = true;
            }
        }
        start += 1;
    }
    return vec;
}

// Merge Sort
/*
 * Память:
 * - Дополнительная память O(n) так как создаются временные массивы при каждом слиянии.
 *
 * Асимптотика:
 * - Худший случай: O(n log n)
 * - Лучший случай: O(n log n)
 * - Средний случай: O(n log n)
 */
void merge(vector<int>& arr, int left, int mid, int right) { // Время: O(n)
    int n1 = mid - left + 1; // Память: O(1)
    int n2 = right - mid; // Память: O(1)
    vector<int> leftArr(n1), rightArr(n2); // Память: O(n) - выделяется при каждом вызове merge, но освобождается перед следующим уровнем рекурсии
    for (int i = 0; i < n1; ++i) // Время: O(n)
        leftArr[i] = arr[left + i]; // Память: O(1)
    for (int j = 0; j < n2; ++j) // Время: O(n)
        rightArr[j] = arr[mid + 1 + j]; // Память: O(1)
    int i = 0, j = 0, k = left; // Память: O(1)
    while (i < n1 && j < n2) { // Время: O(n)
        if (leftArr[i] <= rightArr[j]) { // Время: O(1)
            arr[k] = leftArr[i];  // Память: O(1)
            ++i;
        } else {
            arr[k] = rightArr[j];  // Память: O(1)
            ++j;
        }
        ++k;
    }
    while (i < n1) { // Время: O(n)
        arr[k] = leftArr[i];  // Память: O(1)
        ++i;
        ++k;
    }
    while (j < n2) { // Время: O(n)
        arr[k] = rightArr[j];  // Память: O(1)
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right) { // Время: O(n log n)
    if (left < right) {
        int mid = left + (right - left) / 2; // Память: O(1)
        mergeSort(arr, left, mid); // Время: O(n log n)
        mergeSort(arr, mid + 1, right); // Время: O(n log n)
        merge(arr, left, mid, right); // Время: O(n)
    }
}

// Bucket Sort
/*
 * Асимптотика:
 * - Худший случай: O(n^2) (если все элементы попадают в одну корзину)
 * - Лучший случай: O(n + k), где k - число корзин (при равномерном распределении данных).
 * - Средний случай: O(n + k), при условии равномерного распределения.
 *
 * Память:
 * - Дополнительная память O(n), где n - число корзин, которое равно размеру входного массива.
 */
void bucketSort(vector<double>& arr) {  // Время: Средний: O(n), Худший: O(n^2)
    int n = arr.size(); // Память: O(1)
    vector<double> b[n];  // Память: O(n)
    for (int i = 0; i < n; i++) { // Время: O(n)
        int bi = n * arr[i];  // Память: O(1)
        b[bi].push_back(arr[i]);  // Среднее O(1), худший O(n)
    }
    for (int i = 0; i < n; i++) { // O(n) - количество корзин
        sort(b[i].begin(), b[i].end()); // Худший случай: O(n^2) (если все элементы в одной корзине), Средний: O(n) (равномерное распределение)
    }
    int index = 0; // Память: O(1)
    for (int i = 0; i < n; i++) { // O(n)
        for (int j = 0; j < b[i].size(); j++) { // O(n) всего по всем корзинам
            arr[index++] = b[i][j]; // Память: O(1)
        }
    }
}

vector<int> generateTest_INT(int n){
    vector<int>vec;
    for (int i = 0; i < n; i++)
    {
        int elem = abs(rand()) % 1000000;
        vec.push_back(elem);
    }
    return vec;
}

vector<double> generateTest_FLOAT(int n){
    vector<double>vec;
    for (int i = 0; i < n; i++)
    {
        double elem = (abs(rand()) % 1000000) / 1000000.;
        vec.push_back(elem);
    }
    return vec;
}

int main ()
{
    srand(static_cast<unsigned int>(time(0)));
    // vector<int>arr = generateTest_INT(10);
    // vector<double>arr = generateTest_FLOAT(100000);
    // mergeSort(arr,0,arr.size()-1);
    // arr = CocktailSort(arr);
    // bucketSort(arr);
    // bool check = true;  
    // for (int i = 0; i < arr.size() - 1; i++) {
    //     if (arr[i] > arr[i+1]){
    //         check = false;
    //         break;
    //     }
    // }
    ofstream out1;
    out1.open("bucket_1e5.txt");
    // for (int i = 1000; i<1000000; i+=10000){
    //     vector<double>arr = generateTest_FLOAT(i);
    //     unsigned int start_time =  clock();
    //     bucketSort(arr);
    //     unsigned int end_time = clock();
    //     unsigned int search_time = end_time - start_time;
    //     out1 << i << " " << search_time/10000.0 << endl;
    //     cout << i << endl;
    // }
    for (int i = 0; i < 100; i++)
    {
        vector<double>arr = generateTest_FLOAT(100000);
        unsigned int start_time = clock();
        bucketSort(arr);
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;
        out1 << search_time/10000.0 << " ";
        cout << i << endl;
    }
}