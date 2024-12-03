#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <assert.h>


template <typename T>
std::vector<std::vector<T>> read_csv(const char filename[], const char delimiter = ',', bool skip_header = true) {
    // Эта функция нужно для задач машинного обучения уровня hard+, игнорируйте ее если обратного не сказано
    std::vector<std::vector<T>> data;
  
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open the file");
    }

    int i = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        std::vector<T> row;

        while (std::getline(ss, value, delimiter)) {
            std::istringstream(value) >> value; // Преобразование строки в нужный тип
            T number;
            if constexpr (std::is_same<T, int>::value) {
                number = std::stoi(value); // Для int
            } else {
                number = std::stof(value); // Для float
            }
            row.push_back(number);
        }

        if (!skip_header || i > 0) {
            // Пропускаем первую строку с названиями столбцов
            data.push_back(row);
        }
        
        i++;
    }

    return data;
}


template <typename T>
std::vector<T> read_array_from_file(const char filename[]) {
    std::vector<T> data;
  
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open the file");
    }

    std::string value;
    while (std::getline(file, value)) {
        T value_processed;

        if constexpr (std::is_same<T, int>::value) {
            value_processed = std::stoi(value); // Для int
        } else if constexpr (std::is_same<T, float>::value) {
            value_processed = std::stof(value); // Для float
        } else {
            value_processed = value;
        }

        data.push_back(value_processed);
    }

    return data;
}

void run_tests() {
    // Проверка что массив с int числами считывается корректно
    std::vector<int> vec_int = read_array_from_file<int>("../data/tests/vector1d_int.csv");
    std::vector<int> vec_int_true = {1, 2, 3, 4, 5};
    assert(std::equal(vec_int.begin(), vec_int.end(), vec_int_true.begin()));
    
    // Проверка что массив с float числами считывается корректно
    std::vector<float> vec_float = read_array_from_file<float>("../data/tests/vector1d_float.csv");
    std::vector<float> vec_float_true = {1.1, 1.2, 2.3, 3.4};
    assert(std::equal(vec_float.begin(), vec_float.end(), vec_float_true.begin()));
    
    // Проверка что массив с строками числами считывается корректно
    std::vector<std::string> vec_str = read_array_from_file<std::string>("../data/tests/vector1d_str.csv");
    std::vector<std::string> vec_str_true = {"abc", "abv", "qqq", "www"};
    assert(std::equal(vec_str.begin(), vec_str.end(), vec_str_true.begin()));

    std::cout << "All tests done!" << std::endl;
}

int main() {
    run_tests();

    return 0;
}