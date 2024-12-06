#include <iostream>
#include <vector>
#include <algorithm> 

// сортировка вставками (описана ранее в отчете и в timsort)
// здесь можно использовать и любую другую стабильную сортировку
void insertionSort(std::vector<int>& bucket) {
    for (size_t i = 1; i < bucket.size(); i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// алгоритм bucket sort (сортировка корзнами или сортировка блоками)
// на вход подается массив и значение количества элементов в корзине для оптимизации 
void bucketSort(std::vector<int>& arr, int bucketSize) {
    if (arr.empty()) return; // выхд из функции если пусто

    // нахождение макс и мин в массиве для последующих расчетов 
    int minValue = *std::min_element(arr.begin(), arr.end());
    int maxValue = *std::max_element(arr.begin(), arr.end());

    // расчет корзин по формуле
    int bucketCount = (maxValue - minValue) / bucketSize + 1;
    std::vector<std::vector<int>> buckets(bucketCount);

    // распределение элементов по корзинам по формуле
    for (int num : arr) {
        int bucketIndex = (num - minValue) / bucketSize;
        buckets[bucketIndex].push_back(num);
    }

    // сортировка корзин с помощью insertion sort
    for (auto& bucket : buckets) {
        insertionSort(bucket);
    }

    // объединение отсортированных корзин
    arr.clear();
    for (const auto& bucket : buckets) {
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

// тест и замер времени 
int main() {
    std::vector<int> arr = {20, 40, 50, 10, 30, 550, 67,3000, 70000,43,76868676,89497878,579845873,84959845,4543,57948378,45037,376907,734673, 2, 1, 6, 7546455, 3365, 66, 8989405, 53089367, 396083908, 896093809, 3820683, 238082309};
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
 
    int quant = 1000000000;
    bucketSort(arr, quant);

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Sorted array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}