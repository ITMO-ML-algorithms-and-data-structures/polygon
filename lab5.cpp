#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <cassert>
#include <chrono>
#include <random>
using namespace std;

/*-------------------------------------- Сортировка ГНОМЬЯ ------------------------------------------*/

void swap(int& a, int& b) { // O(1)
    int temp = a; // 4 байта
    a = b;
    b = temp;
}

void GnomeSort(vector<int>& array_unsorted) { // O(n) в лучшем случае (не попадая на else,
//                                                          те для отсортированного массива)
    int current_index = 0; // 4 байта
    int array_len = array_unsorted.size(); // 4 байта
    while (current_index != array_len) { // O(n^2) в худшем случае (если мы n раз попадём на swap)
        if (current_index == 0 || array_unsorted[current_index] >= array_unsorted[current_index - 1]) {
            ++current_index;
        } else {
            swap(array_unsorted[current_index], array_unsorted[current_index - 1]);
            --current_index;
        }
    }
}

// память под создание новых переменных: 12 байт
/*--------------------------------- Сортировка ПИРАМИДАЛЬНАЯ: ------------------------------------------*/

// функция для преобразования поддерева с корнем в i в Max Heap

//// худший==лучший случай: O(log n), тк необходимо "просеять" каждый элемент вниз по дереву
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // 4 байта
    int left = 2 * i + 1; // 4 байта
    int right = 2 * i + 2; // 4 байта

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main функция, создание кучи - O(n)
void heapSort(vector<int>& arr) {
    int n = arr.size(); // 4 байта
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


// Память: под создание новых переменных 24 байта
/*-------------------------------------- Сортировка RADIX -------------------------------------------*/

void CountingSortForRadix(vector<int>& arr, int exp) {
    long int n = arr.size(); // 4 байта
    vector<int> output(n); // 4n байт
    int count[10] = {0}; // счетчик для 10 возможных значений разряда \\ 4 байта

    // подсчет количества вхождений
    for (int i = 0; i < n; i++) { // O(n)
        count[(arr[i] / exp) % 10]++;
    }

    // преобразование count[i] по позиции разряда
    for (int i = 1; i < 10; i++) { // O(10)
        count[i] += count[i - 1];
    }
    // выходной массив
    for (int i = n - 1; i >= 0; i--) { // O(n)
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // копируем отсортированные элементы обратно в оригинальный массив
    for (int i = 0; i < n; i++) { // O(n)
        arr[i] = output[i];
    }
}

// Основная функция поразрядной сортировки
void RadixSort(vector<int>& arr) {
    if (arr.empty()) return; // Проверка на пустой массив

    // максимальное значение, чтобы определить количество разрядов
    int maxVal = *max_element(arr.begin(), arr.end()); // O(n), 4 байта

    // подсчет сортировки для каждого разряда
    for (int exp = 1; maxVal / exp > 0; exp *= 10) { // O(k), где k - номер макс разряда
        CountingSortForRadix(arr, exp);
    }
}

// итак, асимптотическая сложность O(n*k), (k не столь большое тк кол-во разрядов),
// она одинакова для лучших и худших случаев, однако на время выполнения влияет
// разброс разрядов

// память: 4n + 12 байт

//-------------ФУНКЦИИ ДЛЯ ГЕНЕРАЦИИ ВХОДНЫХ МАССИВОВ НЕУДОБНЫХ ДЛЯ НАПИСАННЫХ АЛГОРИТМОВ----------


// функция для генерации массива для Gnome Sort (обратный порядок)
vector<int> generateGnomeSortArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = size - i; // заполнение массива в обратном порядке
        // будет наихудшим случаем для gnomesort тк это сортировка сравнениями
    }
    return arr;
}

// функция для генерации массива для Heap Sort (одинаковые элементы)
vector<int> generateHeapSortArray(int size) {
    return vector<int>(size, 8); // все элементы равны 8, heapsort в любом случае
    // будет перебирать их всех, но такой массив показывает что подход heapsort 
    // при одинаковых данных в массиве неэффективен
}

// функция для генерации массива для Radix Sort (большие числа)
vector<int> generateRadixSortArray(int size) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 9999999); // Числа от 0 до 9999999

    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
    return arr;
}

//-------------------------------------------------------------------------------------------------


void collectData() {  
    cout << "Далее вывод для boxplot:" << endl;
    cout << "Size, GnomeSort Duration, HeapSort Duration, RadixSort Duration" << endl;

    for (int size = 1000; size <= 1000000; size += 1000) {
        vector<int> gnomeArray = generateGnomeSortArray(size);
        vector<int> heapArray = generateHeapSortArray(size);
        vector<int> radixArray = generateRadixSortArray(size);

        // Измерение времени выполнения Gnome Sort
        auto startGnome = high_resolution_clock::now();
        GnomeSort(gnomeArray);
        auto endGnome = high_resolution_clock::now();
        duration<double> durationGnome = endGnome - startGnome;

        // Измерение времени выполнения Heap Sort
        auto startHeap = high_resolution_clock::now();
        heapSort(heapArray);
        auto endHeap = high_resolution_clock::now();
        duration<double> durationHeap = endHeap - startHeap;

        // Измерение времени выполнения Radix Sort
        auto startRadix = high_resolution_clock::now();
        RadixSort(radixArray);
        auto endRadix = high_resolution_clock::now();
        duration<double> durationRadix = endRadix - startRadix;

        cout << size << "," 
             << durationGnome.count() << "," 
             << durationHeap.count() << "," 
             << durationRadix.count() << endl;
    }
}

int main() {
    const int size = 100;
    vector<int> gnomeArray = generateGnomeSortArray(size);
    vector<int> heapArray = generateHeapSortArray(size);
    vector<int> radixArray = generateRadixSortArray(size);

    // измерение времени выполнения GnomeSort
    auto startGnome = chrono::high_resolution_clock::now();
    GnomeSort(gnomeArray);
    auto endGnome = chrono::high_resolution_clock::now();
    chrono::duration<double> durationGnome = endGnome - startGnome;

    cout << "Время выполнения Gnome Sort: " << durationGnome.count() << " секунд" << endl;

    // измерение времени выполнения HeapSort
    auto startHeap = chrono::high_resolution_clock::now();
    heapSort(heapArray);
    auto endHeap = chrono::high_resolution_clock::now();
    chrono::duration<double> durationHeap = endHeap - startHeap;

    cout << "Время выполнения Heap Sort: " << durationHeap.count() << " секунд" << endl;

    // измерение времени выполнения RadixSort
    auto startRadix = chrono::high_resolution_clock::now();
    RadixSort(radixArray);
    auto endRadix = chrono::high_resolution_clock::now();
    chrono::duration<double> durationRadix = endRadix - startRadix;
    cout << "Время выполнения Radix Sort: " << durationRadix.count() << " секунд" << endl;
    collectData();
    return 0;
}