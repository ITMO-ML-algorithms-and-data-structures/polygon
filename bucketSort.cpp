#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <fstream>

// Функция для Bucket Sort O(n⋅k) в худшем
void bucketSort(std::vector<int>& arr) { // 24 байт + size * 4 байт
    int n = arr.size(); // 4 байта
    if (n <= 0) return;

    // Определяем минимальное и максимальное значение в массиве
    int minValue = *std::min_element(arr.begin(), arr.end());// 4 байта O(n)
    int maxValue = *std::max_element(arr.begin(), arr.end());// 4 байта O(n)

    // Фиксированное количество корзин
    int bucketCount = 1000;// 4 байта
    std::vector<std::vector<int>> buckets(bucketCount);

    // 1. Распределяем элементы по корзинам
    for (int i = 0; i < n; i++) { // O(n)
        int bucketIndex = (bucketCount * (arr[i] - minValue)) / (maxValue - minValue + 1); // 4 байта
        bucketIndex = std::min(bucketIndex, bucketCount - 1); // Гарантируем корректный индекс O(1)
        buckets[bucketIndex].push_back(arr[i]); // O(n)
    }

    // 2. Сортируем каждую корзину
    for (int i = 0; i < bucketCount; i++) { //  O(bucketCount)
        if (!buckets[i].empty()) {
            std::sort(buckets[i].begin(), buckets[i].end()); // O(k * log k)
        }
    }

    // 3. Объединяем корзины в результирующий массив
    int index = 0; // 4 байта
    for (int i = 0; i < bucketCount; i++) { //  O(bucketCount)
        for (int val : buckets[i]) { // O(k)
            arr[index++] = val;
        }
    }
}



std::vector<int> readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> data;  // 24 байт + size * 4 байт
    int value;// 4 байта
    while (file >> value) {
        data.push_back(value);
    }

    return data;
}


void Test() {
    // Алгоритм просто проходит по массиву один раз, выполняя только проверки, без обменов
    std::vector<int> good_test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> ans_good = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bucketSort(good_test);
    assert(good_test == ans_good);
    std::cout << "первый тест прошел"<< std::endl;

    std::vector<int> mean_test = {7, 2, 9, 4, 10, 1, 3, 8, 5, 6, 12, 15, 11, 13, 14, 20, 18, 17, 19, 16};
    std::vector<int> ans_mean = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    bucketSort(mean_test);
    assert(mean_test == ans_mean);
    std::cout << "второй тест прошел"<< std::endl;

    // Массив создан таким образом, чтобы runs были минимальной длины (1-2 элемента) это делается за счет чередования больших и малых чисел
    std::vector<int> bad_test = {5, 1, 6, 2, 7, 3, 8, 4, 9, 0, 15, 10, 16, 11, 17, 12, 18, 13, 19, 14};
    std::vector<int> ans_bad = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    bucketSort(bad_test);
    assert(bad_test == ans_bad);
    std::cout << "третий тест прошел"<< std::endl;
}

void Test_time(const std::vector<std::string>& filenames) {
    for (size_t i = 0; i < filenames.size(); i++) {
        // Читаем данные из файла
        std::vector<int> data = readFile(filenames[i]);

        // Измеряем время сортировки
        auto start = std::chrono::high_resolution_clock::now();
        bucketSort(data);
        auto end = std::chrono::high_resolution_clock::now();

        // Вычисляем время выполнения
        std::chrono::duration<double> elapsed = end - start;

        // Выводим результат
        std::cout << "Длина массива " << data.size() << ", Время сортировки = " << elapsed.count() << " секунд" << std::endl;

    }
}


int main() {
    Test();

    std::vector<std::string> filenames = {
            "test_sort/file1.txt", "test_sort/file2.txt", "test_sort/file3.txt", "test_sort/file4.txt",
            "test_sort/file5.txt", "test_sort/file6.txt", "test_sort/file7.txt", "test_sort/file8.txt",
            "test_sort/file9.txt", "test_sort/file10.txt", "test_sort/file11.txt", "test_sort/file12.txt",
            "test_sort/file13.txt", "test_sort/file14.txt", "test_sort/file15.txt", "test_sort/file16.txt"
    };
    Test_time(filenames);

    std::vector<std::string> box_plot_10e4;
    for (int i = 0; i < 50; i ++){
        box_plot_10e4.push_back(std::format("file_boxplot_10e4/file_{}.txt", i));
    }
    Test_time(box_plot_10e4);

    std::vector<std::string> box_plot_10e5;
    for (int i = 0; i < 50; i ++){
        box_plot_10e5.push_back(std::format("file_boxplot_10e5/file_{}.txt", i));
    }
    Test_time(box_plot_10e5);

    std::vector<int> arr = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68};

    std::cout << "До сортировки: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bucketSort(arr);

    std::cout << "После сортировки: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
