#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <functional>
#include <set>
#include <random>
using namespace std;

// Структура для хранения результатов сортировки
struct SortResult {
    std::string algorithm; 
    size_t arraySize;      
    double elapsedTime;    
};

std::vector<int> readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> data;
    int value;

    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла: " << filename << std::endl;
        return data;
    }

    while (file >> value) {
        data.push_back(value);
    }

    file.close();
    return data;
}

void writeResultsToFile(const std::string& filename, const std::vector<SortResult>& results) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка при открытии файла для записи: " << filename << std::endl;
        return;
    }

    for (const auto& result : results) {
        outFile << result.algorithm << "," << result.arraySize << "," << result.elapsedTime << std::endl;
    }

    outFile.close();
}

// Алгоритм HeapSort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Алгоритм TreeSort
struct Node 
{ 
  int key; 
  struct Node *left, *right; 
}; 

struct Node *newNode(int item) 
{ 
  struct Node *temp = new Node; 
  temp->key = item; 
  temp->left = temp->right = NULL; 
  return temp; 
} 

void storeSorted(Node *root, int arr[], int &i) 
{ 
  if (root != NULL) 
  { 
    storeSorted(root->left, arr, i); 
    arr[i++] = root->key; 
    storeSorted(root->right, arr, i); 
  } 
} 

Node* insert(Node* node, int key) 
{ 

  if (node == NULL) return newNode(key); 


  if (key < node->key) 
    node->left = insert(node->left, key); 
  else if (key > node->key) 
    node->right = insert(node->right, key); 

  return node; 
} 


void treeSort(int arr[], int n) 
{ 
  struct Node *root = NULL; 

  root = insert(root, arr[0]); 
  for (int i=1; i<n; i++) 
    root = insert(root, arr[i]); 

  int i = 0; 
  storeSorted(root, arr, i); 
} 

// Timsort (используем std::sort как реализацию Timsort)
const int RUN = 32; 


void insertionSort(int arr[], int left, int right) 
{ 
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


void merge(int arr[], int l, int m, int r) 
{ 

  int len1 = m - l + 1, len2 = r - m; 
  int left[len1], right[len2]; 
  for (int i = 0; i < len1; i++) 
    left[i] = arr[l + i]; 
  for (int i = 0; i < len2; i++) 
    right[i] = arr[m + 1 + i]; 

  int i = 0; 
  int j = 0; 
  int k = l; 


  while (i < len1 && j < len2) { 
    if (left[i] <= right[j]) { 
      arr[k] = left[i]; 
      i++; 
    } 
    else { 
      arr[k] = right[j]; 
      j++; 
    } 
    k++; 
  } 


  while (i < len1) { 
    arr[k] = left[i]; 
    k++; 
    i++; 
  } 

  while (j < len2) { 
    arr[k] = right[j]; 
    k++; 
    j++; 
  } 
} 

void timSort(int arr[], int n) 
{ 

  for (int i = 0; i < n; i += RUN) 
    insertionSort(arr, i, min((i + RUN - 1), (n - 1))); 


  for (int size = RUN; size < n; size = 2 * size) { 
    for (int left = 0; left < n; left += 2 * size) { 
      int mid = left + size - 1; 
      int right = min((left + 2 * size - 1), (n - 1)); 
      if (mid < right) 
        merge(arr, left, mid, right); 
    } 
  } 
} 

// Функция тестирования времени для заданного алгоритма
void runTests(const std::string& algorithmName, 
              std::function<void(std::vector<int>&)> sortFunction, 
              const std::vector<std::string>& filenames, 
              std::vector<SortResult>& results) {
    for (const auto& filename : filenames) {
        std::vector<int> data = readFile(filename);
        if (data.empty()) continue;

        auto start = std::chrono::high_resolution_clock::now();
        sortFunction(data);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        results.push_back({algorithmName, data.size(), elapsed.count()});
    }
}

int main() {
    setlocale(LC_ALL, "Ru");

    // Файлы для тестирования
    std::vector<std::string> testFiles;
    for (int i = 0; i < 50; i++) {
        testFiles.push_back("test_input/file_" + std::to_string(i) + ".txt");
    }

    // Результаты тестирования
    std::vector<SortResult> results;

    std::cout << "Тестирование HeapSort:" << std::endl;
    runTests("HeapSort", heapSort, testFiles, results);

    std::cout << "\nТестирование TreeSort:" << std::endl;
    runTests("TreeSort", treeSort, testFiles, results);

    std::cout << "\nТестирование TimSort:" << std::endl;
    runTests("TimSort", timSort, testFiles, results);

    // Записываем результаты в файл
    writeResultsToFile("sort_results.csv", results);

    return 0;
}
