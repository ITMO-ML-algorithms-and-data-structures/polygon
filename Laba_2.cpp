#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main() {
    // первый массив
    std::vector<std::string> arr_perv = {"Orange", "Red", "Green", "Orange"};
    // второй массив
    std::vector<int> arr_vtor;
    // словарь
    std::unordered_map<std::string, int> slow;

 // Проходимся по массиву
    for (std::string item : arr_perv) {
        // Проверяем, есть ли элемент в словаре
        if (slow.find(item) == slow.end()) {
            slow[item] = static_cast<int>(slow.size() + 1);
        }
        
        // Добавляем закодированное значение в конечныц вектор
        arr_vtor.push_back(slow[item]);
    }

    // Выводим результат
    for (int res : arr_vtor) {
        std::cout << res << " ";
    }
 
    return 0;
}