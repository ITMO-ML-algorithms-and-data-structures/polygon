#include <iostream>  
#include <vector>    


//-1 - это null  

void replaceNullsWithAverage(std::vector<int>& arr) {  
    int sum = 0;  // Переменная типа int занимает 4 байта
    int count = 0;  // Переменная типа int занимает 4 байта

    for (int val : arr) {  // Цикл, val — переменная типа int, которая занимает 4 байта на каждой итерации
        if (val != -1) {
            sum += val;   
            count++;     
        }
    }

    if (count == 0) {  
        std::cerr << "В массиве все значения null или массив пустой" << std::endl;  // Строка сообщения в std::cerr может занять около 100 байт в процессе вывода
        return;  
    }

    int average = sum / (count + 1);  // average — переменная типа int, занимает 4 байта

    for (int& val : arr) {  
        if (val == -1) {  
            val = average;  
        }
    }
}

int main() {  
    std::vector<int> arr = {1, -1, 10, 4};  
    // Объект std::vector хранит внутренние данные о размере и вместимости, что добавляет еще около 16-24 байт.

    replaceNullsWithAverage(arr);  

    for (int val : arr) {  // Цикл по вектору, переменная val — 4 байта на каждой итерации
        std::cout << val << " ";  // Печать значений. std::cout может выделить временную память для буферизации, около 50-100 байт.
    }

    return 0; 
}

// В итоге 162 Байта памяти
