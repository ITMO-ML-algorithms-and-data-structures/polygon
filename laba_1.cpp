#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int max = 0;
    for (int i : arr) {
        if (i>max) {
            max = i;
        }
    }
    std::cout << max;
}
