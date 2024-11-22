#include<iostream>
#include<string>
#include<cassert>

std::string compression(const std::string &s) {
    std::string ans = "";
    if (s.size() == 0) {
        //сравнение s.size() == 0 за O(1)
        return ans;
    }
    int cnt_last = 1;
    ans += s[0]; // O(1)
    for (int i=1; i < s.size() ; i++) {
        //цикл проходит s.size() - 1 итерацию
        //сравнение s[i] == ans[ans.size() - 1] за O(1)
        if (s[i] == ans[ans.size() - 1]) {
            cnt_last += 1; // O(1)
        } else {
            // сравнение cnt_last > 1 за O(1)
            if (cnt_last > 1) {
                ans += std::to_string(cnt_last); // O(l), где l-кол-во разрядов в числе
                //суммарное кол-во разрядов во всех числах которые будут преобразованы функцией to_string <= s.size()/2
                //Тогда в худшем случаи все to_string суммарно работают за O(s.size())
                cnt_last = 1; // O(1)
            }
            ans += s[i]; // O(1)
        }
    }
    if (cnt_last > 1) {
        // сравнение cnt_last > 1 за O(1)
        ans += std::to_string(cnt_last); //O(1)
    }
    //Итоговая сложность O(s.size())
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
