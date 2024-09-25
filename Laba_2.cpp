#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
    // первый массив
    std::vector<std::string> arr_perv = {"Orange", "Red", "Green", "Orange"}; // N * (24 байта + 1 на конечный + 85(макс))
    // второй массив
    std::vector<int> arr_vtor;  // N * 4 байта на int
    // словарь
    std::unordered_map<std::string, int> slow;
    // 255(макс) * (24 + 1 байт на конечный + 85(макс) (ключ) + 4 (значение) + 8 (указатель на значение))


 // Проходимся по массиву
    for (std::string item : arr_perv) {
        // Проверяем, есть ли элемент в словаре
        if (slow.find(item) == slow.end()) {
            slow[item] = static_cast<int>(slow.size() + 1); // то же самое (255(макс) * (24 + символы (ключ) + 1 + 85(макс) + 4 (значение) + 8 (указатель на значение)))
        }
        
        // Добавляем закодированное значение в конечный вектор
        arr_vtor.push_back(slow[item]);  // то же самое (N * 4 байта на int)
    }

    // Выводим результат
    for (int res : arr_vtor) {
        std::cout << res << " ";
    }
    // N * (24 + 1 + 85) + N * 4 + 255(макс) * (24 + 1 + 85 + 4 + 8) = N * 110 + N * 4 + 255 * (122) = N * 114 + 31110 байт = 1171110 байт
    return 0;
}