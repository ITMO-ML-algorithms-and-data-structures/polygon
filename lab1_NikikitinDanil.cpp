#include <iostream>
#include <vector>


int main()
{
    std::vector <int> arr = { 1,2,3,4,56,78,12,14,2,4,5,7,8,9,70,12,22,42,41 };
    int len, max_len;
    len = 0;

    max_len = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            len = len + 1;
            max_len = std::max(max_len, len);
        }
        else {
            len = 0;
        }
    }
    std::cout << max_len;

}
