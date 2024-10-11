#include <iostream>
#include <vector>
#include <set>

int main() {
    int size;
    std::cout << "размер массива: ";
    std::cin >> size;
    std::vector<int> arr(size);
    std::cout << "элементы массива:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::set<int> unique_elements;
    std::vector<int> result;

    for (const int& value : arr) {
        if (unique_elements.insert(value).second) {
            result.push_back(value);
        }
    }

    std::cout << "массив без дубликатов: ";
    for (const int& value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
