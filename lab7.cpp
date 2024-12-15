#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();
        for (int i = 0; i < n && k > 0; ++i) {
            // Найти минимальную цифру, которую можно переместить в позицию i
            int pos = i;
            for (int j = i + 1; j < n && j - i <= k; ++j) {
                if (num[j] < num[pos]) {
                    pos = j;
                }
            }

            // Переместить цифру num[pos] на позицию i
            char minDigit = num[pos];
            for (int j = pos; j > i; --j) {
                num[j] = num[j - 1]; // Смещаем цифры вправо
            }
            num[i] = minDigit; // Устанавливаем минимальную цифру на позицию i

            // Уменьшаем количество оставшихся перестановок
            k -= (pos - i);
        }

        return num;
    }
};

int main() {
    Solution solution;
    string num = "4321";
    int k = 4;
    cout << "Result: " << solution.minInteger(num, k) << endl;

    num = "100";
    k = 1;
    cout << "Result: " << solution.minInteger(num, k) << endl;

    num = "36789";
    k = 1000;
    cout << "Result: " << solution.minInteger(num, k) << endl;

    num = "10000";
    k = 2;
    cout << "Result: " << solution.minInteger(num, k) << endl;

    return 0;
}

