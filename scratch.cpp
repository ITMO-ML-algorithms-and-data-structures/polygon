#include <chrono>
#include <vector>
#include <iostream>
#include <algorithm>
void bubble_sort(int arr[], const int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++){
            if (arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void selection_sort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        int min_ind = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_ind]) {
                min_ind = j;
            }
        }
        if (min_ind != i) {
            std::swap(arr[i], arr[min_ind]);
        }
    }
}
void bucket_sort(std::vector<int>& arr) {
    int min_val = arr[0];
    int max_val = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    int num_buckets = max_val - min_val + 1;
    std::vector<std::vector<int>> buckets(num_buckets);
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        buckets[num - min_val].push_back(num);
    }
    arr.clear();
    for (auto bucket : buckets) {
        selection_sort(bucket);
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}
int main(){
    int arr[] = {4, 2, 1, 3, 5};
    int arr1[] = {4, 2, 1, 3, 5};
    std::vector<int> arr2 = {4, 2, 1, 3, 5};
    std::vector<int> arr3 = {4, 2, 1, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    auto start1 = std::chrono::high_resolution_clock::now();
    bubble_sort(arr1, size);
    std::cout << "Отсортированный пузырьком массив:" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << arr1[i] << std::endl;
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time1 = end1 - start1;
    std::cout << "Время выполнения: " << elapsed_time1.count() << " секунд" << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    selection_sort(arr2);
    std::cout << "Отсортированный выбором массив:" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << arr2[i] << std::endl;
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time2 = end2 - start2;
    std::cout << "Время выполнения: " << elapsed_time2.count() << " секунд" << std::endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    bucket_sort(arr3);
    std::cout << "Отсортированный блочно массив:" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << arr3[i] << std::endl;
    }
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time3 = end3 - start3;
    std::cout << "Время выполнения: " << elapsed_time3.count() << " секунд" << std::endl;
    return 0;
}
