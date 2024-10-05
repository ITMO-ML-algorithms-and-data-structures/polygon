#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<int> numbers = {1, 2, 2, 3, 4, 4, 5, 6, 6};

    // Удаление дубликатов
    std::set<int> uniq (numbers.begin(), numbers.end());
    std::vector<int> uniqNum (uniq.begin(), uniq.end());
    
    // Вывод результата
    for (int num : uniqNum) {
        std::cout << num << " ";
    }

    return 0;
}
