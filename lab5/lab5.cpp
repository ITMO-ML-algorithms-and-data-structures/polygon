#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include <chrono>


using namespace std;

vector<int> insertionSort(vector<int> array) {
    int n = array.size(); //int = 4 bytes, O(1)
    for(int i = 1; i < n; i++) { //int = 4 bytes, O(1) + O(1) + O(1) * O(N)
        for(int j = i; j > 0 && array[j - 1] > array[j]; j--) { //int = 4 bytes, 6 * O(1) * среднее кол-во итераций N/2 => O(N)
            // меняем местами элементы
            swap(array[j - 1], array[j]);//O(1) * 5
        }
    }
    //Сложность алгоритма O(N^2) =  3 * O(1) * O(N) * ((6 + 5) * O(1) * O(N/2))
    //доп память только на вспомогательные переменные, перестановка на месте. Пространственная сложность O(1)
    return array;
}


/*
//Bubble sort для сравнения с CombSort
vector<int> bubbleSort(vector<int> array) {
    int n = array.size(); //int = 4 bytes, O(1)
    for (int i = 0; i < n; i++) {//int = 4 bytes, O(1) + O(1) + O(1) * O(N)
        for (int j = 0; j < n - 1; j++) { //int = 4 bytes, O(1) + O(1) + O(1) * O(N)
            if (array[j] > array[j + 1]) {//O(1) * 3
                // меняем местами элементы
                swap(array[j + 1], array[j]);//O(1) * 5
            }
        }
        //O(N^2)
    }
    return array;
}
*/

vector<int> combSort(vector<int> array) {
    int n = array.size(); //int = 4 bytes, O(1)
    int step = n; //int = 4 bytes, O(1)
    bool flag = false; //int = 1 byte, O(1)
    int num = 0; //int = 4 bytes, O(1)
    while (step > 1 || flag) { //O(1) * 3 
        if (step > 1) {// O(1)
            step = step * 1000 / 1247; // O(1) * 3 
        }//O(logN) шаг уменьшается в 1,247 раз
        // cout << step << " ";
        flag = false; // O(1)
        int i = 0; //int = 4 bytes, O(1)
        while (i + step < n) { //O(1) * 2  сложность цикла линейная O(N), среднее значение меньше N/2
            if (array[i] > array[i + step]) { //O(1) * 3
                flag = true; //O(1)
                swap(array[i], array[i + step]); //O(1) * 5
            }
            i++; //O(1)
        }
        // num++;
        // cout << step << " ";
    }
    //Сложность алгоритма O(N*logN) =  6 * O(1) * O(logN) * ((6 + 5) * O(1) * O(N/2))
    //доп память только на вспомогательные переменные, перестановка на месте. Пространственная сложность O(1)
    return array;
}

vector<int> countingSort(vector<int> array) {
    const int K = 1e5;// 4 byte O(1)
    vector<int> c(K+1);// K * 4 byte + 24 byte Vector
    int n = array.size(); // 4 byte O(1)

    for (int i = 0; i < n; i++) // 4 byte once, (O(1) + O(1)) * O(N)
        c[array[i]]++; // O(1) + O(1) + O(1)

    int b = 0;// 4 byte O(1)
    for (int i = 0; i <= K; i++) {// 4 byte once, (O(1) + O(1)) * O(K)
        while (c[i] != 0) { //O(1) + O(1)
            array[b] = i; // Суммарно O(N)
            b++; //O(1)
            c[i]--; //O(1) + O(1)
        }
    }
    //Сложность алгоритма O(K*N) =  5 * O(1) * O(N) + (4 * O(1) * O(K) * 3 * O(1) * O(N))
    //доп память на вектор для подсчета частоты + вспомогательные переменные. Пространственная сложность O(K)
    return array;
}

vector<int> readDataset(string filename) {
    vector<int> input_array;
    // Открываем файл
    ifstream in(filename.c_str());  // O(1) - открытие файла
    // Считываем следующую строку из файла до конца.
    int number; // O(1) - создание переменной

    while(in >> number) { // O(N) - цикл while
        input_array.push_back(number); // O(1) - добавление строки в вектор
    }

    in.close(); //O(1) - закрытие файла
    return(input_array);
}

//Тесты cassert
void test_sorts() 
{
    vector<int> input_1 = {9, 0, 11, 10, 3, 2};
    vector<int> expected_output_1 = {0, 2, 3, 9, 10, 11};
    vector<int> result_1_1 = insertionSort(input_1);
    vector<int> result_1_2 = combSort(input_1);
    vector<int> result_1_3 = countingSort(input_1);
    assert(
        result_1_1 == expected_output_1 && 
        result_1_2 == expected_output_1 && 
        result_1_3 == expected_output_1
        );
    cout << "test 1 is successful" << endl;

    vector<int> input_2 = {9, 8, 3, 2, 1, 0};
    vector<int> expected_output_2 = {0, 1, 2, 3, 8, 9};
    vector<int> result_2_1 = insertionSort(input_2);
    vector<int> result_2_2 = combSort(input_2);
    vector<int> result_2_3 = countingSort(input_2);
    assert(
        result_2_1 == expected_output_2 && 
        result_2_2 == expected_output_2 && 
        result_2_3 == expected_output_2
        );
    cout << "test 2 is successful" << endl;

    vector<int> input_3 = {1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> expected_output_3 = {1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> result_3_1 = insertionSort(input_3);
    vector<int> result_3_2 = combSort(input_3);
    vector<int> result_3_3 = countingSort(input_3);
    assert(
        result_3_1 == expected_output_3 && 
        result_3_2 == expected_output_3 && 
        result_3_3 == expected_output_3
        );
    cout << "test 3 is successful" << endl;

    vector<int> input_4 = {};
    vector<int> expected_output_4 = {};
    vector<int> result_4_1 = insertionSort(input_4);
    vector<int> result_4_2 = combSort(input_4);
    vector<int> result_4_3 = countingSort(input_4);
    assert(
        result_4_1 == expected_output_4 && 
        result_4_2 == expected_output_4 && 
        result_4_3 == expected_output_4
        );
    cout << "test 4 is successful" << endl;
}

int main() {

    vector<int> input_array = readDataset("dataset.txt"); //O(1) - создание вектора

    int arr_size = input_array.size();

    auto start1 = chrono::high_resolution_clock::now(); 
    vector<int> result1 = insertionSort(input_array);
    auto start2 = chrono::high_resolution_clock::now();
    vector<int> result2 = combSort(input_array);
    auto start3 = chrono::high_resolution_clock::now();
    vector<int> result3 = countingSort(input_array);
    auto endall = chrono::high_resolution_clock::now();

    auto duration1 = chrono::duration_cast<chrono::microseconds>(start2 - start1);
    auto duration2 = chrono::duration_cast<chrono::microseconds>(start3 - start2);
    auto duration3 = chrono::duration_cast<chrono::microseconds>(endall - start3);

    ofstream out;
    out.open("result.txt", ios_base::app);// O(1) - открытие файла
    out << arr_size << ";" << duration1.count() << ";" << duration2.count() << ";" << duration3.count() << endl;
    out.close(); // O(1) - закрытие файла

    // test_sorts();

    return 0;
}