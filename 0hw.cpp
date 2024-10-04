#include <iostream>
#include <vector>

int main() {
    size_t inp_len, best_start = 0, best_end = 1, curr_start = 0;

    std::cin >> inp_len;
    std::vector<int> input;
    input.reserve(inp_len);

    for (size_t i = 0; i < inp_len; ++i) {
        std::cin >> input[i];

        if (i != 0 and input[i] <= input[i - 1]) {
            if (best_end - best_start < i - curr_start)
                best_start = curr_start, best_end = i;
            curr_start = i;
        }
    }

    if (best_end - best_start < inp_len - curr_start)
        best_start = curr_start, best_end = inp_len;

    for (size_t i = best_start; i < best_end; ++i)
        std::cout << input[i] << ' ';

    return 0;
}
