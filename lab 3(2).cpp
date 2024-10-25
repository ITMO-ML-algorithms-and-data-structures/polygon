#include <iostream>
#include<vector>
#include<fstream>
#include <fstream>
#include <sstream>
#include <string>


//Тесты
int test_passed = 0;
int test_failed = 0;

void assertEqual(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << "[PASSED]" << testName << "\n";
        test_passed++;
    }
    else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}

void report() {
    std::cout << "\nTests passed total: " << test_passed << "\n";
    std::cout << "\nTests not passed total: " << test_failed << "\n";
}


void test(std::vector<double>& arr, double min_val, double max_val) {
    assertEqual((min_val != max_val), "test zero devision");
    assertEqual((arr.size() <= 1e9), "test input data by condition");
    report();
}


//Функция считывающая датасет
std::vector<double> load_data() {
    std::vector<double> data;
    std::ifstream file("C:\\Users\\admin\\polygon\\bers.tsv");
    std::string line;
    while (std::getline(file, line)) {//Так как строка одна во всем датасете ,то сложность фцункции считывания О(n) 
        std::istringstream ss(line);
        std::string item;  
        while (std::getline(ss, item, '\t')) {
            double item1 = std::stod(item);
            data.push_back(item1);
        }
    }
    return data;
}

int main() {
    //std::vector<double> arr = { 1,100,1000001,2 };//2*О(n)-выделение памяти и инициализация каждой переменной
    std::vector<double> arr = load_data();//О(n) - функция считывания файла и записи его элементов в массив.
    int min_val = arr[0];//О(1)+О(1)+О(1) - выделение памяти ,взятие эл-та по индексу ,присваивание
    int max_val = arr[0];//О(1)+О(1)+О(1) - выделение памяти ,взятие эл-та по индексу ,присваивание
    
    // Проходим по массиву и ищем минимальное и максимальное значение
    int size = arr.size();
    for (size_t i = 1; i < size; ++i) {//В любом случае  O(1)+O(1)+O(7*n) ,т.к. если отсортирован по возрастанию(убыванию)(даже в рамках конкретной пары), то присваивания в одном случае не будет происходить (это обьяснение почему не О(8*N)
        if (arr[i] < min_val) {//O(1)+O(1) - взятие эл-та по индексу и сравнение
            min_val = arr[i];//О(1) - присваивание
        }
        if (arr[i] > max_val) {//O(1)+O(1) - взятие эл-та по индексу и сравнение
            max_val = arr[i];//О(1) - присваивание
        }
    }

    test(arr, max_val, min_val);
    

    for (int k = 0; k < size; k++) {//О(1)+О(1)- инициализация и присваивание//Сложность всего цикла О(5n) (Сравнение + прибавление 1 + Взятие  элемента по индексу ,считаем по формуле  выводим)*n
        //О(1)*n- сравнение n раз; О(1)*n - прибавление 1 n раз // Получается O(2n)
        std::cout << ( (arr[k] - min_val) / (max_val - min_val))<<" ";//(О(1)+О(1)+О(1))*n=O(4n) - Взятие  элемента  по индексу ,считаем и выводим n раз
        }
    //Итого сложность: 11*O(1) + 2*О(n) + O(7n)+O(5n) = O(M) - Линейная.
    
}