#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> read_file(const string& filename) {
    vector<int> arr; // Вектор для хранения элементов массива
    ifstream inputFile(filename); // Открываем файл для чтения

    int number;
    while (inputFile >> number) { // Читаем числа из файла
        arr.push_back(number); // Добавляем каждое число в вектор
    }

    return arr; // Возвращаем заполненный массив
}
// Функция для разделения массива
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Выбираем последний элемент в качестве опорного
    int i = low - 1; // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // Если текущий элемент меньше или равен опорному
            i++; // Увеличиваем индекс меньшего элемента
            swap(arr[i], arr[j]); // Меняем местами
        }
    }
    swap(arr[i + 1], arr[high]); // Меняем опорный элемент с элементом после последнего меньшего
    return i + 1; // Возвращаем индекс опорного элемента
}

// Функция быстрой сортировки
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Находим индекс опорного элемента

        // Рекурсивно сортируем элементы до и после разделения
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> array = read_file("datasets/dataset_1000.txt"); // Пример массива для сортировки
    int n = array.size();

    quickSort(array, 0, n - 1); // Сортируем массив

    cout << "Отсортированный массив: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
