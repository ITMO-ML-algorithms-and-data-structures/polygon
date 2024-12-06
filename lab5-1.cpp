#include <iostream>
using namespace std;

// функция для пузырьковой сортировки
void bubbleSort(int arr[], int n) {//Объявляет функцию bubbleSort (принимает 2 параметра-->)
//arr[] - массив целых чисел, который нужно отсортировать; n - его размер
// тип void означает, что функция ничего не возвращает.
   
    for (int i = 0; i < n - 1; i++) {//внешний цикл, управляет кол-вом полных проходов по массиву//проходит по индексам от 0 до n-1
        for (int j = 0; j < n - i - 1; j++) {//внутренний цикл//проходит по элементам массива, сравнивая соседние
                                             // n - i - 1 уменьшает количество сравнений с каждым проходом
                                             //тк последние элементы уже отсортированы
            if (arr[j] > arr[j + 1]) {//проверяет,является ли текущий элемент больше следующего.Если да, их надо поменять местами  
                // Обмен значениями
                int temp = arr[j];//временная переменная temp, в которую сохраняется значение текущего элемента массива
                arr[j] = arr[j + 1];//текущий элемент заменяется значением следующего элемента
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для вывода массива
void printArray(int arr[], int n) {//принимает массив и его размер
    for (int i = 0; i < n; i++) {//проходится по всем элементам и выводит их ↓↓↓
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Определяем размер массива.sizeof(arr)возвращает общий размер массива в байтах
                                          //sizeof(arr[0]) — размер одного элемента массива. 
                                          //Делением этих значений мы получаем количество элементов в массиве.

    cout << "Исходный массив: \n";
    printArray(arr, n);

    bubbleSort(arr, n); // вызов функции пузырьковой сортировки для сортировки массива

    cout << "Отсортированный массив: \n";
    printArray(arr, n); // Вывод отсортированного массива

    return 0;
}
