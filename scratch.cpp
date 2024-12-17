#include <chrono>
#include <vector>
#include <iostream>
void bubble_sort(int arr[], const int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++){
            if (arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void smooth_sort(int arr[], const int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_ind = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_ind]) {
                min_ind = j;
            }
        }
        if (min_ind != i) {
            std::swap(arr[i], arr[min_ind]);
        }
    }
}

int main(){
    int arr[] = {4, 2, 1, 3, 5};
    int arr1[] = {4, 2, 1, 3, 5};
    int arr2[] = {4, 2, 1, 3, 5};
    int arr3[] = {4, 2, 1, 3, 5};
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
     smooth_sort(arr2, size);
    std::cout << "Отсортированный плавно массив:" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << arr2[i] << std::endl;
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time2 = end2 - start2;
    std::cout << "Время выполнения: " << elapsed_time2.count() << " секунд" << std::endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    bucket_sort(arr3, size);
    std::cout << "Отсортированный блочно массив:" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << arr3[i] << std::endl;
    }
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time3 = end3 - start3;
    std::cout << "Время выполнения: " << elapsed_time3.count() << " секунд" << std::endl;
    return 0;
}
