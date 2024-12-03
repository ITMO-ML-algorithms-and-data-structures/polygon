#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <windows.h>
#include "lab_5_sort_1.cpp"
#include "lab_5_sort_2.cpp"
#include "lab_5_sort_3.cpp"

using namespace std;

string buffer;

void generate_middle_test(int& massive_size, int& number){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(numeric_limits<int>::min(), numeric_limits<int>::max());
    ofstream test;
    string file_way = buffer + "/tests/test_" + to_string(number) + ".txt";
    test.open(file_way);
    test << massive_size << endl;
    for (int i = 0; i < massive_size; i++) {
        test << dist(gen) << endl;
    }
    test.close();
}

void generate_best_test(int& massive_size, int& number){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(numeric_limits<int>::min(), numeric_limits<int>::max());
    ofstream test;
    string file_way = buffer + "/tests/test_" + to_string(number) + ".txt";
    test.open(file_way);
    test << massive_size << endl;
    vector<int> vec(massive_size);
    for (int i = 0; i < massive_size; i++) {
        vec[i] = dist(gen);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < massive_size; i++) {
        test << vec[i] << endl;
    }
    test.close();
}

void generate_worst_test(int& massive_size, int& number){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(numeric_limits<int>::min(), numeric_limits<int>::max());
    ofstream test;
    string file_way = buffer + "/tests/test_" + to_string(number) + ".txt";
    test.open(file_way);
    test << massive_size << endl;
    vector<int> vec(massive_size);
    for (int i = 0; i < massive_size; i++) {
        vec[i] = dist(gen);
    }
    sort(vec.rbegin(), vec.rend());
    for (int i = 0; i < massive_size; i++) {
        test << vec[i] << endl;
    }
    test.close();
}

void run_test(int& number) {
    string file_way = buffer + "/tests/test_" + to_string(number) + ".txt";
    ifstream test;
    test.open(file_way);
    int vec_size;
    test >> vec_size;
    vector<int> vec(vec_size);
    for (int j = 0; j < vec_size; j++) {
        test >> vec[j];
    }
    test.close();
    auto start = chrono::high_resolution_clock::now();
    timsort(vec);
    auto finish = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(finish - start);
    long double final_time = duration.count() / 1e6;
    vector<int> check_vec(vec.size());
    check_vec = vec;
    sort(vec.begin(), vec.end());
    if (check_vec != vec) {
        cout << "Wrong answer" << endl;
        return;
    }
    cout << final_time  << endl;
}

void testing_with_step() {
    for (int massive_size = 1e3, number = 1; massive_size < 1e5; massive_size += 1e3, number++) {
        generate_middle_test(massive_size, number);
        run_test(number);
    }
}

void testing() {
    cout << "Quantity of tests: ";
    int quantity;
    cin >> quantity;
    cout << endl << "Massive size: ";
    int massive_size;
    cin >> massive_size;
    cout << endl;
    for (int number = 1; number <= quantity; number++) {
        generate_middle_test(massive_size, number);
        run_test(number);
    }
}

int main() {
    char temp_buffer[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, temp_buffer);
    buffer = string(temp_buffer);
    testing();
}

