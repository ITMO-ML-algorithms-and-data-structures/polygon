#include <iostream>
#include <string>



int main()
{
    std::string brackets_seq;
    std::cin >> brackets_seq;
    int ans = 0, balance = 0;
    for (const char& str : brackets_seq) {
        if (str == '(') {
            balance++;
        }
        else if (balance > 0) {
            ans++;
            balance--;
        }
    }
    std::cout << ans << "\n";
    return 0;
}