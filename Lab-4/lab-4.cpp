#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <limits>
#include <chrono>
#include <algorithm>
#include <iomanip>
using namespace std;

//Преобразование считанной строки в вектор
vector<double> stringToVector(const string& line) {
    vector<double> originalVector;
    string cleanedLine = line;
    
    // Удаляем квадратные скобки
    cleanedLine.erase(0, 1);
    cleanedLine.erase(cleanedLine.size() - 1);

    //Считывание значений и запись их в вектор
    double num = 0;
    stringstream ss(cleanedLine);
    string item;
    while (getline(ss, item, ',')) {
        // Преобразуем каждое число в целое и добавляем в вектор
        originalVector.push_back(stod(item));
    }

    return originalVector;
}

//Преобразование вектора в строку
string vectorToString(const vector<double>& vec) {
    ostringstream res;
    
    res << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        res << fixed << setprecision(1) << vec[i]; // Устанавливаем фиксированную точность
        if (i < vec.size() - 1) { // Не добавляем запятую после последнего элемента
            res << ", ";
        }
    }
    res << "]"; 
    
    return res.str();
}


//Функция для расчёта метрики
double calculateMetric(const vector<double>& cluster){
    if (cluster.empty()) return 0.0;

    // Вычисляем среднее значение
    double sum = 0.0;
    for (double val : cluster) {
        sum += val;
    }
    double mean = sum / cluster.size();

    // Рассчитываем сумму абсолютных отклонений
    double metric = 0.0;
    for (double val : cluster) {
        metric += abs(val - mean);
    }

    return metric;
}

//Функция для генерации всех перестановок кластера
void permute(vector<double>& cluster, int left, int right, double& bestMetric, vector<double>& bestCluster) {
    if (left == right) {
        double currentMetric = calculateMetric(cluster);
        if (currentMetric < bestMetric) {
            bestMetric = currentMetric;
            bestCluster = cluster; // Запоминаем лучший кластер
        }
    } else {
        for (int i = left; i <= right; i++) {
            swap(cluster[left], cluster[i]); // Перестановка
            permute(cluster, left + 1, right, bestMetric, bestCluster); // Корректный рекурсивный вызов
            swap(cluster[left], cluster[i]); // Возврат к исходному порядку
        }
    }
}

//Перебор всех возможных значений разбиения изначального вектора, на 5 подвекторов с наименьшей метрикой
void generatePartitions(const vector<double>& arr, int start, int k, vector<vector<double>>& currentPartition, 
                        double& bestMetric, vector<vector<vector<double>>>& bestPartition) {
    int n = arr.size();

    if (k == 1) {
        // Остался только один кластер
        vector<double> lastCluster(arr.begin() + start, arr.end());
        currentPartition.push_back(lastCluster);

        // Перестановка для текущего кластера
        double clusterMetric = numeric_limits<double>::infinity();
        vector<double> bestCluster;

        permute(currentPartition.back(), 0, currentPartition.back().size() - 1, clusterMetric, bestCluster);
        currentPartition.back() = bestCluster; // Заменяем кластер на лучший

        double metric = 0;
        for (const auto& cluster : currentPartition) {
            metric += calculateMetric(cluster);
        }
        if (metric < bestMetric) {
            bestMetric = metric;
            bestPartition = {currentPartition}; // Запоминаем текущее разбиение
        }
        currentPartition.pop_back();
        return;
    }

    // Обеспечиваем, чтобы минимальная длина для каждого кластера была не меньше 1
    for (int end = start + 1; end <= n - (k - 1); end++) {
        currentPartition.push_back(vector<double>(arr.begin() + start, arr.begin() + end));
        generatePartitions(arr, end, k - 1, currentPartition, bestMetric, bestPartition);
        currentPartition.pop_back();
    }
}

// Функция для проверки ответа
bool comparePartitions(const vector<vector<double>>& actual, const vector<vector<double>>& expected) {
    if (actual.size() != expected.size()) return false;
    for (size_t i = 0; i < actual.size(); ++i) {
        if (actual[i] != expected[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream inputTest("test.txt");
    ifstream answerFile("answer.txt");
    if (!inputTest) { // Проверяет, успешно ли открылся файл
        cerr << "Не удалось открыть файл!" << endl;
        return 0;
    }

    string line;
    while (getline(inputTest, line)) { // Читает файл построчно
        
        auto start = chrono::high_resolution_clock::now();
        
        vector<double> originalVector;
        originalVector = stringToVector(line);

        double bestMetric = numeric_limits<double>::infinity();
        vector<vector<vector<double>>> bestPartition;
        vector<vector<double>> currentPartition;

        generatePartitions(originalVector, 0, 5, currentPartition, bestMetric, bestPartition);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;

        cout << "Лучшее разбиение: " << endl;
        for (const auto& cluster : bestPartition[0]) {
            cout << vectorToString(cluster) << " ";
        }
        cout << endl;
        cout << "Минимальная метрика: " << bestMetric << endl;
        cout << "Время выполнения: " << elapsed.count() << " секунд" << endl;
        
        // Читаем ожидаемое разбиение
        vector<vector<double>> expectedPartition;
        string answerLine;

        if (getline(answerFile, answerLine)) {
            // Парсим строку ответа в вектор векторов
            stringstream ss(answerLine);
            string clusterLine;
            while (getline(ss, clusterLine, '|')) { // РАЗДЕЛИТЕЛЬ - '|' между подкластером
                expectedPartition.push_back(stringToVector(clusterLine));
            }
        }

        // Сравниваем с ожидаемым
        if (comparePartitions(bestPartition[0], expectedPartition)) {
            cout << "Ответ совпадает с ожидаемым." << endl;
        } else {
            cout << "Ответ НЕ совпадает с ожидаемым!" << endl;
        }
        
    }

    inputTest.close();
    return 0;
}