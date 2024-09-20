#include <iostream>

int main() {
    int max_plus{}, max_minus{}, result{}, a{}, b{};
    int sp_size = 3;
    int sp[] = {0, 0, 0};
    for (int i = 0; i < sp_size; i++) {
        if (sp[i] > 0) {
            if (sp[i] * max_plus > result) {
                result = sp[i] * max_plus;
                a = sp[i];
                b = max_plus;
            }
            if (sp[i] > max_plus) max_plus = sp[i];
        }
        if (sp[i] < 0) {
            if (sp[i] * max_minus > result) { 
                result = sp[i] * max_minus; 
                a = sp[i];
                b = max_minus;
            }
            if (sp[i] < max_minus) max_minus = sp[i];
        }
    }
    std::cout << result << "\n";
    std::cout << a << ' ' << b;
}