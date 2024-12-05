#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) { // копирование O(s.size() + t.size())
        // функция возвращает количество подпоследовательностей t в s

        // s и t занимают по s.size() + 1 и t.size() + 1 байт
        //на j - ой позиции dp_old хранит кол-во способов выбрать подпоследовательность t[0:step) в s[0:j)
        vector<long long> dp_old(s.size() + 1, 1); // O(s.size()), 24 + 8 * (s.size() + 1) байт
        //на j - ую позицию dp_new добавляется кол-во способов выбрать подпоследовательность t[0:step + 1) в s[0:j)
        //изначально dp_old заполнен 1 чтобы на нулевом шаге когда s[j] == t[0] добавлась 1
        vector<long long> dp_new(0); // O(1), 24 байта
        for (int step=0; step < t.size() ; step++) {
            // внутри цикла +4 байта
            // цикл работает за O(t.size() * s.size())
            char new_let = t[step]; // +1 байт
            dp_new.push_back(0);
            for (int i=0; i < s.size() ; i++) {
                // внутри цикла +4 байта
                // dp_new будет весить максимум 24 + 8 * (s.size() + 1) байт
                if (s[i] == new_let) {
                    // в этом случаи t[0:step + 1) можно выбрать используя только s[0:i) или выбрать t[0:step) из s[0:i) и s[i]
                    dp_new.push_back(dp_new[i] + dp_old[i]);
                } else {
                    // в этом случаи t[0:step + 1) можно выбрать используя только s[0:i)
                    dp_new.push_back(dp_new[i]);
                }
                // на последней итерации этого цикла будет использовано больше всего памяти
                // s.size() + 1 +t.sise() + 1 + 24 + 8 * (s.size() + 1) + 24 + 8 * (s.size() + 1) + 4 + 1 + 4 = 17 * s.size() + t.size() + 75 байт
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
