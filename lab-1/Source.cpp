#include <iostream>
#include <vector>
using namespace std;

int count_elements(const vector<int>& arr, int number) {
    

    int count = 0;
    for (int i : arr) {
        if (i == number) {
            count++;
        }
       
    }
    if (count == 0) {
        cout << "Нет такого числа в массиве" << endl;
    }
    return count;
}

void test01() {
    
    vector<int> arr = { 1, 5, 3, 5, 2, 5 };
    int num = 5;
    int arrive = count_elements(arr, num);
    if (arrive == 3) {
        cout << "Test1 passed" << endl;
    }
    else {
        cout << "Test1 failed" << endl;
    }
    
}

void test02() {

    vector<int> arr = { 1, 5, 3, 5, 2, 5 };
    int num = 6;
    int arrive = count_elements(arr, num);
    if (arrive == 0) {
        cout << "Test1 passed" << endl;
    }
    else {
        cout << "Test1 failed" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    test01();
    test02();
    return 0;
}