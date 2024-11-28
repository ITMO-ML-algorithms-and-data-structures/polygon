#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main() {
    //Есть массив, нужно подсчитать кол-во уникальных значений и заменить каждое значение кол-вом
    int size; 
    std::cout << "size = ";
    std::cin >> size;

    std::vector<std::string> arr(size);  // для каждой строки 24 байта + 100 и  для массива 124 × 1e4 = 1.24МБ
    std::cout << "arr = ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    // Хранение кол-ва уникальных значений
    std::unordered_map<std::string, int> countMap; //для одной записи (124+4)*2=256 байт, итого для хэш-таблицы 256*1e4=2.56 Mб

    // Подсчет кол-ва уникальных значений
    for (const std::string& value : arr) {
        countMap[value]++;
    }

    // Замена значений в массиве на количество их повторений
    std::vector<int> res(size); // 4*1е4 = 0.04 Mб
    for (int i = 0; i < size; ++i) {
        res[i] = countMap[arr[i]];
    }

    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) {
            std::cout << ", ";
        }
    }

    return 0;
}

// Итого 1.24 + 2.56 + 0.04 ≈ 3.84 Mб