#include<iostream>
#include<string>
#include<cassert>

std::string compression(const std::string &s) {
    std::string ans = "";
    if (s.size() == 0) {
        //��������� s.size() == 0 �� O(1)
        return ans;
    }
    int cnt_last = 1;
    ans += s[0]; // O(1)
    for (int i=1; i < s.size() ; i++) {
        //���� �������� s.size() - 1 ��������
        //��������� s[i] == ans[ans.size() - 1] �� O(1)
        if (s[i] == ans[ans.size() - 1]) {
            cnt_last += 1; // O(1)
        } else {
            // ��������� cnt_last > 1 �� O(1)
            if (cnt_last > 1) {
                ans += std::to_string(cnt_last); // O(l), ��� l-���-�� �������� � �����
                //��������� ���-�� �������� �� ���� ������ ������� ����� ������������� �������� to_string <= s.size()/2
                //����� � ������ ������ ��� to_string �������� �������� �� O(s.size())
                cnt_last = 1; // O(1)
            }
            ans += s[i]; // O(1)
        }
    }
    if (cnt_last > 1) {
        // ��������� cnt_last > 1 �� O(1)
        ans += std::to_string(cnt_last); //O(1)
    }
    //�������� ��������� O(s.size())
    return ans;
}

void test() {
    std::string s1="aaabb";
    assert((compression(s1) == "a3b2"));
    s1="abac";
    assert((compression(s1) == "abac"));
    s1="DdD";
    assert((compression(s1) == "DdD"));
    s1="";
    assert((compression(s1) == ""));
}

int main()
{
    test();
    int number_of_lines;
    std::cin >> number_of_lines;
    std::string input;
    while (number_of_lines > 0) {
        std::cin >> input;
        std::cout << compression(input);
        number_of_lines -= 1;
    }
    return 0;
}
