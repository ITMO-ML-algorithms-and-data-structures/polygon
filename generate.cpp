#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    // ������������� ���������� ��������� �����
    srand(static_cast<unsigned int>(time(nullptr)));

    int count;
    cout << "������� ���������� ��������� �����: ";
    cin >> count;

    ofstream outFile("random_numbers.txt"); // �������� ����� ��� ������
    if (!outFile) {
        cerr << "�� ������� ������� ���� ��� ������!" << endl;
        return 1;
    }

    // ������ ��������� ����� ����� � ����
    for (int i = 0; i < count; ++i) {
        int randomNumber = rand(); // ��������� ���������� �����
        outFile << randomNumber << endl; // ������ ����� � ����
    }

    outFile.close(); // �������� �����
    cout << "��������� ����� �������� � ���� random_numbers.txt" << endl;

    return 0;
}
