#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;

void bucketSort(int arr[], int size) {
    // находим максимальное и минимальное значение в массиве
    int maxVal = arr[0]; // 4 байта
    int minVal = arr[0]; // 4 байта
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) { // O(n)
            maxVal = arr[i];
        }    
        if (arr[i] < minVal) { // O(n)
            minVal = arr[i];
        }   
    }

    // количество ведер
    int bucketCount = max(1, size / 5); //  1 ведро на каждые 5 элементов
    vector<vector<int>> buckets(bucketCount);

    // размер ведра
    double bucketRange = static_cast<double>(maxVal - minVal + 1) / bucketCount;

    // распределяем элементы по ведрам
    // O(n)
    for (int i = 0; i < size; i++) {
        int bucketIndex = static_cast<int>((arr[i] - minVal) / bucketRange);
        if (bucketIndex >= bucketCount) { // в случае, если индекс выходит за пределы
            bucketIndex = bucketCount - 1;
        }
        buckets[bucketIndex].push_back(arr[i]);
    }

    // сортируем каждое ведро и собираем результаты
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        // используем сортировку вставками для небольших ведер
        if (!buckets[i].empty()) {
            sort(buckets[i].begin(), buckets[i].end());
            for (int j = 0; j < buckets[i].size(); j++) {
                arr[index++] = buckets[i][j]; // собираем отсортированные элементы обратно в массив
            }
        }
    }
}

// функция для проверки результата теста и вывода соответствующего сообщения
void assertTest(bool ans) {
    if (ans) {
        cout << "The test is passed" << '\n';
    } else {
        cout << "The test is not passed" << '\n';
    }
}

void generateRandomNumbers(vector<int>& numbers, int count) {
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < count; ++i) {
        numbers.push_back(rand() % 100); // Генерация случайного числа от 0 до 99
    }
}

// тесты
void runTest() {

// лучший случай
// O(n + k), где k — это максимальное количество элементов в любом ведре (при равномерном распределении)
int best_case[] = {1, 2, 4, 4, 6, 8, 12};
int expected_best_case[] = {1, 2, 4, 4, 6, 8, 12};
int size_best_case = sizeof(best_case) / sizeof(best_case[0]);
bucketSort(best_case, size_best_case);  
bool result_best_case = equal(begin(best_case), end(best_case), begin(expected_best_case));
assertTest(result_best_case);

// средний случай
// O(n + k * log(k)), где k — количество ведер
int averege_case[] = {1, 4, 2, 8, 6, 12, 4};
int expected_averege_case[] = {1, 2, 4, 4, 6, 8, 12};
int size_averege_case = sizeof(averege_case) / sizeof(averege_case[0]);
bucketSort(averege_case, size_averege_case);  
bool result_averege_case = equal(begin(averege_case), end(averege_case), begin(averege_case));
assertTest(result_averege_case);

// худший случай
// O(n^2), все элементы попадают в одно ведро 
int worst_case[] = {12, 12, 12, 12, 12, 12};
int expected_worst_case[] = {12, 12, 12, 12, 12, 12};
int size_worst_case = sizeof(worst_case) / sizeof(worst_case[0]);
bucketSort(worst_case, size_worst_case);  
bool result_worst_case = equal(begin(worst_case), end(worst_case), begin(expected_worst_case));
assertTest(result_worst_case);
}


int main() {
    
    int arr[] = {0, 23, 65, 4, 1, 90, 7, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, size);

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

    bucketSort(randomArr, count);

    // Текущее время окончания выполнения работы
    auto end = chrono::high_resolution_clock::now();
    
    // Продолжительность выполнения работы
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Sorting completed." << endl;
    cout << "Running time: " << duration.count() << " microseconds" << endl;
 
    return 0;
}

// Итоговая память для функции bucketSor составляет 8 байт
