#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>

void shakerSort(std::vector<int>& arr) { // 24 байт + size * 4 байт
    int left = 0;               // Левая граница 4 байта
    int right = arr.size() - 1; // Правая граница 4 байта
    bool swapped;               // Флаг для проверки обменов 1 байт

    // O(n/2)
    do {
        swapped = false;

        // Проход слева направо
        for (int i = left; i < right; ++i) { // O(n)
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]); // O(1)
                swapped = true;
            }
        }
        right--; // Сокращаем правую границу

        // Проход справа налево
        for (int i = right; i > left; --i) { // O(n)
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]); // O(1)
                swapped = true;
            }
        }
        left++; // Сокращаем левую границу
    } while (swapped); // Если не было обменов, завершаем сортировку
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
    shakerSort(good_test);
    assert(good_test == ans_good);
    std::cout << "первый тест прошел"<< std::endl;

    std::vector<int> mean_test = {7, 2, 9, 4, 10, 1, 3, 8, 5, 6};
    std::vector<int> ans_mean = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    shakerSort(mean_test);
    assert(mean_test == ans_mean);
    std::cout << "второй тест прошел"<< std::endl;

    std::vector<int> bad_test = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> ans_bad = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    shakerSort(bad_test);
    assert(bad_test == ans_bad);
    std::cout << "третий тест прошел"<< std::endl;
}

void Test_time(const std::vector<std::string>& filenames) {
    for (size_t i = 0; i < filenames.size(); i++) {
        // Читаем данные из файла
        std::vector<int> data = readFile(filenames[i]);

        // Измеряем время сортировки
        auto start = std::chrono::high_resolution_clock::now();
        shakerSort(data);
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

    std::vector<int> arr = {5, 1, 4, 2, 8, 0, 2};

    std::cout << "До сортировки: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    shakerSort(arr);
    std::cout << "После сортировки: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
