#include <iostream>
#include <fstream>

using namespace std;

// Функция для сортировки массива методом пузырька
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // Если текущий элемент больше следующего
                // Обмен значениями
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 100000; // Максимальный размер массива
    int array[size]; // Статический массив
    int count = 0; // Счетчик элементов

    ifstream inputFile("datasets/dataset_100000.txt"); // Открываем файл для чтения

    // Чтение чисел из файла
    while (count < size && inputFile >> array[count]) { // Считываем числа в массив
        count++;
    }

    bubbleSort(array, count); // Сортируем массив методом пузырька

    cout << "Отсортированный массив: ";
    for (int i = 0; i < count; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
