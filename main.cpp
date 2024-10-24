// Задача: Перемешивание элементов массива
// Cама функция перемешивание массива реализована с помощью алгоритма Фишера, который работает за О(N)
// О(N) - ибо цикл один, а все операции в нем работают за О(1), где N - размер массива

#include <iostream>
#include "shuffle_array.cpp"

int main() {
    // Запускаем функцию с тестами
    if (runTests()) {
        std::cout << "All tests passed" << std::endl;
    } else {
        std::cout << "Tests failing" << std::endl;
    }
    // Вводим размер массива
    int size;
    std::cout << "Input size of array : ";
    std::cin >> size;

    int *array = new int[size]; // создаем динамический массив размером size
    // Вводим элементы массива
    std::cout << "Input array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    // Перетасовка массива с помощью нашей функции
    shuffleArray(array,size);

    // Выводим перетасованный массив
    std::cout << "Shuffled array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Освобождаем память
    delete[] array;
    return 0;
}

