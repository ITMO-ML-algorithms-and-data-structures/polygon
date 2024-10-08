#include <iostream>
#include <string>
#include <array>
#include <map>

int main()
{
    std::string str1, str2;
    std::map<char, char> map;

    std::cout << "str1: ";
    std::cin >> str1;
    std::cout << "str2: ";
    std::cin >> str2;

    if (std::size(str1) != std::size(str2)) { return 2; }
    
    for (int i = 0; i < std::size(str1); i++)
    {
        char a = str1[i]; char b = str2[i];

        if ((map.count(b) == 0 and map.count(a) == 1) or 
            (map.count(b) == 1 and map.count(a) == 0)) { return 0; }

        else if (map.count(b) == 0 and map.count(a) == 0) 
        { map[b] = a; map[a] = b; }

        else if (map[b] != a or map[a] != b) { return 0; }

        if (map[a] != b and map[b] != a) { return 0; }
    }
    return 1;
}
