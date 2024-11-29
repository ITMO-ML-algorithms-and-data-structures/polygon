#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <fstream>

// Минимальный размер "run"
const int RUN = 10;

// Сортировка вставками для небольших подмассивов
void insertionSort(std::vector<int>& arr, int left, int right) { // 24 байт + size * 4 байт  4 байт  4 байт
    for (int i = left + 1; i <= right; i++) { // O(k), где k = right - left + 1
        int temp = arr[i]; //  4 байт
        int j = i - 1; // 4 байт
        while (j >= left && arr[j] > temp) { // O(k) в худшем случае
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Слияние двух подмассивов O(n)
void merge(std::vector<int>& arr, int left, int mid, int right) {// 24 байт + size * 4 байт  4 байт  4 байт 4 байт
    int len1 = mid - left + 1, len2 = right - mid; // 4 байт 4 байт
    std::vector<int> leftPart(len1); // 24 байт + size * 4 байт
    std::vector<int> rightPart(len2); // 24 байт + size * 4 байт

    // Копируем данные во временные массивы
    for (int i = 0; i < len1; i++){ // O(len1)
        leftPart[i] = arr[left + i];
    }
    for (int i = 0; i < len2; i++){ // O(len2)
        rightPart[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left; // 4 байта

    // Сливаем обратно в основной массив
    while (i < len1 && j < len2) { // O(len1 + len2)
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }

    // Копируем оставшиеся элементы
    while (i < len1){ // O(len1)
        arr[k++] = leftPart[i++];
    }
    while (j < len2) { // O(len2)
        arr[k++] = rightPart[j++];
    }
}

// Основная функция Timsort O(n*log(n))
void timSort(std::vector<int>& arr) {
    int n = arr.size(); // 4 байта

    // Сортируем подмассивы размером RUN с помощью сортировки вставками
    for (int i = 0; i < n; i += RUN) {// O(n)
        insertionSort(arr, i, std::min(i + RUN - 1, n - 1));
    }

    // Сливаем подмассивы
    for (int size = RUN; size < n; size = 2 * size) { // O(log(n / RUN))
        for (int left = 0; left < n; left += 2 * size) { // O(n / size)
            int mid = left + size - 1; // 4 байта
            int right = std::min(left + 2 * size - 1, n - 1); // байта

            if (mid < right) {
                merge(arr, left, mid, right); // O(size)
            }
        }
    }
}

std::vector<int> readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> data; // 24 байт + size * 4 байт
    int value; // 4 байта
    while (file >> value) {
        data.push_back(value);
    }

    return data;
}


void Test() {
    // Алгоритм просто проходит по массиву один раз, выполняя только проверки, без обменов
    std::vector<int> good_test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> ans_good = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    timSort(good_test);
    assert(good_test == ans_good);
    std::cout << "первый тест прошел"<< std::endl;

    std::vector<int> mean_test = {7, 2, 9, 4, 10, 1, 3, 8, 5, 6, 12, 15, 11, 13, 14, 20, 18, 17, 19, 16};
    std::vector<int> ans_mean = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    timSort(mean_test);
    assert(mean_test == ans_mean);
    std::cout << "второй тест прошел"<< std::endl;

    // Массив создан таким образом, чтобы runs были минимальной длины (1-2 элемента) это делается за счет чередования больших и малых чисел
    std::vector<int> bad_test = {5, 1, 6, 2, 7, 3, 8, 4, 9, 0, 15, 10, 16, 11, 17, 12, 18, 13, 19, 14};
    std::vector<int> ans_bad = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    timSort(bad_test);
    assert(bad_test == ans_bad);
    std::cout << "третий тест прошел"<< std::endl;
}

void Test_time(const std::vector<std::string>& filenames) {
    for (size_t i = 0; i < filenames.size(); i++) {
        // Читаем данные из файла
        std::vector<int> data = readFile(filenames[i]);

        // Измеряем время сортировки
        auto start = std::chrono::high_resolution_clock::now();
        timSort(data);
        auto end = std::chrono::high_resolution_clock::now();

        // Вычисляем время выполнения
        std::chrono::duration<double> elapsed = end - start;

        // Выводим результат
        std::cout << "Длина массива " << data.size() << ", Время сортировки = " << elapsed.count() << " секунд" << std::endl;

    }
}


// Основная программа
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
    std::vector<int> arr = {5, 1, 6, 2, 7, 3, 8, 4, 9, 0, 15, 10, 16, 11, 17, 12, 18, 13, 19, 14};

    std::cout << "До сортировки: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    timSort(arr);

    std::cout << "После сортировки: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
