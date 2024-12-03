#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void odd_even_sort(vector<int>& input_vec) {
    bool sort_flag = false;
    while (!sort_flag) { //O(N)
        sort_flag = true;
        for (int i = 0; i < input_vec.size() - 1; i += 2) { //O(N / 2)
            if (input_vec[i] > input_vec[i + 1]) {
                swap(input_vec[i], input_vec[i + 1]);
                sort_flag = false;
            }
        }
        for (int i = 1; i < input_vec.size() - 1; i += 2) { //O(N / 2)
            if (input_vec[i] > input_vec[i + 1]) {
                swap(input_vec[i], input_vec[i + 1]);
                sort_flag = false;
            }
        }
    }
}
//�����: O(N^2) � ������ � �������, O(N) � ������ (���� ������ ��� ������������)



