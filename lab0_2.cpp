#include <iostream>
#include <vector>


bool is_simple(const int& n) {
    if (n == 2) {
        return true;
    }
    else if (n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i <= (int)sqrt(n) + 1; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;

}


int main()  
{
    std::vector<int> vec{3, 5, 7, 9, 13, 92};
    std::vector<int> prefix_sums{ 0 };
    {
        int sum = 0;
        for (const int& iter : vec) {
            sum += iter;
            prefix_sums.push_back(sum);
        }
    }
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = i; j < vec.size(); j++) {
            if (is_simple(prefix_sums[j + 1] - prefix_sums[i])) {
                std::cout << i << " " << j << " " << prefix_sums[j + 1] - prefix_sums[i] << "\n";
            }
        }
    }
    return 0;
}
