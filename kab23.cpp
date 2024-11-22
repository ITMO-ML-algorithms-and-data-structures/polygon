#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // исходный массив
    std::vector<int> arr = {1, 2, 2, 3, 4, 4, 5};

    // сортируем массив (нужно для корректной работы метода unique)
    std::sort(arr.begin(), arr.end());

    // удаляем дубликаты
    auto last = std::unique(arr.begin(), arr.end());
    
    // удаляем лишние элементы
    arr.erase(last, arr.end());
    
    // выводим результат
    std::cout << "Массив без дубликатов: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
