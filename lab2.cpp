#include<iostream>
#include<string>
#include<cassert>

std::string compression(std::string &s) {
    //функция сжатия
    // ссылка на s весит 1 байт
    std::string ans = "";
    if (s.size() == 0) {
        return ans;
    }
    int cnt_last = 1; // +4 байта
    ans += s[0];
    for (int i=1; i < s.size() ; i++) {
        // +4 байта из-за цикла
        // во время выолнения цикла в строке ans максимум 2*m-1 символ, где m - кол-во частей подряд идущих символов
        // тогда максимальный вес строки достигается на последней итерации и равен 2*m
        // на последний итерации программа использует больше всего памяти 2*n + 1 + 4 + 4 + 2*m байт
        if (s[i] == ans[ans.size() - 1]) {
            cnt_last += 1;
        } else {
            ans += std::to_string(cnt_last);
            cnt_last = 1;
            ans += s[i];
        }
    }
    // в конце выполнения функции ans весит 2*m байт
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
    std::string input; // строка весит n+1 байт, где n - кол-во символов
    std::cin >> input;
    std::cout << compression(input);
    return 0;
}
