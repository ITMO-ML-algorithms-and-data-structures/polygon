#include <random> 
#include <algorithm> 
#include <vector> 
#include <ctime> 
#include <iostream> 
#include <fstream> 
using namespace std;

// для выполнения сортировки и замера времени в файл.
void runTest(const string& inputFileName, const string& outputFileName, int testId, void (*sortingFunction)(vector<int>&), const string& sortingName) {
    ifstream inputFile(inputFileName); 
    ofstream outputFile(outputFileName, ios::app); 

    int arraySize;
    inputFile >> arraySize; 

    vector<int> array(arraySize); 

    for (int index = 0; index < arraySize; ++index) {
        inputFile >> array[index]; 
    }

    unsigned int startTime = clock(); 
    sortingFunction(array);
    unsigned int endTime = clock(); 

    outputFile << sortingName << " Test " << testId << ": " << arraySize << " elements, "
               << "Time: " << (endTime - startTime) / (double)CLOCKS_PER_SEC * 1000 << " ms\n"; 

    inputFile.close(); 
    outputFile.close(); 
}

// генерации файла с тестовыми данными
void generateFile(const string& fileName, int arraySize) {
    ofstream file(fileName); 
    random_device randomDevice; 
    mt19937 generator(randomDevice()); 
    uniform_int_distribution<> distribution(-1000, 1000); 
    file << arraySize << "\n";

    for (int index = 0; index < arraySize; ++index) {
        file << distribution(generator) << " "; 
    }

    file.close(); 
}


// Реализация Shaker Sort
void ShakerSort(vector<int>& array) {
    int left = 0; 
    int right = array.size() - 1; 
    bool swapped = true; 

    while (swapped) {
        swapped = false; 
        // лева направо
        for (int i = left; i < right; ++i) {
            if (array[i] > array[i + 1]) { 
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
        --right;
        swapped = false; 
        // справа налево
        for (int i = right; i > left; --i) {
            if (array[i] < array[i - 1]) { 
                swap(array[i], array[i - 1]);
                swapped = true; 
            }
        }

        ++left;
    }
}


// Pancake Sort
void PancakeSort(vector<int>& array) {
    auto flip = [](vector<int>& arr, int end) {
       
        for (int i = 0, j = end; i < j; ++i, --j) {
            swap(arr[i], arr[j]);
        }
    };
    for (int size = array.size(); size > 1; --size) {
        int maxIndex = max_element(array.begin(), array.begin() + size) - array.begin();
        if (maxIndex != size - 1) {
            flip(array, maxIndex); 
            flip(array, size - 1);
        }
    }
}

// Stooge Sort
void StoogeSort(vector<int>& array, int l, int h) {
    if (l >= h) return; 

    if (array[l] > array[h]) {
        swap(array[l], array[h]);
    }

  
    if (h - l + 1 > 2) {
        int third = (h - l + 1) / 3; 

        StoogeSort(array, l, h - third);
        StoogeSort(array, l + third, h);
        StoogeSort(array, l, h - third);
    }
}


int main() {
    const string inputFileName = "test_data.txt"; 
    const string outputFileName = "sort_results.txt"; 
    generateFile(inputFileName, 10000); 

    for (int testId = 1; testId <= 5; ++testId) {
        runTest(inputFileName, outputFileName, testId, ShakerSort, "ShakerSort"); 
        cout << "Completed Shaker Sort Test " << testId << endl; 
    }

    // Тестирование Pancake Sort
    for (int testId = 1; testId <= 5; ++testId) {
        runTest(inputFileName, outputFileName, testId, PancakeSort, "PancakeSort"); 
        cout << "Completed Pancake Sort Test " << testId << endl; 
    }

    // Stooge Sort
    for (int testId = 1; testId <= 5; ++testId) {
        runTest(inputFileName, outputFileName, testId, [](vector<int>& array) { StoogeSort(array, 0, array.size() - 1); }, "StoogeSort"); // Запускаем тест
        cout << "Completed Stooge Sort Test " << testId << endl; 
    }
    return 0; 
}
