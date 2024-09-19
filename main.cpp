#include <iostream>
#include "middle+lab1.cpp"
// int a[] = {1, 2, 1, -1, -3, 0}, int len = 6: ожидаемый вывод → 1 / вывод программы → 1
// int a[] = {-1, -36, -5, -18, -7, -9, -15}, int len = 7: ожидаемый вывод → -5 / вывод программы → -5
// int a[] = {32, 54, 68, 11, 46, 90}, int len = 6: ожидаемый вывод → 68 / вывод программы → 68
// int a[] = {1, 1, 1, 1}, len = 4: ожидаемый исход → "элемент не найден" / вывод программы → second max digit is not found
// int a[] = {1, 1, 2, 1, 1}, len = 5: ожидаемый вывод → 1 / вывод программы → 1
// int a[] = nullptr, len = 0: ожидаемый исход → "элемент не найден" / вывод программы → second max digit is not found

void test(int arr[], int len, int expected_result, int test_number) 
{
    int res = Second_MAX(arr, len);
    cout << "Test " << test_number << " is completed: ";
    if (res == expected_result) {
        if (res == INT_MIN) 
        {
            cout << "no element is found" << endl;
        }
        else {
        cout << "Correct element " << res << " is found" << endl;
        }
    }
    else {
        cout << "Incorrect element found" << endl;

    }
}
int main() 
{
    int arr_test1[] = {1, 2, 1, -1, -3, 0};   
    int arr_test2[] = {-1, -36, -5, -18, -7, -9, -15};
    int arr_test3[] = {32, 54, 68, 11, 46, 90};
    int arr_test4[] = {1, 1, 1, 1};
    int arr_test5[] = {1, 1, 2, 1, 1};
    test(arr_test1, 6, 1, 1);
    test(arr_test2, 7, -5, 2);
    test(arr_test3, 6, 68, 3);
    test(arr_test4, 4, INT_MIN, 4);
    test(arr_test5, 5, 1, 5);
    test(nullptr, 0, INT_MIN, 6);
}




