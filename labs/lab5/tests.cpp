#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cassert>

#include "odd_even.cpp"
#include "pancake.cpp"
#include "pigeonhole.cpp"

// Вывод массива
void print_vector(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Чтение набора данных из файла
std::vector<int> read_file(const std::string& filename, int size) {
    std::ifstream file(filename);
    std::vector<int> data;
    int elem;

    // читает файл и записывает его в data, пока количество значений не достигнет size
    while (data.size() < size) {
        file >> elem;
        data.push_back(elem);
    }
    return data;
}

// Тесты с замером времени
void time(const std::string& filename, int size) {
    std::vector<int> data = read_file(filename, size);

    // Измеряем время сортировки
    auto start_time = std::chrono::high_resolution_clock::now();
    // pigeonhole_sort(data);
    // odd_even_sort(data);
    // pancake_sort(data);
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем время и выводим результат
    std::chrono::duration<double> result = end_time - start_time;
    std::cout << "Len: " << data.size() << " elems, sort time = " << result.count() << " sec" << std::endl;
}

// Функция, проверяющая корректность сортировки
void is_sorted(std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        assert(arr[i] <= arr[i + 1]);
    }
}

void tests(std::string& sort_name) {
    // Лучший случай, уже отсортированный массив
    std::vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    // Массив в обратном порядке, худший для odd-even
    std::vector<int> arr2 = {7, 6, 5, 4, 3, 2, 1};
    // Средний случай, случайный порядок
    std::vector<int> arr3 = {-6, 14, 2, -3, 0, 11, 24};
    // Массив из одного элемента
    std::vector<int> arr4 = {52};
    // Массив из одинаковых
    std::vector<int> arr5 = {13, 13, 13, 13, 13, 13};
    std::vector<std::vector<int>> arr_tests = {arr1, arr2, arr3, arr4, arr5};

    if (sort_name == "odd-even") {
        for (std::vector<int> test_array : arr_tests) {
            odd_even_sort(test_array);
            is_sorted(test_array);
        }
        std::cout << "All test passed." << std::endl;
    } else if (sort_name == "pancake") {
        for (std::vector<int> test_array : arr_tests) {
            pancake_sort(test_array);
            is_sorted(test_array);
        }
        std::cout << "All test passed." << std::endl;
    } else if (sort_name == "pigeonhole") {
        for (std::vector<int> test_array : arr_tests) {
            pigeonhole_sort(test_array);
            is_sorted(test_array);
        }
        std::cout << "All test passed." << std::endl;
    }
}

int main() {
    std::string filename = "numbers1e6.txt";

    // Тестирования для линейного графика, проход по файлу с шагом 1000
    //for (int i = 1000; i <= 50000; i += 1000) {
    //    time(filename, i);
    //}
   
    // Тестирования для box plot, берем по 1е4 либо 1е5 значений из файла
    //for (int i = 0; i < 50; i++) {
    //    time(filename, 10000);
    //}
    //for (int i = 0; i < 50; i++) {
    //    time(filename, 100000;)
    //}

    // Тестирование на обычных тестах
    std::vector<std::string> sort_names = {"odd-even", "pancake", "pigeonhole"};
    // tests(sort_names[0]);
    // tests(sort_names[1]);
    // tests(sort_names[2]);

    return 0;
}