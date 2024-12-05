#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) { // ����������� O(s.size() + t.size())
        // ������� ���������� ���������� ���������������������� t � s

        // s � t �������� �� s.size() + 1 � t.size() + 1 ����
        //�� j - �� ������� dp_old ������ ���-�� �������� ������� ��������������������� t[0:step) � s[0:j)
        vector<long long> dp_old(s.size() + 1, 1); // O(s.size()), 24 + 8 * (s.size() + 1) ����
        //�� j - �� ������� dp_new ����������� ���-�� �������� ������� ��������������������� t[0:step + 1) � s[0:j)
        //���������� dp_old �������� 1 ����� �� ������� ���� ����� s[j] == t[0] ��������� 1
        vector<long long> dp_new(0); // O(1), 24 �����
        for (int step=0; step < t.size() ; step++) {
            // ������ ����� +4 �����
            // ���� �������� �� O(t.size() * s.size())
            char new_let = t[step]; // +1 ����
            dp_new.push_back(0);
            for (int i=0; i < s.size() ; i++) {
                // ������ ����� +4 �����
                // dp_new ����� ������ �������� 24 + 8 * (s.size() + 1) ����
                if (s[i] == new_let) {
                    // � ���� ������ t[0:step + 1) ����� ������� ��������� ������ s[0:i) ��� ������� t[0:step) �� s[0:i) � s[i]
                    dp_new.push_back(dp_new[i] + dp_old[i]);
                } else {
                    // � ���� ������ t[0:step + 1) ����� ������� ��������� ������ s[0:i)
                    dp_new.push_back(dp_new[i]);
                }
                // �� ��������� �������� ����� ����� ����� ������������ ������ ����� ������
                // s.size() + 1 +t.sise() + 1 + 24 + 8 * (s.size() + 1) + 24 + 8 * (s.size() + 1) + 4 + 1 + 4 = 17 * s.size() + t.size() + 75 ����
            }
            dp_old = dp_new; // O(s.size())
            dp_new.clear(); // O(s.size())
        }
        return dp_old[s.size()];
    }
};

int main() {
    Solution sol1;
    string s1, s2;
    cin >> s1 >> s2;
    cout << sol1.numDistinct(s1, s2);
    return 0;
}
