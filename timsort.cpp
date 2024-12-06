#include <iostream>
#include <vector>
#include <algorithm> 

const int RUN = 32; // количество подмассивов на которые разобьем

// Сортировка вставками для отдельных подмассивов
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        // каждый элемент будем сравнивать с уже отсортированной частью
        // перемещение элементов которые больше данного элем 
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// функция для сляния двух подмассивов
void merge(std::vector<int>& arr, int left, int mid, int right) {
    // размеры подмассивов
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // создание временных векторов для слияния
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // переносим данные в временные векторы
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // слияние двух векторов
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // копирование элементов кторые остались
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

// алгоритм сортировки Timsort
void timSort(std::vector<int>& arr) {
    int n = arr.size();

    // сортировка самих подмассивов с помощью сортировки вставками
    for (int i = 0; i < n; i += RUN) {
        insertionSort(arr, i, std::min(i + RUN - 1, n - 1));
    }

    // слияние отсортированных подмассивов
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, n - 1);

            // слияние если центр часть можно совместить с правой 
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

// тест и замер времение
int main() {
    std::vector<int> arr = {20, 40, 50, 10, 30, 550, 67,3000, 70000,43,76868676,89497878,579845873,84959845,4543,57948378,45037,376907,734673, 2, 1, 6, 7546455, 3365, 66, 8989405, 53089367, 396083908, 896093809, 3820683, 238082309};
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
 
    timSort(arr);

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Sorted array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}