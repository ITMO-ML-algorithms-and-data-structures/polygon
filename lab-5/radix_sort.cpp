#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;
//сложность выполняемого алгоритма - О(n*log n)
void read_csv(const std::string& filename, std::vector<int>& intArray) { // Функция чтения чисел из csv в массив
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ',')) { // Split by comma
            try {
                int number = std::stoi(value); // Convert to int
                intArray.push_back(number); // Add to the vector
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number: " << value << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Number out of range: " << value << std::endl;
            }
        }
    }

    file.close();
}

void CountSort(int a[], int n, int curr_digit)
{  
int i = {0};
int result[n] = {0};
int count[10] = {0};

//подсчитываем количество повторений 
for (i =0; i <n; i++){
    count[(a[i] / curr_digit) % 10]++;
    }
//создаем позиционную "карту" для введеных чисел на основе рассматриваемого curr_digit
for (i = 1; i<10; i++){
    count[i] += count[i-1];
    }   

//результат
for (i =n-1; i>= 0; i--){
    result[count[(a[i] / curr_digit) % 10] - 1] = a[i]; //заносим значения во временный массив по индексации полученной из count
    count[(a[i] / curr_digit) % 10]--;
    }

for (i =0; i <n; i++){
    a[i] = result[i]; //изменяем изначальный массив. конец цикла сортировки счетами
    }
}

void radixsort(int a[], int n)
{
    int curr_digit;

    for (curr_digit = 1; n/curr_digit > 0; curr_digit *= 10){
        CountSort(a, n, curr_digit);}
}


int main() {
//    std::vector<std::string> data_samples = {"1000", "2000", "3000", "4000", "5000", "6000", "7000", "8000", "9000", 
//                                           "10000", "20000", "30000", "40000", "50000", "60000", "70000", "80000", "90000", "100000",
 //                                          "100000", "200000", "300000", "400000", "500000", "600000", "700000", "800000", "900000", "1000000"};
   std::vector<std::string> data_samples = {"400000"};
    std::vector<float> corr_median_time;
    std::cout << data_samples.size() << std::endl;
    float sum_time = 0;
    for(int i=0; i < data_samples.size(); i++){
        for (int j = 1; j <= 10; j ++) {
        std::vector<int> temp_arr;        
        std::string tmp_file = data_samples[i] + "_" + std::to_string(j) + ".csv";

        read_csv(tmp_file, temp_arr);

        int n = temp_arr.size();
        int arr[n] = {0};
        for (int i; i < n; i++){
            arr[i] = temp_arr[i];
        }
        std::cout << n << std::endl;
        for (int i; i < (n/1000); i++){
            std::cout << arr[i] << " ";
        }

        auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

        radixsort(arr, n);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;
        std::cout << duration.count() << std::endl; // Выводим время работы
        sum_time += duration.count();
    }
    corr_median_time.push_back(sum_time/10);
    }
    for (auto now : corr_median_time) {
        cout << now << " ";
    }
  return 0;
    }
    