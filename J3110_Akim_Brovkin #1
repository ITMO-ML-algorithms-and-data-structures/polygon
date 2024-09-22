#include <iostream>

int main()
{
    std::string input;
    std::cin >> input;
    bool flag = false;
    for (int i = 0; i < input.size() / 2 + 1; ++i)
    {
        if (input[i] == input[input.size() - i - 1])
            flag = true;
        else
            break;
    }
    if (flag)
        std::cout<<"YES";
    else
        std::cout<<"NO";
    

    return 0;
}
