#include <iostream>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

void shakerSort(int* arr, int array_size) {
    int i; // переменная для итерации; 4 байта
    int t; // переменная для временного хранения значения при обмене элементов; 4 байта
    int left = 0; // переменная для отслеживания индекса текущей левой границы; 4 байта
    int right = array_size - 1; // переменная для отслеживания индекса текущей правой границы; 4 байта

    // основной цикл, выполняется, пока левая граница меньше правой
    do {

        // прямой проход: перемещение больших элементов вправо
        for (i = left; i < right; i++)
        // если текущий элемент больше последующего, меняем их местами
        if (arr[i] > arr[i + 1]) {
            t = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = t;
        }
        // уменьшаем правую границу, т. к. последний элемент найден
        -- right;
        
        // обратный проход: перемещение меньших элементов влево
        for (i = right; i > left; --i)
        // если текущий элемент меньше предыдущего, меняем их местами 
        if (arr[i] < arr[i - 1]) {
            t = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = t;
        }
        // увеличиваем левую границу, т. к. первый элемент найден
        ++left;

    } while (left < right);
}

// Функция для проверки результата теста и вывода соответствующего сообщения
void assertTest(bool ans) {
    if (ans) {
        cout << "The test is passed" << '\n';
    } else {
        cout << "The test is not passed" << '\n';
    }
}

// тесты
void runTest() {

// лучший случай
// O(n)
int best_case[] = {1, 2, 4, 6, 8, 12};
int expected_best_case[] = {1, 2, 4, 6, 8, 12};
int size_best_case = sizeof(best_case) / sizeof(best_case[0]);
shakerSort(best_case, size_best_case);  
bool result_best_case = equal(begin(best_case), end(best_case), begin(expected_best_case));
assertTest(result_best_case);

// средний случай
// O(n^2)
int averege_case[] = {1, 4, 2, 8, 6, 12};
int expected_averege_case[] = {1, 2, 4, 6, 8, 12};
int size_averege_case = sizeof(averege_case) / sizeof(averege_case[0]);
shakerSort(averege_case, size_averege_case);  
bool result_averege_case = equal(begin(averege_case), end(averege_case), begin(averege_case));
assertTest(result_averege_case);

// худший случай
// O(n^2)
int worst_case[] = {12, 8, 6, 4, 2, 1};
int expected_worst_case[] = {1, 2, 4, 6, 8, 12};
int size_worst_case = sizeof(worst_case) / sizeof(worst_case[0]);
shakerSort(worst_case, size_worst_case);  
bool result_worst_case = equal(begin(worst_case), end(worst_case), begin(expected_worst_case));
assertTest(result_worst_case);
}

void generateRandomNumbers(vector<int>& numbers, int count) {
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < count; ++i) {
        numbers.push_back(rand() % 100); // Генерация случайного числа от 0 до 99
    }
}


int main() {
    int arr[] = {2, 78, 56, 34, 2, 12, 67, 90, 42, 11};
    int size =sizeof(arr) / sizeof(arr[0]);

    shakerSort(arr, size);

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    
    runTest(); 

    const int count = 10000; // Количество случайных чисел
    vector<int> randomNumbers;

    // Генерация случайных чисел
    generateRandomNumbers(randomNumbers, count);

    // Преобразование std::vector в массив для сортировки
    int* randomArr = randomNumbers.data();
    
    // Записываем текущее время работы
    auto start = chrono::high_resolution_clock::now();

    shakerSort(randomArr, count);

    // Текущее время окончания выполнения работы
    auto end = chrono::high_resolution_clock::now();
    
    // Продолжительность выполнения работы
    auto duration = chrono::duration_cast< chrono::microseconds>(end - start);

    cout << "Sorting completed." << endl;
    cout << "Running time: " << duration.count() << " milliseconds" << endl;
 


    return 0;
}

// Итоговая память для функции shakerSort составляет 16 байт