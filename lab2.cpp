#include<iostream>
#include<string>
#include<cassert>

std::string compression(std::string &s) {
    //������� ������
    // ������ �� s ����� 1 ����
    std::string ans = "";
    if (s.size() == 0) {
        return ans;
    }
    int cnt_last = 1; // +4 �����
    ans += s[0];
    for (int i=1; i < s.size() ; i++) {
        // +4 ����� ��-�� �����
        // �� ����� ��������� ����� � ������ ans �������� 2*m-1 ������, ��� m - ���-�� ������ ������ ������ ��������
        // ����� ������������ ��� ������ ����������� �� ��������� �������� � ����� 2*m
        // �� ��������� �������� ��������� ���������� ������ ����� ������ 2*n + 1 + 4 + 4 + 2*m ����
        if (s[i] == ans[ans.size() - 1]) {
            cnt_last += 1;
        } else {
            ans += std::to_string(cnt_last);
            cnt_last = 1;
            ans += s[i];
        }
    }
    // � ����� ���������� ������� ans ����� 2*m ����
    ans += std::to_string(cnt_last);
    return ans;
}

void test() {
    std::string s1="aaabb";
    assert((compression(s1) == "a3b2"));
    s1="abac";
    assert((compression(s1) == "a1b1a1c1"));
    s1="DdD";
    assert((compression(s1) == "D1d1D1"));
}

int main()
{
    test();
    std::string input; // ������ ����� n+1 ����, ��� n - ���-�� ��������
    std::cin >> input;
    std::cout << compression(input);
    return 0;
}
