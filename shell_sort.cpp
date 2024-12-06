#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <chrono>
#include <sstream>
#include <string>

using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Начинаем с большого шага, затем уменьшаем его
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Выполняем сортировку вставками для текущего шага
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Сравниваем элементы, находящиеся на расстоянии gap
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Вставляем временный элемент на правильное место
            arr[j] = temp;
        }
    }
}

//Используемая память: O(n) + 20 байт.

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
    vector<int> good_test = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    vector<int> ans_good = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    shellSort(good_test);
    assert(good_test == ans_good);
    cout << "the first test is completed" << endl;

    vector<int> mean_test = { 7, 2, 9, 4, 10, 1, 3, 8, 5, 6, 12, 15, 11, 13, 14, 20, 18, 17, 19, 16 };
    vector<int> ans_mean = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    shellSort(mean_test);
    assert(mean_test == ans_mean);
    cout << "the second test is completed" << endl;

    // Массив создан таким образом, чтобы runs были минимальной длины (1-2 элемента) это делается за счет чередования больших и малых чисел
    vector<int> bad_test = { 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    vector<int> ans_bad = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    shellSort(bad_test);
    assert(bad_test == ans_bad);
    cout << "the third test is completed" << endl;
}

void Test_time(const vector<string>& filenames) {
    for (size_t i = 0; i < filenames.size(); i++) {
        // Читаем данные из файла
        vector<int> data = readFile(filenames[i]);

        // Измеряем время сортировки
        auto start = chrono::high_resolution_clock::now();
        shellSort(data);
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

    shellSort(arr);

    cout << "the sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
