#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime> // Для проверки времени работы алгоритма на 25 элементов

/* 
Поиск подмассивов размера K в массиве размера N, сумма элементов которых равна нулю
K = 4, N - до 25. Сложность - medium. Сложность алгоритма не менее N^K.
*/

bool AreDiffirent(std::vector<int> arr1, std::vector<int> arr2) {
    
    std::unordered_map<int, int> hesh_table;
    // Для подсчёта кол-ва элементов используем хэш-таблицу

    for (int i : arr1) {
        ++hesh_table[i];
    }
    for (int i : arr2) {
        ++hesh_table[i];
    }

    for (int i = 0; i < arr1.size(); i++) {
        if (hesh_table[arr1[i]] == 1) { return true; }
    } // Сверяя каждый элемент на наличие уникального элемента, 
      // мы проверяем, различны ли массивы
    return false;
    // Если ничего не подошло, то все элементы повторяются у двух векторов
}


std::vector<std::vector<int>> MakeMasks(std::vector<int> arr) {

    std::vector<std::vector<int>> output;
    
    for (int i1 = 0; i1 < arr.size(); i1++) {
        for (int i2 = 0; i2 < arr.size(); i2++) {
            for (int i3 = 0; i3 < arr.size(); i3++) {
                for (int i4 = 0; i4 < arr.size(); i4++) {
                    if (i1 != i2 && i1 != i3 && i1 != i4 && i2 != i3 && i2 != i4 && i3 != i4
                        && arr[i1] + arr[i2] + arr[i3] + arr[i4] == 0) {

                        std::vector<int> part_of_output = { i1, i2, i3, i4 };
                        bool key = true;

                        for (std::vector<int> vector : output) {
                            if (not AreDiffirent(part_of_output, vector)) {
                                key = false;
                            }
                        }
                        if (key) { output.push_back(part_of_output); }
                        
                    }
                }
            }
        }
    }
    return output;
}

int main() {
    int start = clock();

    std::vector<int> input = { -14, -13, -12, -11, -10,
                               -9, -8, -6, -5, -4,
                               -3, -2, -1, 0, 1,
                               2, 3, 4, 5, 6,
                               7, 8, 9, 10, 11,
                               12, 13, 14, 15, 16};
                            // Массив из 25 элементов

    for (std::vector<int> arr : MakeMasks(input)) {
        for (int a : arr) {
            std::cout << a << " ";
        }
        std::cout << "\n";
    }
    int end = clock();
    int delta = (end - start) / CLOCKS_PER_SEC;

    std::cout << "start: " << start << "; end:  " << end << "\n";

    std::cout << "total time used in seconds: " << delta << std::endl;
}
