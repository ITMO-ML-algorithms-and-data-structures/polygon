#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <chrono>
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

// Функция для генерации подмассивов
void generateSubarrays(double* arr, int size, const int subarraySize, vector<vector<double>>& subarrays) {
    // Создаем все возможные подмассивы указанного размера
    for (int i = 0; i <= size - subarraySize; ++i) {
        subarrays.push_back(vector<double>(arr + i, arr + i + subarraySize));
    }
}

// Основная функция для создания 5 подмассивов с минимальной метрикой
double** finalDevelopmentClusters(double* arr, int size) {
    if (size < 5) return nullptr; // Проверка на недостаточное количество элементов

    // Массив указателей для результатов
    double** ans = new double*[5];

    // Генерируем подмассивы длины 1
    vector<vector<double>> subarrays;
    generateSubarrays(arr, size, 1, subarrays); // Здесь используем подмассивы длины 1

    // Параметры для поиска минимальных метрик
    double minMetricValues[5];
    fill_n(minMetricValues, 5, numeric_limits<double>::max());

    // Поиск 5 подмассивов с минимальной метрикой
    for (const auto& comb : subarrays) {
        double currentMetric = calculate(comb.data(), comb.size());
        for (int i = 0; i < 5; ++i) {
            if (currentMetric < minMetricValues[i]) {
                // Сдвиг метрик, чтобы освободить место для новой
                for (int j = 4; j > i; --j) {
                    minMetricValues[j] = minMetricValues[j - 1];
                    ans[j] = ans[j - 1];
                }
                // Сохраняем новый подмассив с минимальной метрикой
                ans[i] = new double[comb.size()];
                copy(comb.begin(), comb.end(), ans[i]);
                minMetricValues[i] = currentMetric;
                break; // Прерывание текущего цикла, так как мы нашли место для новой метрики
            }
        }
    }

    return ans; // Возвращаем массив с 5 подмассивами с минимальной метрикой
}


// Преобразование double** в string
string doubleArrayToString(double** array, int rows, int cols) {
    string res;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Форматируем строку с двумя знаками после запятой
            string formatted = to_string(array[i][j]);
            // Правильное форматирование с двумя знаками после запятой
            formatted = formatted.substr(0, formatted.find('.') + 3); // Обрезаем до двух знаков после запятой

            res += formatted;
            if (j < cols - 1) {
                res += " ";
            }
        }
        if (i < rows - 1) {
            res += " ";
        }
    }
    return res;
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
    auto start = chrono::high_resolution_clock::now();
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
        cout << result_check_test(number_line, doubleArrayToString(result, 5, 1)) << endl;
        cout << doubleArrayToString(result, 5, 1) << endl;
        delete[] arr; // Освобождение памяти

        // Освобождение памяти результата
        if (result != nullptr) { // Проверяем, был ли результат найден
            for (int i = 0; i < 5; ++i) {
                delete[] result[i]; // Освобождение памяти для каждого массива
            }
            delete[] result; // Освобождение памяти для указателя на массив
            result = nullptr; // Обязательно обнуляем указатель для предотвращения двойного освобождения
        }
    }
    stream_test.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Время выполнения: " << duration.count() << " секунд" << endl;
    return 0;
}