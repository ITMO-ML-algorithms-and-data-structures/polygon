#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class CountVectorizer {
public:
    // ������� ���� (���-�������) � ������ ����-��������: �) �����-������ �) ������-�����

    unordered_map<string, int> word_index_map;
    unordered_map<int, string> index_word_map;

    /*
    ����� �������, ������� �� ���� ������ �� �����, ����������� ������ �� ��������
    � ����������� � ���-������� ���������� ��������
    */

    void breakAndAddUnique(const vector<string>& arr) {
        int index = 0;

        for (const auto& str : arr) {
           istringstream stream(str);
           string word;

            while (stream >> word) {
                if (word_index_map.find(word) == word_index_map.end()) {
                    word_index_map[word] = index;
                    index_word_map[index] = word;
                    index++;
                }
            }
        }
    }

    /*
    ����� �������, ������� �� ���� ������ �� ����� � ������������� ��� � ������� ����� n X m, 
    ��� n -- ���-�� ����� � �������, � m -- ���-�� ���������� ����
    */
     vector<vector<int>> createMatrix(const vector<string>& arr) {
     vector<vector<int>> matrix(arr.size(), vector<int>(word_index_map.size(), 0));

        for (int row_index = 0; row_index < arr.size(); ++row_index) {
            istringstream stream(arr[row_index]);
            string word;

            while (stream >> word) {
                if (word_index_map.find(word) != word_index_map.end()) {
                    int word_column_index = word_index_map[word];
                    matrix[row_index][word_column_index]++;
                }
            }
        }

        return matrix;
    }
    // ����� �������, ��������� ����������� �������
    void printMatrix(const vector<vector<int>>& matrix) {
        for (const auto& row : matrix) {
            cout << "[";
            for (int number_of_appearings : row) {
                    cout << number_of_appearings << " ";
            }
            cout << '\b';
            cout << "]" << endl;
        }
    }
};

int main() {
    CountVectorizer cv;
    vector<string> arr = {
        "Hello world !",
        "Hello",
        "world",
        "!"
    };

    cv.breakAndAddUnique(arr);
    auto matrix = cv.createMatrix(arr);
    cv.printMatrix(matrix);

    return 0;
}
