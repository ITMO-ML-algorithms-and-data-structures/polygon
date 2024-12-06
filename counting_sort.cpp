#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <chrono>
#include <sstream>
#include <string>

using namespace std;

// Функция Counting Sort
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Найдём минимальное и максимальное значения в массиве
    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());

    // Создаём вспомогательный массив для подсчёта (сдвигаем на -minValue, если есть отрицательные значения)
    vector<int> count(maxValue - minValue + 1, 0);

    // Заполняем массив подсчёта
    for (int num : arr) {
        count[num - minValue]++;
    }

    // Перезаписываем исходный массив в отсортированном порядке
    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            arr[index++] = i + minValue;
            count[i]--;
        }
    }
}

// Память: O(n + k), где n - количество элементов, k - диапазон уникальных значений

vector<int> readFile(const string& filename) {
    ifstream file(filename);
    vector<int> data;  // 24 байт + size * 4 байт
    int value;// 4 байта
    while (file >> value) {
        data.push_back(value);
    }

    return data;
}

void Test() {
    // Алгоритм просто проходит по массиву один раз, выполняя только проверки, без обменов
    vector<int> good_test = { 1, 2, 2, 3, 1, 2, 3, 1};
    vector<int> ans_good = { 1, 1, 1, 2, 2, 2, 3, 3 };
    countingSort(good_test);
    assert(good_test == ans_good);
    cout << "the first test is completed" << endl;

    vector<int> mean_test = { 10, 5, 7, 5, 10, 2, 9, 1, 8, 6 };
    vector<int> ans_mean = { 1, 2, 5, 5, 6, 7, 8, 9, 10, 10 };
    countingSort(mean_test);
    assert(mean_test == ans_mean);
    cout << "the second test is completed" << endl;

    // Массив создан таким образом, чтобы runs были минимальной длины (1-2 элемента) это делается за счет чередования больших и малых чисел
    vector<int> bad_test = { 1000, 5, 3000, 2000, 4000, 10000 };
    vector<int> ans_bad = { 5, 1000, 2000, 3000, 4000, 10000 };
    countingSort(bad_test);
    assert(bad_test == ans_bad);
    cout << "the third test is completed" << endl;
}

void Test_time(const vector<string>& filenames) {
    for (size_t i = 0; i < filenames.size(); i++) {
        // Читаем данные из файла
        vector<int> data = readFile(filenames[i]);

        // Измеряем время сортировки
        auto start = chrono::high_resolution_clock::now();
        countingSort(data);
        auto end = chrono::high_resolution_clock::now();

        // Вычисляем время выполнения
        chrono::duration<double> time = end - start;

        // Выводим результат
        cout << "the length of the array " << data.size() << ", sorting time = " << time.count() << " seconds" << endl;

    }
}

int main() {
    Test();

    vector<string> filenames = {
            "C:/Users/polin/OneDrive/Desktop/test_sort/file1.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file2.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file3.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file4.txt",
            "C:/Users/polin/OneDrive/Desktop/test_sort/file5.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file6.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file7.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file8.txt",
            "C:/Users/polin/OneDrive/Desktop/test_sort/file9.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file10.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file11.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file12.txt",
            "C:/Users/polin/OneDrive/Desktop/test_sort/file13.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file14.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file15.txt", "C:/Users/polin/OneDrive/Desktop/test_sort/file16.txt"
    };
    Test_time(filenames);

    vector<string> box_plot_10e4;
    vector<string> box_plot_10e5;
    for (int i = 0; i < 50; i++) {
        ostringstream oss;
        oss << "C:/Users/polin/OneDrive/Desktop/file_boxplot_10e4/file_" << i << ".txt";
        box_plot_10e4.push_back(oss.str());
    }

    for (int i = 0; i < 50; i++) {
        ostringstream oss;
        oss << "C:/Users/polin/OneDrive/Desktop/file_boxplot_10e5/file_" << i << ".txt";
        box_plot_10e5.push_back(oss.str());
    }
    Test_time(box_plot_10e4);
    Test_time(box_plot_10e5);

    vector<int> arr = { 3, 2, 4, 1 };

    cout << "the original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "the sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

