#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

// Функция для расчета метрики по массиву
double calculate(const double* arr, int size) {
    double dist = 0;
    double arr_sum = 0;
    for (int i = 0; i < size; i++) {
        arr_sum += arr[i];
    }
    double average = arr_sum / size;  // Расчет среднего значения
    for (int i = 0; i < size; i++) {
        dist += abs(arr[i] - average);
    }
    return dist;
}

// Функция для вычисления метрики
double metric(const vector<double>& comb) {
    double sum = 0.0;
    for (double value : comb) {
        sum += value; // Например, просто сумма всех элементов
    }
    return sum / comb.size(); // Возвращаем среднее значение
}


// Функция для записи значений из файла в динамический массив
double* readArrayFromFileToDynamicArray(const string& filename, int& size) {
    vector<double> dynamicArray;  // Использование vector для динамического массива
    ifstream inputFile(filename);
    double number;

    while (inputFile >> number) {
        dynamicArray.push_back(number);
    }

    size = dynamicArray.size();
    double* result = new double[size];
    copy(dynamicArray.begin(), dynamicArray.end(), result); // Копируем данные в массив
    return result;
}

// Генерация всех возможных сочетаний массивов (комбинаций)
void generateCombinations(double* arr, int size, vector<vector<double>>& combinations, int depth = 0, vector<double> currentCombination = {}) {
    if (depth == 5) { // Предполагаем, что мы ищем 5 массивов
        combinations.push_back(currentCombination);
        return;
    }
    for (int i = 0; i < size; ++i) {
        currentCombination.push_back(arr[i]); // Добавляем текущий элемент в комбинацию
        generateCombinations(arr, size, combinations, depth + 1, currentCombination);
        currentCombination.pop_back(); // Убираем последний добавленный элемент
    }
}

double** finalDevelopmentClusters(double* arr, int size) {
    std::vector<std::vector<double>> combinations; // Для хранения всех сочетаний
    generateCombinations(arr, size, combinations); // Генерация всех комбинаций

    double** ans = nullptr; // Результат
    double minMetricValue = std::numeric_limits<double>::max(); // Инициализация большой метрики

    // Для каждой комбинации
    for (const auto& comb : combinations) {
        double currentMetric = metric(comb);
        if (currentMetric < minMetricValue) {
            minMetricValue = currentMetric;

            // Освобождаем предыдущий массив, если он был выделен
            if (ans != nullptr) {
                for (int i = 0; i < 5; ++i) {
                    delete[] ans[i]; // Освобождаем память для каждой строки
                }
                delete[] ans; // Освобождаем память для массива указателей
            }

            // Создаем новый массив для хранения результатов
            ans = new double*[5]; // Предполагается, что мы хотим хранить 5 массивов
            for (int i = 0; i < 5; ++i) {
                ans[i] = new double[comb.size()]; // Выделяем память под массивы
                std::copy(comb.begin(), comb.end(), ans[i]); // Копируем данные
            }
        }
    }

    return ans; // Возвращаем наилучшее решение
}


// Преобразование double** в string
string doubleArrayToString(double** array, int rows, int cols) {
    ostringstream oss;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            oss << fixed << setprecision(2) << array[i][j];
            if (j < cols - 1) {
                oss << " ";
            }
        }
        if (i < rows - 1) {
            oss << " ";
        }
    }
    return oss.str();
}

// Функция для проверки ответов
string result_check_test(int number_line, string current_line_test) {
    ifstream stream_answer("answer.txt");
    string current_line_answer;
    for (int i = 0; getline(stream_answer, current_line_answer); i++) {
        if (i == number_line) {
            break;
        }
    }
    return current_line_answer == current_line_test ? "True" : "False";
}

// Главная функция
int main() {
    int size = 0;
    ifstream stream_test("test.txt");
    if (!stream_test.is_open()) {
        cout << "Ошибка открытия файла: test.txt" << endl;
        return 1;
    }

    string current_line_test;
    int number_line = 0;
    while (getline(stream_test, current_line_test)) {
        number_line++;
        double* arr = readArrayFromFileToDynamicArray("test.txt", size);
        double** result = finalDevelopmentClusters(arr, size);
        cout << result_check_test(number_line, doubleArrayToString(result, 1, 5)) << endl;
        //cout << doubleArrayToString(result, 1, 5);
        delete[] arr; // Освобождение памяти

        // Освобождение памяти результата
        if (result != nullptr) { // Проверяем, был ли результат найден
            for (int i = 0; i < 5; ++i) {
                delete[] result[i]; // Освобождение памяти для каждого массива
            }
            delete[] result; // Освобождение памяти для указателя на массив
        }
    }
    stream_test.close();
    return 0;
}
