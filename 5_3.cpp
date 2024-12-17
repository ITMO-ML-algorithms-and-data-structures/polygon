#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cassert>

int get_radix(int a) {
    int ans = 1; // 4 байта
    a /= 10;
    while (a) { // O(n)
        ans += 1;
        a /= 10;
    }
    return ans;
}

void RadixSort(std::vector<int>& arr) {
    std::vector<std::vector<int>> radixes = std::vector<std::vector<int>>(10, std::vector<int>(0)); 
    int max_ln = 0, k = 1; // 8 байт
    for (int i = 0; i < arr.size(); i++) { // O(n)
        max_ln = std::max(max_ln, get_radix(arr[i]));
    }
    for (int r = 0; r < max_ln; r++) { // O(n)
        for (int i = 0; i < arr.size(); i++) { // O(n)
            radixes[(arr[i] / k) % 10].push_back(arr[i]);
        }
        arr.clear();
        for (int digit = 0; digit < 10; digit++) { // O(n)
            for (int i = 0; i < radixes[digit].size(); i++) { // O(n)
                arr.push_back(radixes[digit][i]);
            }
        }
        radixes = std::vector<std::vector<int>>(10, std::vector<int>(0));
        k *= 10;
    }
}

void time_for_test() {
    std::fstream findata("time_tests\\time_tests0.txt");
    std::ofstream out("time_proc.txt");
    for (int test = 0; test < 400; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i = 0; i < len_data; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        unsigned long long t_start = clock();
        RadixSort(data);
        unsigned long long t_end = clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << std::setprecision(20) << execution_time << '\n';
    }
    findata.close();

    findata.open("time_tests\\time_tests1.txt");
    for (int test = 0; test < 300; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i = 0; i < len_data; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        unsigned long long t_start = clock();
        RadixSort(data);
        unsigned long long t_end = clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << std::setprecision(20) << execution_time << '\n';
    }
    findata.close();

    findata.open("time_tests\\time_tests2.txt");
    for (int test = 0; test < 150; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i = 0; i < len_data; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        unsigned long long t_start = clock();
        RadixSort(data);
        unsigned long long t_end = clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << std::setprecision(20) << execution_time << '\n';
    }
    findata.close();

    findata.open("time_tests\\time_tests3.txt");
    for (int test = 0; test < 150; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i = 0; i < len_data; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        unsigned long long t_start = clock();
        RadixSort(data);
        unsigned long long t_end = clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << std::setprecision(20) << execution_time << '\n';
    }
    findata.close();
    out.close();
}


void test()
{
    std::vector<int> vector1, vector_1, vector2, vector_2, vector3, vector_3;
    vector1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector_1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector_2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector3 = { 2, 3, 6, 1, 4, 7, 8, 9, 10, 5 };
    vector_3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    RadixSort(vector1);
    RadixSort(vector2);
    RadixSort(vector3);
    for (int i = 0; i < 10; i++)
    {
        assert(vector1[i] == vector_1[i]);
        assert(vector2[i] == vector_2[i]);
        assert(vector3[i] == vector_3[i]);
    }
}

int main() {
    test();
    //time_tests();
    std::vector<int> data(0); //24 + 4 * n байт
    int len_data, input_val; // 8 байт
    std::cin >> len_data;
    for (int i = 0; i < len_data; i++) { // O(n)
        std::cin >> input_val;
        data.push_back(input_val);
    }
    RadixSort(data);
    for (int i = 0; i < len_data; i++) { // O(n)
        std::cout << data[i] << ' ';
    }
    return 0;
}