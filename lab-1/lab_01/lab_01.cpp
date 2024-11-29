#include <iostream> 
#include <string> // ���������� ��� ������ �� ��������
#include <vector> // ���������� ��� ������������ ��������
#include <unordered_map> // ���������� ��� �������� ��� ����-��������"; �������� 100 ���� 

using namespace std;

vector<int> values(const vector<string> arr, int size) { // ���������� ������� � ����������� ������������� ������� � ��� �������

    unordered_map<string, int> st_values;
    for (int i = 0; i < size; i++) {
        st_values[arr[i]]++; //������ ���-������� � ���������� � �������
    }

    vector<int> fin_arr(size); // ������ ������, ������� ����� ����������

    for (int i = 0; i < size; i++) {
        fin_arr[i] = st_values[arr[i]]; // ��� �������� � �������� ������� ������������ ���������� ��� ���������
    }

    return fin_arr; 
}

void test1()
{
    vector<string> arr = { "Orange", "Red", "Green", "Orange" }; // 17 ����
    int size = 4;
    vector<int> arrive = values(arr, size);

    if (arrive == vector<int>{2, 1, 1, 2}) {
        cout << "Test1 passed";
    }
    else
    {
        cout << "Test1 failed";
        for (int i = 0; i < size; i++){
            cout << arrive[i] << " ";
        }
    }
}

int main()
{
    test1(); // 16 ���� 
    return 0;
}
// �������� 130 ���� 