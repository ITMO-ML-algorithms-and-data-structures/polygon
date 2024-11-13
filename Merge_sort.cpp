#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    // Заполнение временных массивов
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    // Слияние двух половин
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);  // Рекурсивно сортируем левую половину
        mergeSort(arr, mid + 1, right);  // Рекурсивно сортируем правую половину

        merge(arr, left, mid, right);  // Сливаем два отсортированных массива
    }
}

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    mergeSort(arr, 0, arr.size() - 1);

    for (int val : arr) {
        std::cout <<

                  val << " ";
    }
    return 0;
}

