#include<iostream>
#include<string>
#include<map>
#include<clocale>

bool check_str(std::string &s) {
    // �������� ��� � ������ ������ ���������� �������
    // ������ s ����� 1 ����
    for (int i=0; i < s.size() ; i++) {
        // + 4 ����� �� �� �����
        // ������� main ���������� 4 + k1 + 1 + k2 + 1 = k1 + k2 + 6 ����
        // ����� k1 + k2 + 6 + 1 + 4 = k1 + k2 + 11 ����
        if (!(('a' <= s[i]) & (s[i] <= 'z')) & !(('0' <= s[i]) & (s[i] <= '9')) & !(('A' <= s[i]) & (s[i] <= 'Z'))) {
            return false;
        }
    }
    return true;
}

bool are_isomorphic(std::string &s1, std::string &s2) {
    // ��������� �� ������������ ������
    // ������ s1 � s2 ����� �� 1 �����
    if (s1.size() != s2.size()) {
        // ���� ������ ������� �������, �� ��� �� ���������
        return false;
    }
    // ������� ������� � ������� �������� ������������ ����� ���������
    std::map<char, char> accordance; // �������� ��� map �� ������� (sizeof(char) + sizeof(char) + sizeof(_Rb_tree_node_base)) * M + sizeof(_Rb_tree)
    // ���������� (1 + 1 + 24) * M + 64 �����, ��� M - ���-�� ���������� �������� � ������, ������� �� ����������� 62
    for (int i=0; i < s1.size() ; i++) {
        // + 4 ����� �� �� �����
        if (accordance.find(s1[i]) != accordance.end()) {
            // �������� ��� ������� s1[i] ������������� 1 �������
            // ����� are_isomorphic ���������� 2 + (1 + 1 + 24) * M + 64 + 4 + 2= 26*M + 72 ����
            // � main ���������� 4 + 4 + k1 + 1 + k2 + 1 = k1 + k2 + 10 ����
            // ����� 26*M + k1 + k2 + 82 �����
            if (accordance[s1[i]] != s2[i]) {
                return false;
            }
        } else {
            // ��������� ������������ ���� ��� ������ �� �����������
            accordance[s1[i]] = s2[i];
        }
    }
    return true;
}

int main() {
    setlocale(LC_CTYPE, "rus");
    int n=-1; // 4 �����
    std::string input_str1, input_str2; // ������ ������ ����� �� 1 �����
    do {
        // + 4 ����� �� �� �����
        std::cout << "������� ���������� ��� �����\n";
        // ��������� ���-�� ��� ���� ��� �� ������ �������������
        std::cin >> n;
    } while (n < 1);
    for (int i=0; i < n ; i++) {
        // + 4 ����� �� �� �����
        do {
            // + 4 ����� �� �� �����
            std::cout << "������� 1-�� ������\n";
            // ��������� 1-�� ������ ���� ��� �� ����� ����������
            std::cin >> input_str1; // ������ ������ ����� k1 + 1 ����, ��� k1 - ����� ������
        } while (!check_str(input_str1));
        do {
            // + 4 ����� �� �� �����
            std::cout << "������� 2-�� ������\n";
            // ��������� 2-�� ������ ���� ��� �� ����� ����������
            std::cin >> input_str2; // ������ ������ ����� k2 + 1 ����, ��� k2 - ����� ������
        } while (!check_str(input_str2));

        if (are_isomorphic(input_str1, input_str2)) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }
    }
    // �� ���� 6 + k1 + k2 ����, ��� k1 � k2 ����� ����� �� i-�� ��������
    // ������������ ����� ���� ����������� � ������ 37 � ����� 26*M + k1 + k2 + 82 �����, ��� M - ���-�� ���������� �������� � ������� �� i-�� ��������
    return 0;
}
