#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool prime(int num){ //������� �� �������� �������� �����
    for (int div = 2; div < round(sqrt(num)) + 1; div++)
        if (num % div == 0){
            return 0;
    }
    return 1;
}

int main() {
    int n, mi;
    cin >> n; //�� �� ���� ������� ������� ������, ��������, ��� n - ������ �������
    int m[n];
    for (int i = 0; i < n; i++){
        cin >> mi; //���� ������ �������
        m[i] = mi;
    }
    vector<pair<int, int>> ans; //ans - ������ ���, ��� ������ ������� �������� ������� �����, � ������ ���-�� ��� ����������
    for (int j = 0; j < n; j++){ //���� ������� �����
        if (prime(m[j])){
            bool flag_repeat = 0;
            for (int k = 0; k < ans.size(); k++){ //������� ���� �� ��������� ������� ����� � ans
                if (ans[k].first == m[j]){
                    flag_repeat = 1;
                    ans[k].second++;
                    break;
                }
            }
            if (!flag_repeat){ //���� �� ����, �� ���������
                ans.push_back(make_pair(m[j], 1));
            }
        }
    }
    for (int i = 0;i < ans.size(); i++){
        if (ans[i].second % 2 == 0){ //������� ��� ������� �����, ������� ����������� ������ ���-�� ���
           cout << ans[i].first << " ";
        }
    }
    return 0;
}
