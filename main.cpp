#include <iostream>
#include <vector>
#include <cassert>
#define MIN_MERGE 32
void oddEvenSort(std::vector<int>& arr) {
    int n = arr.size();
    bool flag = true;

    while (flag) {
        flag=false;

        for (int i = 0; i < n-1; i+=2) {//чет
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i],arr[i+1]);
                flag = true;
            }
        }
        for (int i = 1; i < n-1; i+=2) {//нечет
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i],arr[i+1]);
                flag = true;
            }
        }
    }
}

void output(const std::vector<int>& arr) {//функция вывода
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
}

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;  //Инициализация самого большого элемента как корня
    int left = 2 * i + 1;//Левый дочерний элемент
    int right = 2 * i + 2;//Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый дочерний элемент больше, чем самый большой до сих пор
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    //Если самый большой элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        //Рекурсивно вызываем heapify на измененной поддереве
        heapify(arr, n, largest);
    }
}


void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    //Строим максимальную кучу
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    //Извлекаем элементы из кучи по одному
    for (int i = n - 1; i >= 1; i--) {
        //Перемещаем корень в конец
        std::swap(arr[0], arr[i]);

        //Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

//Вычисление минимального размера запуска (run)
int minRunLength(int n) {
    int r = 0;
    while (n >= MIN_MERGE) {
        r = r | n & 1;
        n >>= 1;
    }
    return n + r;
}

//Сортировка вставками для подмассива от left до right
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//Слияние двух отсортированных подмассивов
void merge(std::vector<int>& arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    std::vector<int> left(len1), right(len2);

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

//Основная функция Timsort
void timSort(std::vector<int>& arr) {
    int n = arr.size();
    int minRun = minRunLength(MIN_MERGE);

    //Сортируем каждый подмассив размером до minRun с помощью сортировки вставками
    for (int start = 0; start < n; start += minRun) {
        int end = std::min(start + MIN_MERGE - 1, n - 1);
        insertionSort(arr, start, end);
    }

    //Сливаем подмассивы
    for (int size = MIN_MERGE; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

void testSort(void(*Func)(std::vector<int>&)) {
    std::vector<int> bestcase = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> middlecase = {4,2,1,3,5,7,6,10,8,9};
    std::vector<int> worstcase = {10,9,8,7,6,5,4,3,2,1};

    std::vector<int> expected = {1,2,3,4,5,6,7,8,9,10};
    //bestcase
    std::vector<int> testbest = bestcase;
    Func(testbest);
    assert(testbest==expected);
    std::cout<<"Test bestcase  passed"<<std::endl;

    //middlecase
    std::vector<int> testmiddle = middlecase;
    Func(testmiddle);
    assert(testmiddle==expected);
    std::cout<<"Test middlecase  passed"<<std::endl;

    //worstcase
    std::vector<int> testworst = worstcase;
    Func(testworst);
    assert(testworst==expected);
    std::cout<<"Test worstcase  passed"<<std::endl;
}

int main() {
    std::vector<int> arr = {9,8,7,6,5,4,3,2,1};
    testSort(oddEvenSort);
    testSort(heapSort);
    testSort(timSort);
    output(arr);
    return 0;
}
