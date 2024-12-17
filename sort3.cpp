#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;


vector<int> read_file(const string filename) {
    vector<int> mas;
    ifstream in(filename);
    int number;

    while (in >> number) {
        mas.push_back(number);
    }
    return mas;
}

// Функция сортировки по разряду
void countingSort(vector<int>& arr, int exp) {
    vector<int> count(10, 0); // Массив для подсчета вхождений цифр (от 0 до 9)
    vector<int> output(arr.size()); // Массив для временного хранения отсортированных данных

    // Подсчитываем количество вхождений цифр в разряде
    for (int num : arr) {
        count[(num / exp) % 10]++; // Извлекаем цифру на текущем разряде
    }

    // Преобразуем массив count, чтобы он хранил позицию для каждой цифры
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1]; // Преобразование: теперь count[i] указывает на индекс последнего вхождения цифры i
    }

    // Строим отсортированный массив на основе count
    for (int i = arr.size() - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10; // Извлекаем цифру на текущем разряде
        output[count[digit] - 1] = arr[i]; // Помещаем число в правильную позицию
        count[digit]--; // Уменьшаем счетчик для данной цифры
    }

    // Копируем отсортированный массив обратно в оригинальный
    arr = output;
}

// Основная функция поразрядной сортировки
void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end()); // Находим максимальное значение в массиве

    // Проходим по всем разрядам (от младшего к старшему)
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp); // Сортируем массив по текущему разряду
    }
}

int main() {
    clock_t start = clock();
    vector<int> arr = read_file("/Users/mir/CLionProjects/lab-5/arr_1_mln.txt");

    radixSort(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    clock_t end = clock();
    double time = (end - start) / (double)CLOCKS_PER_SEC;
    cout << time;
}